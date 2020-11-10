#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int GetRandom(int minimumValue, int maximumValue) {
	int randomCard;

	randomCard = minimumValue + rand() % (maximumValue - minimumValue + 1);
	return randomCard;
}

  int DealCard(int (&playerCard)[52], const int &i) {
//string DealCard(int (&playerCard)[52], const int &i, char (&suitArray)[4], const string (&numberArray)[13]) {
	
//	int suit, number;
//	string cardsuit, cardnumber, fullcard;
		int card = GetRandom(0, 51);
		while (playerCard[card] != 0) {
			card = GetRandom(0, 51);
		}
			playerCard[card] = i;
		/*	suit = card % 4;
			number = card / 4;
			cardnumber = numberArray[number];
			cardsuit = suitArray[suit];
			fullcard = cardnumber + cardsuit; */
			//cout << fullcard << " \n"; 
return card;
}

int ScoreHand (string cardnumber1, string cardnumber2) {
	int score = 0;
	if (cardnumber1 == "A" || cardnumber2 == "A") {
		score = score + 1; }
	if (cardnumber1 == "2" || cardnumber2 == "2") {
		score = score + 2; }
	if (cardnumber1 == "3" || cardnumber2 == "3") {
		        score = score + 3; }
	if (cardnumber1 == "4" || cardnumber2 == "4") {
		        score = score + 4; }
	if (cardnumber1 == "5" || cardnumber2 == "5") {
		        score = score + 5; }
	if (cardnumber1 == "6" || cardnumber2 == "6") {
		        score = score + 6; }
	if (cardnumber1 == "7" || cardnumber2 == "7") {
		        score = score + 7; }
	if (cardnumber1 == "8" || cardnumber2 == "8") {
		        score = score + 8; }
	if (cardnumber1 == "9" || cardnumber2 == "9") {
		        score = score + 9; }
	if (cardnumber1 == "10" || cardnumber1 == "J" || cardnumber1 == "Q" || cardnumber1 == "K") {
		score = score + 10; }
	if (cardnumber2 == "10" || cardnumber2 == "J" || cardnumber2 == "Q" || cardnumber2 == "K") {
		score = score + 10; }
return score;
}






/* string ConvertHand(const int &card) {
	int suit, number;
	string cardnumber, cardsuit, fullcard, cardConvert;

	suit = card % 4;
	number = card / 4;
	cardnumber = numberArray[number];
	cardsuit = suitArray[suit];
	fullcard = cardnumber + cardsuit;
return fullcard;
} */

int main() {
	srand(time(nullptr));
	int playerCard[52] = {0};
	char suitArray[4] {'H', 'C', 'D', 'S'};
	string numberArray[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	int numPlayers;

	cout << "Enter Numplayers ";
		cin >> numPlayers;

	for(int i = 1; i <= numPlayers; ++i) {
		int suit, number, card;
		string cardnumber1, cardnumber2, cardsuit, card1, card2, combinedCards;

		card = DealCard(playerCard, i);
		suit = card % 4;
		number = card / 4;
		cardnumber1 = numberArray[number];
		cardsuit = suitArray[suit];
		card1 = cardnumber1 + cardsuit;

		card = DealCard(playerCard, i);
		suit = card % 4;
		number = card / 4;
		cardnumber2 = numberArray[number];
		cardsuit = suitArray[suit];
		card2 = cardnumber2 + cardsuit;

		combinedCards = card1 + " " + card2;

		cout << "Player " << i << " has cards: " << setw(20) << setfill(' ') << left << combinedCards; 
		cout << "(" << ScoreHand(cardnumber1, cardnumber2) << ")" << '\n';

	/*	cout << "Player " << i << " has cards: "
			<< DealCard(playerCard, i, suitArray, numberArray) << " " 
			<< DealCard(playerCard, i, suitArray, numberArray) << '\n'; */
	}
	
	
//	for(int i = 0; i < 52; ++i) {
	//	cout << playerCard[i] << " \n";
//	}



return 0;
}
