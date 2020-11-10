/* This program will have a user input a left and right operand along with an operation and will output the calculation
 * Author: Logan Tillman
 * Date: September 5, 2018 */

#include <iostream> 
using namespace std;
int main()
{
   double leftOperand;
   double rightOperand;
   char userOperation;
   double userResult;

   cout << "Enter left operand: ";
      if (!(cin >> leftOperand)) { //checks to see if leftOperand is a valid number
		  cout << "Invalid left operand." << '\n'; //prints if leftOperand is invalid
		  return 1; //ends program if leftOperand is invalid
	  }
   cout << "Enter operation: ";
   cin >> userOperation;
   if (userOperation == '|' || userOperation == 'b' || userOperation == 'B') //checks to see if the userOperation is for absolute value
   {
		if (leftOperand >= 0)
		{
			userResult = leftOperand; //if the leftOperand is greater than or equal to 0 then the answer is the leftOperand
		}
		else 
		{
			userResult = leftOperand * -1; //if the leftOperand is less than 0, it'll multiply by -1 to get the absolute value
		}
		cout << "Result: " << userResult << '\n'; //prints the result if it's absolute value
		return 1; //will end the program once it prints the result for abs value
   }
   else
   {

   cout << "Enter right operand: ";
   if (!(cin >> rightOperand)) { //error statement for rightOperand
		cout << "Invalid right operand." << '\n'; //prints if rightOperand is invalid
		return 1; //will end the program if rightOperand is invalid
   }
   else
   {
   switch (userOperation) //checks input to see which operation to execute
	{
		case('A'): //checking for addition operation
		case('a'):
		case('+'):
			userResult = leftOperand + rightOperand; //result is the sum of leftOperand and rightOperand
			break;
		case('S'): //checking for subtraction operation
		case('s'):
		case('-'):
			userResult = leftOperand - rightOperand; //result is the rightOperand subtracted from the leftOperand
			break;
		case('M'): //checking for multiplicaiton operation
		case('m'):
		case('x'):
		case('*'):
			userResult = leftOperand * rightOperand; //result is the product of the leftOperand and the rightOperand
			break;
		case('D'): //checking for division operation
		case('d'):
		case('/'):
			userResult = leftOperand / rightOperand; //result is the leftOperand divided by the rightOperand
			break;
		default:
			cout << "Unknown Operation." << '\n'; //default statement for the switch will print if the userOperation isn't valid
			return 1; //program will end if the default statement executes
		break;
    }
   }
   }
   cout << "Result: " << userResult << '\n'; //prints the result of the function executed
 


   return 0; //finally ends the program
}
