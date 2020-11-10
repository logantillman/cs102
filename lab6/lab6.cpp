/* Author: Logan Tillman
 * Date: September 26, 2018
 * This program is a speeding ticket calculator that will have the user input information about the parameters of their
 * speeding ticket and output the calculation of the speeding ticket into a file */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {

	const double interstate = 5.2252;
	const double highway = 9.4412;
	const double residential = 17.1525;
	const double none = 12.152;
	string citationNumber;
	int month, day, year, speed, speedLimit, startMonth, startDay, startYear, endMonth, endDay, endYear;
	double price;
	char roadType;
	string monthLetters [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	string ticketFile, reportFile, line;
	istringstream iss;
	ifstream inputStream;
	ofstream outputStream;

		cout << "Enter a ticket file: ";
			cin >> ticketFile;
		
			inputStream.open(ticketFile);
				if(!inputStream.good()) {
					cout << "Unable to open " << ticketFile << '\n';
					return 1;
				}

		cout << "Enter a report file: ";
			cin >> reportFile;
	
		outputStream.open(reportFile);

		cout << "Enter report start date (mm dd yyyy): ";
			cin >> startMonth >> startDay >> startYear;
		cout << "Enter report end date (mm dd yyyy): ";
			cin >> endMonth >> endDay >> endYear;
	
		while (getline(inputStream, line)) {
			iss.clear();
			iss.str(line);
			iss >> citationNumber >> month >> day >> year >> speed >> speedLimit >> roadType;

			if (year < 2000) {
				year = year + 2000;
			}

			if (year >= startYear && year <= endYear) {
				if (((year == startYear) && (month >= startMonth)) || ((year == endYear) && (month <= endMonth)) || ((year > startYear) && (year < endYear))) {
					if (((year == startYear) && (month == startMonth) && (day >= startDay)) || ((year == endYear) && (month == endMonth) && (day <= endDay)) ||
							((year > startYear) && (year < endYear)) || ((year == startYear) && (month > startMonth)) || ((year == endYear) && (month < endMonth))) {

			switch (roadType) {
				case ('r'):
				case ('R'):
					price = (speed - speedLimit) * residential;
					break;
				case ('i'):
				case ('I'):
					price = (speed - speedLimit) * interstate;
					break;
				case ('h'):
				case ('H'):
					price = (speed - speedLimit) * highway;
					break;
				default:
					price = (speed - speedLimit) * none;
					break;
			}

			if (price < 0) {
				price = 0;
			}

			outputStream << setw(2) << setfill('0') << day << "-" << monthLetters[month-1]
				<< "-" << year;
			outputStream << " " << citationNumber << "    $ " << setw(9) << setfill(' ') << fixed << setprecision(2) 
				<< price << '\n'; 
		
					}
				}
				}
			}
		
		



return 0;
}
