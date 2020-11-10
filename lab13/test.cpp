#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> test = {0, 1, 2, 3, 4, 5, 6, 7};

		for (int i = 0; i < test.size(); ++i)
		{
			cout << "Value at " << i << " = " << test.at(i) << '\n';
		}

	test.resize(3, 5);

	for (int i = 0; i < test.size(); ++i)
	{
		cout << "Resized vector " << test.at(i) << " ";
	}

	

return 0;
}	
