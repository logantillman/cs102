#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <vector>
using namespace std;

struct Pixel
{
	int red;
	int green;
	int blue;
};

int main()
{
	stringstream ss;
	ifstream inputStream;
	string inputFile;
	string junk, line;
	vector<Pixel> pixels;
	Pixel colors;
	int i = 0;
	string fileType;
	int width = 0;
	int height = 0;
	int maxIntensity = 0;
	int once = 0;		
	int wandh = 0;
		cout << "Enter input file: ";
			cin >> inputFile;
	
		inputStream.open(inputFile);
			if (!inputStream.good())
				cerr << "you done fucked up chief\n";
	
		while (getline(inputStream, line))
		{

			if(line[0] == '#')
				continue;
			ss << line;

			if (once == 0)
			{
				ss >> fileType;
				++once;

				cout << "File type: " << fileType << '\n';

				if (fileType != "P3")
				{
					cerr << "wrong filetype\n";
					return -1;
				}
			}

			if (wandh == 0)
			{
				if(ss >> width)
				{
				++wandh;
				cout << "Width: " << width << '\n';
				}
			}

			if (wandh == 1)
			{
				if(ss >> height)
				{
				++wandh;
				cout << "Height: " << height << '\n';
				}
			}

			if (wandh == 2)
			{
				if(ss >> maxIntensity)
				{
				++wandh;
				cout << "Max Intensity: " << maxIntensity << '\n';
				}
			}

			if (i == 0)
				++i;	
		
			if (i == 1)
			{
				if (ss >> colors.red)
					++i;
			}
			
			if (i == 2)
			{
				if (ss >> colors.green)
					++i;
			}
		
			if (i == 3)
			{
				if (ss >> colors.blue)
					++i;
			}
			
			if (i == 4)
			{
				pixels.push_back(colors);
				i = 0;
			}

			ss.clear();
		}
	
		for(int i = 0; i < (int) pixels.size(); ++i)
			cout << "red: " <<  pixels.at(i).red 
				<< " green: " << pixels.at(i).green
				<< " blue: " << pixels.at(i).blue 
				<< '\n';

return 0;
}
