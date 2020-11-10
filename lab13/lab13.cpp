/* This program represents a vector and holds all of the written out functions that make up a vector
 * Author: Logan Tillman
 * Date: November 20, 2018 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

class doublevector {
     static constexpr double DOUBLE_DEFAULT_VALUE = -5.55;
     double *mValues;
     int mNumValues;
public:
     doublevector();
     ~doublevector();
     void resize(int new_size, double initial_value=DOUBLE_DEFAULT_VALUE);
     void push_back(double value);
     double &at(int index);
     const double &at(int index) const;
     unsigned long size() const;
};
void print_all(const doublevector &v)
{
     if (v.size() == 0) {
           cout << "Vector is empty.\n";
     }
     else {
          unsigned long i;
          for (i = 0;i < v.size();i++) {
                cout << "[" << setfill('0') << right << setw(3) << i
                     << "] = " << fixed << setprecision(4) << v.at(i)
                     << '\n';
          }
     }
}
int main()
{
      doublevector v;
      do {
           string command;
           cout << "Enter a command ('quit' to quit): ";
           if (!(cin >> command) || command == "quit") {
                break;
           }
           else if (command == "push_back") {
                double value;
                cin >> value;
                v.push_back(value);
		cout << "Pushed back "
		     << fixed << setprecision(4)
		     << value << '\n';
           }
           else if (command == "resize") {
                string line;
                int new_size;
                double initial;
                cin >> new_size;
                getline(cin, line);
                istringstream sin(line);

                if (sin >> initial)
                     v.resize(new_size, initial);
                else
                     v.resize(new_size);
           }
           else if (command == "size") {
                cout << v.size() << '\n';
           }
           else if (command == "print") {
                print_all(v);
           }
           else if (command == "get") {
                int index;
                cin >> index;
                try {
                     cout << "Value at " << index << " = "
		          << setprecision(4) << fixed
                          << v.at(index) << '\n';;
                }
                catch(out_of_range &err) {
                     cout << err.what() << '\n';
                }
           }
           else if (command == "set") {
		   double d;
		   int index;
                   cin >> index >> d;
                   try {
			v.at(index) = d;
                        cout << "SET: " << index << " = "
			     << setprecision(4) << fixed
                             << v.at(index) << '\n';;
                   }
                   catch(out_of_range &err) {
                        cout << err.what() << '\n';
                   }
           }
           else if (command == "clear") {
                v.resize(0);
           }
           else {
                cout << "Invalid command '" << command << "'\n";
           }
      } while(true);
      cout << endl;
      return 0;
}
//Write your class members below here.

// This is the constructor for the doublevector class
doublevector::doublevector()
{
	// Sets the initial size to 0 and makes mValues a null pointer
	mNumValues = 0;
	mValues = nullptr;
}

// This is the deconstructor for the class
doublevector::~doublevector()
{
	// If mValues isn't a null pointer, it'll delete it
	if (mValues != nullptr)
	{
		delete mValues;
		mValues = nullptr;
	}
}

// This is the resize function for the vector that takes a new size and initial value
void doublevector::resize(int new_size, double initial_value)
{
	// If the new size is less than 0, it does nothing
	if (new_size < 0)
	{
	}
		    
	// If the new size is 0, it deletes mValues and makes it a null ptr
	if (new_size == 0)
	{
		if (mValues != nullptr)
		{
			delete mValues;
			mValues = nullptr;
		}

		// Sets mNumValues equal to the new size
		mNumValues = new_size;
	}
			    
	// Executes if the new size is greater than the current size
	if (new_size > mNumValues)
	{
		// Creates a copy for mValues and gives it memory
		double *mValuesCopy = new double [new_size];

			// Loops through and copies over mValues to mValuesCopy
			for (int i = 0; i < mNumValues; i++)
			{
				mValuesCopy[i] = mValues[i];
			}
			
			// Deletes mValues if it's not a nullptr
			if (mValues != nullptr)
			{
				delete mValues;
				mValues = nullptr;
			}

			// Loops through and assigns the newly created variables to the initial value
			for (int i = mNumValues; i < new_size; i++)
			{
				mValuesCopy[i] = initial_value;														
			}					        
						
			// Sets mValues equal to the copy
			mValues = mValuesCopy;
			
			// Sets the size of the vector equal to the new size
			mNumValues = new_size;
	}
	
	// Executes if the new size is less than the current vector size
	if (new_size < mNumValues)
	{
		// Creates a copy for mValues and gives it memory
		double *mValuesCopy = new double [new_size];
		
		// Copies only the new size of the vector from mValues into the copy
		for (int i = 0; i < new_size; i++)
		{
			mValuesCopy[i] = mValues[i];
		}
		
		// Deletes mValues if it's not a null pointer
		if (mValues != nullptr)
		{
			delete mValues;
			mValues = nullptr;
		}

		// Sets the vector size equal to the new size
		mNumValues = new_size;
	}
}

// Increases the size of the vector by 1 and adds the element to the end
void doublevector::push_back(double value)
{
	// Calls the resize function where the size will be increased by one sets and initial value
	resize(mNumValues + 1, value);
}

// Returns the value at a given location
double & doublevector::at(int index)
{
	if (index >= mNumValues) {
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
		    
return mValues[index];
}

// Returns a read only value at a given location
const double & doublevector::at(int index) const
{
	if (index >= mNumValues) {
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
		    
return mValues[index];
}

// Returns the size of the vector
unsigned long doublevector::size() const
{
	unsigned long size = mNumValues;
		    
return size;
}

