#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> A;
	unsigned int capacity = A.capacity();
	cout << "capacity: " << capacity << '\n'; 
	
		for (int i = 0; i < 10; ++i)
		{
			A.push_back(i);
			cout << i << ": " << A.capacity() << '\n';
			if (A.capacity() != capacity)
			{
				capacity = A.capacity();
			}
		}

		A.reserve(100);
		cout << "capacity: " << A.capacity() << '\n';

return 0;
}
