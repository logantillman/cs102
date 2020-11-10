#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 2, 4 ,6, 8, 10 };

	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';

	int* arrPtr = arr;

	for (int i = 0; i < 5; ++i)
	{
		cout << *(arrPtr + i) << ' ';
	}
	cout << '\n';

	for (int i = 0; i < 5; ++i)
	{
		cout << *arrPtr << ' ';
		arrPtr++;
	}
	cout << '\n';

return 0;
}
