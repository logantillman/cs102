#include <iostream>

using namespace std;

int main()
{
	bool boolVar = true;
	int intVar = 25;
	double doubleVar = 1.23;

	bool* boolPtr = &boolVar;
	int* intPtr = &intVar;
	double* doublePtr = &doubleVar;

	cout << "boolPtr = " << boolPtr << '\n';
	cout << "intPtr = " << intPtr << '\n';
	cout << "doublePtr = " << doublePtr << '\n';

	cout << "*boolPtr = " << *boolPtr << '\n';
	cout << "*intPtr = " << *intPtr << '\n';
	cout << "*doublePtr = " << *doublePtr << '\n';

	cout << "&boolPtr = " << &boolPtr << '\n';
	cout << "&intPtr = " << &intPtr << '\n';
	cout << "&doublePtr = " << &doublePtr << '\n';
return 0;
}
