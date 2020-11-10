#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double Distance(const vector<double> &u, const vector<double> &v);

int main(int argc, char *argv[])
{
	vector<double> u(3);
	cout << "Input x, y, z of u: ";
	cin >> u.at(0) >> u.at(1) >> u.at(2);

	vector<double> v(3);
	cout << "Input x, y, z of v: ";
	cin >> v.at(0) >> v.at(1) >> v.at(2);

	cout << "D(u,v) = " << Distance(u, v) << '\n';

	return 0;
}

double Distance(const vector<double> &u, const vector<double> &v)
{
	double dx2 = pow(v.at(0) - u.at(0), 2);
	double dy2 = pow(v.at(1) - u.at(1), 2);
	double dz2 = pow(v.at(2) - u.at(2), 2);

	return sqrt(dx2 + dy2 + dz2);
}
