// Slot Machine Program
// Jackpot = 777 - 10x bet
// 3 of a kind - 5x bet
// 2 of a kind - 3x bet

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

void Spin(vector<int> &values, int low = 2, int high = 7);
int ComputeWinnings(const vector<int> &values, int bet);

int main() {
	srand(time(nullptr));

	int money = 1000;

	while (money > 0) {
		cout << "You have $" << money << '\n';
		int bet;
		do {
			cout << "Place a bet: ";
			cin >> bet;
		while (bet > money);
		}

		vector<int> vals(3);
		Spin(vals);
	}
	money -= bet

		vetor<int> vals(3);
	Spin(vals);
	int winnings = ComputerWinnings(vals, bet);
	money += winnings;

	if (winnings > 0) {
		cout << "You won $" << winnings << "!\n";
	}
	else {
		cout << "You lost.\n";

	}
return 0;
}


void Spin(vector<int> &values, int low, int high) {
	for (auto &val : values) {
		val = low + rand() % (high - low + 1);
		cout << " " << val;
	}
	cout << '\n';
}

int ComputeWinnings(const vector<int> &values, int bet) {
	if (values.at(0) == values.at(1) && values.at(0) == values.at(2)) {
		if (values.at(1) == 7) {
			return bet * 10;
		}
	}
}













