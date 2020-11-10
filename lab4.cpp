/* Author: Logan Tillman
 * Date: September 12, 2018
 * This program will have a user input the number of miles and number of gallons used on a truck or car
 * and spit out the average miles per gallon for each */
#include <iostream>
#include <limits>
using namespace std;

int main() {

string userCommand;
double carMiles = 0.0;		
double carGallons = 0.0;
double truckMiles = 0.0;
double truckGallons = 0.0;
double carMPG = 0.0;
double truckMPG = 0.0;
double tempcarGallons = 0.0; //My temporary variables are used in the running totals, when I used carMiles =+ carMiles it gave me decimal inaccuracies. This probably isn't very efficient but it works.
double tempcarMiles = 0.0;
double temptruckGallons = 0.0;
double temptruckMiles = 0.0;

	cout << "Enter command: ";
	cin >> userCommand;	//This will take the intial input of the user

	while (userCommand == userCommand) {	//This while statement is the initial loop that will always execute, this is done so it'll run infinitely until the user types "done"

		while (userCommand == "car" || userCommand == "truck" || userCommand == "done") {	/*This is my nested loop. When the user types "car" "truck" or "done", it'll
																							  proceed into the individual if statements that will then make their calculations */

			if (userCommand == "car") {	//This is the if statement that'll execute if the user enters "car"
		
				cout << "Enter car's miles: ";
					while (!(cin >> tempcarMiles)) {	//This is my loop for the carMiles, if the user enters an invalid number, it'll keep asking until a valid number is given
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter car's miles: ";
					}

				carMiles = carMiles + tempcarMiles;	//This is the running total for carMiles that'll be used for calculations when the user types "done" 
		
				cout << "Enter car's gallons: ";
					while (!(cin >> tempcarGallons)) {	//This is the same loop for carGallons, which will repeat until a valid number is input
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter car's gallons: ";
					}

				carGallons = carGallons + tempcarGallons;	//This is the running total for carGallons, which is also used for calculations when the user types "done"
			
				cout << "Enter command: "; //This is the end of the car if statement where it asks for another command, if it's not "car" the program will enter a different loop
				cin >> userCommand;

			}	

			else if (userCommand == "truck") {	//This else if statement will execute when the user types "truck"
			
				cout << "Enter truck's miles: ";
					while (!(cin >> temptruckMiles)) {	//This is the loop for truckMiles, just like carMiles, it won't proceed until given a valid input
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter truck's miles: ";
					}

				truckMiles = truckMiles + temptruckMiles;	//This is the running total for truckMiles used for calculations when the user types "done"

				cout << "Enter truck's gallons: ";
					while (!(cin >> temptruckGallons)) {	//This is the loop for truckGallons, the same process as all the other loops, will repeat until valid input
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter truck's gallons: ";
					}

				truckGallons = truckGallons + temptruckGallons;	//running total for truckGallons used in calculations

				cout << "Enter command: "; //This input will determine which loop the program will enter next
				cin >> userCommand;
			}
			
			else if (userCommand == "done") {	//This else if statement will calculate the average MPGs if the user types "done"
				
				carMPG = carMiles / carGallons;	//This calculates the average MPG for the cars
				truckMPG = truckMiles / truckGallons;	//This calculates the average MPG for the trucks

					if (carMPG != carMPG) {	//This statement says if carMPG is false, it'll output that the fleet has no cars
						cout << "Fleet has no cars." << '\n';
					}

					else {	//This will make the calculation for the carMPG as long as it has a value
						cout << "Average car MPG = " << carMPG << '\n';
					}

					if (truckMPG != truckMPG) {	//Same thing with the trucks, if it's false, it'll output that the fleet has no trucks
						cout << "Fleet has no trucks." << '\n';
					}

					else {	//This will make the calculation for the truckMPG as long as it has a value
						cout << "Average truck MPG = " << truckMPG << '\n';
					}

				return 1;	//This will end the program once the calculation is made and the output is given
			}

	
		}

		cout << "Unknown command." << '\n';	//If an invalid command is given, the program will output "Unknown command"
		cout << "Enter command: ";	//If the user inputs and invalid command, this will ask for another command until a valid one is entered
		cin >> userCommand;

		}



return 0;
}




