#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() { 

string userFile;

	cout << "Enter a ticket file: ";
	cin >> userFile;
	ifstream in(userFile.c_str());

	if (!in) {
		cerr << "Unable to open " << userFile << ".\n";
		return 1;
	}

string fileLine;
string citationNumber;
int numMonth;
int numDay;
int clockedSpeed;
int speedLimit;
char typeRoad;
	while (in >> fileLine) { 
		in >> citationNumber >> numMonth >> numDay >> clockedSpeed >> speedLimit >> typeRoad;
		cout << citationNumber << " " << numMonth << " " << numDay << " "
			 << clockedSpeed << " " << speedLimit << " " << typeRoad << '\n';
	}

	in.close();

}
