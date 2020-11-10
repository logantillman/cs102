#include <iostream>
using namespace std;

class Y {
	public:
		Y() { count++; }
		static int getCount() { return count; }
	private:
		static int count;
};

int Y::count = 0;

int main()
{
	cout << "Count: " << Y::getCount() << '\n';
	Y a;
	Y b;
	Y c;
	cout << "Count: " << Y::getCount() << '\n';




return 0;
}
