#include <iostream>
using namespace std;

class X {
public:
	static int getNextID() { return nextID++; } 
private:
	static int nextID;
};

int X::nextID = 0;

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		cout << "Next ID = " << X::getNextID() << '\n';
	}

return 0;
}
