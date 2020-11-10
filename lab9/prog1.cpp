#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;



int main(int argc, char *argv[]) {

	int num_to_generate = 5;
	int seed = time(nullptr);

	if (argc > 1) {
		stringstream ss(argv[1]);
		ss >> num_to_generate;
	}
	
	if (argc > 2) {
		stringstream ss(argv[2]);
		ss >> seed;
	}
		srand(seed);

		for (int i = 0; i < num_to_generate; ++i) {
			cout << rand() << '\n';
		}





return 0;
}
