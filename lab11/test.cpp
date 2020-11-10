#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
//	string argv[4] = {"2011-10-03", "2009-09-02", "2014-02-21", "2015-05-12"};
	int year1, day1, month1;
	char junk;
//	int enteredyear;
	stringstream iss;
	string syear, sday, smonth, test;
	int test2, test3;

//	cout << "Enter which variable to access";
//	cin >> enteredyear;
	
//	getline (argv[enteredyear], line);
//		cin >> year >> month >> day;

//	cout << year << " " << month << " " << day << '\n';
		iss << argv[2];
	//	iss.clear();
	//	iss.str();
	//	iss.clear;
		iss >> year1 >> junk >> month1 >> junk >> day1;
		iss.clear();
		syear = to_string(year1);
		smonth = to_string(month1);
			if (smonth.size() != 2)
				smonth.insert(0, "0");
		sday = to_string(day1);
			if (sday.size() != 2)
				sday.insert(0, "0");
		test = syear + smonth + sday;
		test2 = stoi(test);
		
		iss << argv[3];
		iss >> year1 >> junk >> month1 >> junk >> day1;
		iss.clear();
		syear = to_string(year1);
		smonth = to_string(month1);
		sday = to_string(day1);
		test = syear + smonth + sday;
		test3 = stoi(test);
		


		cout << test2 << " " << test3 << '\n';
	//	cout << year << " " << month << " " << day << '\n';

return 0;
}
