#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
	double x, y;
};

class Rectangle
{
public:
	Point p1;
	Point p2;

	double Area();
};

int main ()
{
	Rectangle r;
	
	cout << "Enter point 1 x and y coordinate: ";
	cin >> r.p1.x >> r.p1.y;
	cout << "Enter point 2 x and y coordinate: ";
	cin >> r.p2.x >> r.p2.y;

	cout << "Area: " << r.Area() << '\n';

return 0;
}

double Rectangle::Area()
{

	double width = abs(p1.x - p2.x);
	double height = abs(p1.y - p2.y);

return width * height;
}

