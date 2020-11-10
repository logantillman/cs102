/*This is a function that is supposed to be able to take in parameters to manipulate an image, however it doesn't work correctly.
 * Author: Logan Tillman
 * Date: November 14 2018 */
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Pixel struct that holds the RGB values for each pixel
struct Pixel
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
};

// Picture class that holds the information and functions to perform on the picture
class Picture
{
public:
	Picture();
	const Pixel& get_pixel(const unsigned int &row, const unsigned int &column) const;
	Pixel& get_pixel(const unsigned int &row, const unsigned int &column);
	void set_pixel(const unsigned int &row, const unsigned int &column, const Pixel &pixelstruct);
	void invert();
	void flip_x();
	void flip_y();
	bool read_input(istream &in);
	void write_output(ostream &out);
private:
	vector<Pixel> pixels;
	int width;
	int height;
	int maxIntensity;
};

int main(int argc, char **argv)
{
	string input = argv[1];
	string output = argv[2];
	string command = argv[3];
	ifstream inputStream;
	ofstream outputStream;
	Picture picture;


	// If the user doesn't input at least 2 command line arguments after the file name, the function will print an error
	if(argc < 3)
	{
		cerr << "Usage: ./lab12 <input file or '-'> <output file or '-'> <'I', 'Y', 'X', or blank>\n";
	return -1;
	}


	// If the user enters a dash, it'll read in from cin
	if (input == "-")
	{

		// Determines if the file was able to be read in successfully
		if(!(picture.read_input(inputStream)))
		{
			cerr << "Error reading file.\n";
		return -1;
		}
	}


	// If the user entered a file name, it'll read in from the file
	else if (input != "-")
	{
		inputStream.open(input);
			
			// Determines if the file failed to open
			if(!inputStream.good())
			{
				cerr << "Unable to open " << input << '\n';
				return -1;
			}

		// Determines if the file was able to be read in and added all of the pixels	
		if(!(picture.read_input(inputStream)))
		{
			cerr << "Error reading file.\n";
		return -1;
		}
	}


	// If the user enters "I", it will invert the picture
	if (command == "I")
	{
		picture.invert();
	return 1;
	}

	
	// If the user enters "Y", it will flip the picture across the y axis
	if (command == "Y")
	{
		picture.flip_y();
	return 1;
	}

	
	// If the user enters "X", it will flip the picture across the x axis
	if (command == "X")
	{
		picture.flip_x();
	return 1;
	}


	// Will output to the terminal if the user enters a dash
	if (output == "-")
		picture.write_output(cout);


	// Will output to a specified file the user enters
	else if (output != "-")
	{
		outputStream.open(output);

			
			// Checks to see if the output file opened properly
			if(!outputStream.good())
			{
				cerr << "Unable to open " << output << '\n';
				return -1;
			}

		// Writes the function to the specified file
		picture.write_output(outputStream);
	}

return 0;
}


// Default constructor for the Picture class
Picture::Picture()
{
	width = 0;
	height = 0;
	maxIntensity = 0;
}


// This function will get the pixel at the entered row and column and return it as a const reference
const Pixel& Picture::get_pixel(const unsigned int &row, const unsigned int &column) const
{
	int pixel;
	pixel = (row - 1) * (width) + (column - 1);	

return pixels.at(pixel);
}


// The mutator function for get_pixel, will find the pixel at the given row and column
Pixel& Picture::get_pixel(const unsigned int &row, const unsigned int &column)
{
	int pixel;
	pixel = row * width + column;

return pixels.at(pixel);
}


// Will set the pixel at the given row and column with the Pixel passed in
void Picture::set_pixel(const unsigned int &row, const unsigned int &column, const Pixel &pixelstruct)
{
	int pixel = row * width + column;
	
	pixels.at(pixel) = pixelstruct;
}


// Subtracts the maxIntensity of the pixel from the current value to invert the colors
void Picture::invert()
{
	for(int i = 0; i < (int) pixels.size(); ++i)
	{
		pixels.at(i).red = maxIntensity - pixels.at(i).red;
		pixels.at(i).green = maxIntensity - pixels.at(i).green;
		pixels.at(i).blue = maxIntensity - pixels.at(i).blue;
	}
}


// Flips the picture across the x-axis by going through half of the height and flipping it
void Picture::flip_x()
{
	for(int i = 0; i < height/2; ++i)
	{
		for(int j = 0; j < width; ++j)
		{ 
			Pixel temp = get_pixel(i, j);
			Pixel temp2 = get_pixel(height-1-i, j);
			set_pixel(i, j, temp2);
			set_pixel(height-1-i, j, temp);
		}
	}
}


// Flips the picture across the y-axis by going through half of the width and flipping it
void Picture::flip_y()
{
	for (int j = 0; j < width/2; ++j)
	{
		for(int i = 0; i < height; ++i)
		{
			Pixel temp = get_pixel(i, j);
			Pixel temp2 = get_pixel(i, width-1-j);
			set_pixel(i, j, temp2);
			set_pixel(i, width-1-j, temp);
		}
	}
}


// Supposed to read the input from the file and update maxintensity, width and height, allocating space to the vector,
// and reading in all of the pixels and adding it to the vector. However it doesn't work.
bool Picture::read_input(istream &in)
{
	stringstream ss;
	string line, fileType;
	Pixel colors;
	int pixelCounter = 0;
	int initialCounter = 0;
	
		while (maxIntensity == 0)
		{
			getline(in, line);

			if(line[0] == '#')
				continue;

			ss << line;

			if (initialCounter == 0)
			{
				if (ss >> fileType)
				++initialCounter;
				else
					continue;

				if (fileType != "P3")
				{
					return false;
				}
			}

			if (initialCounter == 1)
			{
				if (ss >> width)
					++initialCounter;
				else
					continue;
			}

			if (initialCounter == 2)
			{
				if (ss >> height)
					++initialCounter;
				else
					continue;
			}

			if (initialCounter == 3)
			{
				if (ss >> maxIntensity)
					++initialCounter;
				else
					continue;
			}
		}

	pixels.reserve(width * height);

	while (getline(in, line))
	{
		if(line[0] == '#')
			continue;
		
		ss << line;

		if (pixelCounter == 0)
			++pixelCounter;

		if (pixelCounter == 1)
		{
			if (ss >> colors.red)
				++pixelCounter;
		}

		if (pixelCounter == 2)
		{
			if (ss >> colors.green)
				++pixelCounter;
		}

		if (pixelCounter == 3)
		{
			if (ss >> colors.blue)
				++pixelCounter;
		}

		if (pixelCounter == 4)
		{	
			pixels.push_back(colors);
			pixelCounter = 0;
		}	

		ss.clear();
	}


	if (pixels.capacity() != pixels.size())
		return false;

return true;
}


// Writes the output to the specified location
void Picture::write_output(ostream &out)
{
	if (out == "-")
	{
		cout << "P3\n" << width << " " << height << '\n';
		cout << maxIntensity << '\n';

		for(int i = 0; i < (int) pixels.size();  ++i)
		{
			cout << pixels.at(i).red << " " << pixels.at(i).green << " "
				<< pixels.at(i).blue << '\n';
		}
	}

	if (out != "-")
	{
		out << "P3\n" << width << " " << height << '\n';
		cout << maxIntensity << '\n';

		for(int i = 0; i < (int) pixels.size(); ++i)
		{
			cout << pixels.at(i).red << " " << pixels.at(i).green << " "
				<< pixels.at(i).blue << '\n';
		}
	}
}
