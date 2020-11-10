/* Author: Logan Tillman
 * Date: November 6, 2018
 * This program is a speeding ticket calculator that will have the user input information about the parameters of their
 * speeding ticket into the command line and output the calculation of the speeding ticket into a file or terminal*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <istream>
#include <ostream>
#include <fstream>
using namespace std;

// Global variables for calculating and outputting the tickets
const double INTERSTATE = 5.2252;
const double HIGHWAY = 9.4412;
const double RESIDENTIAL = 17.1525;
const double NONE = 12.152;
const string monthLetters [12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// Structure for the Date of tickets and the inputs
struct Date
{
	int month;
	int day;
	int year;
};

// Structure that has all of the parameters for a speeding ticket
struct Ticket
{
	Date citationDate;
	string citationNumber;
	int clockedSpeed;
	int speedLimit;
	char roadType;
};

// Database that holds the tickets in the file
class Database
{
public:
	void add_ticket(const Ticket &t, Database &database);
	vector<Ticket> gen_report(Date &start, Date &end) const;
private:
	vector<Ticket> tickets;
};

// A function that will read in all of the tickets from a file and input it into a database
bool Read(Database &database, istream &in);

// A function that will calculate the tickets and write them to the terminal or a file
bool Write(const vector<Ticket> &tickets, ostream &out);

// A function that takes a date and translates it into an int (2017-08-27 -> 20170827) for comparison
int Encode(const Date &d);

int main(int argc, char **argv) 
{
	string ticketFile = argv[1];
	string reportFile = argv[4];
	stringstream ss;
	ifstream inputStream;
	ofstream outputStream;
	char junk;
	Date sdate;
	Date edate; 
	Database database;
	vector<Ticket> outputtickets;

		// Error check for the command line arguments entered
		if (argc != 5)
		{
			cout << "Usage: ./lab11 <input file> <start: year-month-day> <end: year-month-day> <output or '-'>\n";
			return 1;
		} 
	
		// Opens and error checks the input file
		inputStream.open(ticketFile);
			if(!inputStream.good()) 
			{
				cerr << "Unable to open " << ticketFile << '\n';
				return 1;
			}

		// Opens and error checks the output file if entered
		if (reportFile != "-")
		{
			outputStream.open(reportFile);
				if(!outputStream.good())
				{
					cerr << "Unable to open " << reportFile << '\n';
				return 1;
				}
		}

		// Calls and error checks the Read function, prints error message if returns false
		if(!Read(database, inputStream))
		{
			cerr << "Could not read from " << ticketFile << '\n';
			return 1;
		}

		// Uses a stringstream to extract the start and end dates from the command line and enter them into structs
		// uses junk to store the "-" character
		ss << argv[2];
		ss >> sdate.year >> junk >> sdate.month >> junk >> sdate.day;
		ss.clear();
		ss << argv[3];
		ss >> edate.year >> junk >> edate.month >> junk >> edate.day;

		// Runs gen_report to find the tickets within the dates, and calls Write depending on which output was entered in the command line
		outputtickets = database.gen_report(sdate, edate);
		if (reportFile == "-")
		{
			// Writes the output to the terminal
			Write(outputtickets, cout);
		}
		else
		{
			// Write the output to the entered file
			Write(outputtickets, outputStream);
		}

return 0;
}

// Takes a ticket structure and adds it to the Ticket vector in the database
void Database::add_ticket(const Ticket &ticket, Database &database)
{
	tickets.push_back(ticket);
}

// Reads all of the tickets in the file and calls add_ticket to add them to the database. Returns false if something fails
bool Read(Database &database, istream &in)
{
	Ticket ticket;
	
	// Stores the parameters of a ticket in the file to its respective spot in the ticket structure
	while (in >> ticket.citationNumber >> ticket.citationDate.month >> ticket.citationDate.day >> ticket.citationDate.year >> ticket.clockedSpeed >> ticket.speedLimit >> ticket.roadType)
	{
		// If the year in the ticket file is only a 2 digit year, this will convert it to 4 digits
		if (ticket.citationDate.year < 2000)
		{
			ticket.citationDate.year = ticket.citationDate.year + 2000;
		}
		
		// Calls add ticket to add the read ticket into the database
		database.add_ticket(ticket, database);
	}
return true;
}

// gen_report will take the entered start and end date and determine whether each ticket falls within the dates
vector<Ticket> Database::gen_report(Date &start, Date &end) const
{
	vector<Ticket> outputtickets;
	int startdate, enddate;

		// Turns both of the dates into integers through the Encode function
		startdate = Encode(start);
		enddate = Encode(end);

		// Loops through each ticket in the file and compares it with the date to see if it falls within the parameters
		// If a ticket falls within the entered dates, it will be added to the outputtickets vector
		for (int i = 0; i < (int) tickets.size(); ++i)
		{
			// Runs Encode on the ticket date for comparison
			int ticketdate = Encode(tickets.at(i).citationDate);

				// Compares the dates, and adds the ticket to the vector if it falls within the dates
				if (startdate <= ticketdate && enddate >= ticketdate)
				{
					outputtickets.push_back(tickets.at(i));
				}
		}

// Returns the vector that holds the correct tickets to output
return outputtickets;
}

// Calculates the ticket prices and outputs them to the correct location
bool Write(const vector<Ticket> &tickets, ostream &out)
{
	// If the output is invalid it will fail
	if(!out)
	{
		return false;
	}
	
	int speed, speedLimit, day, month, year;
	double price;
	char roadType;
	string citationNumber;

	// Loops through all of the tickets to calculate them
	for (int i = 0; i < (int) tickets.size(); ++i)
	{
		
		// Creates new variables for the ticket structs to make the code more readable
		speed = tickets.at(i).clockedSpeed;
		speedLimit = tickets.at(i).speedLimit;
		roadType = tickets.at(i).roadType;
		citationNumber = tickets.at(i).citationNumber;
		year = tickets.at(i).citationDate.year;
		month = tickets.at(i).citationDate.month;
		day = tickets.at(i).citationDate.day;
		price = 0;

		// Takes the road type and calculates the price for the speeding ticket
		switch (roadType)
		{
			case ('r'):
			case ('R'):
				price = (speed - speedLimit) * RESIDENTIAL;
				break;
			case ('i'):
			case ('I'):
				price = (speed - speedLimit) * INTERSTATE;
				break;
			case ('h'):
			case ('H'):
				price = (speed - speedLimit) * HIGHWAY;
				break;
			default:
				price = (speed - speedLimit) * NONE;					
				break;
		}

		// Makes sure the price isn't negative	
		if (price < 0)
			price = 0;

		// If the user enters "-" for the output location it will output to the terminal
		if (out == "-")
		{
			cout << setw(2) << setfill ('0') << day << "-" << monthLetters[month-1]
				<< "-" << year << " ";
			cout << citationNumber << "    $ " << setw(9) << setfill(' ') << fixed 
				<< setprecision(2) << price << '\n';
		}

		// If the user enters a file for the output location this will output to that file
		else if (out != "-")
		{
			out << setw(2) << setfill ('0') << day << "-" << monthLetters[month-1]
				<< "-" << year << " ";
			out << citationNumber << "    $ " << setw(9) << setfill(' ') << fixed 
				<< setprecision(2) << price << '\n';
		}
	}
return true;
}

// This function will take a date structure and turn it into an integer
int Encode(const Date &d)
{
string syear, smonth, sday, encodestring;
int encode;
	
	// Converts the year into a string
	syear = to_string(d.year);
	
	// Converts the month into a string and adds a "0" at the front if it's a single digit month
	smonth = to_string(d.month);
		if (smonth.size() != 2)
			smonth.insert(0, "0");
	
	// Converts the day into a string and adds a "0" at the front if it's a single digit day	
	sday = to_string(d.day);
		if (sday.size() != 2)
			sday.insert(0, "0");

	// Adds all of the strings together into one e.x. (2017 + 08 + 27 = 20170827)
	encodestring = syear + smonth + sday;

	// Turns the final string into an integer
	encode = stoi(encodestring);

return encode;
}
