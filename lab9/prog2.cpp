#include <iostream>
#include <cmath>

using namespace std;

double deg2rad(double);

int main(int argc, char *argv[])
{
	double degrees;
	cout << "Input a value in degrees: ";
	cin >> degrees;

	double radians = deg2rad(degrees);
	
	cout << "cos(" << degrees << ") = "
		 << cos(radians) << '\n';
	cout << "sin(" << degrees << ") = "
		 << sin(radians) << '\n';
	cout << "tan(" << degrees << ") = "
		 << tan(radians) << '\n';
	cout << "cos^2(" << degrees << ") = "
		 << pow(cos(radians), 2) << '\n';

return 0;
}

double deg2rad(double deg)
{
	return deg * M_PI / 180;
}
