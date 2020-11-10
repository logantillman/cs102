/* This program will have the user enter the amount of players, then the program will
 * distribute 2 random cards to each player */
// Author: Logan Tillman
// Date: October 12, 2018

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Gets a random number 0-51 , which corresponds to one card in a 52 card deck
int GetRandom(int minimumValue, int maximumValue) {
	int randomCard;
	randomCard = minimumValue + rand() % (maximumValue - minimumValue + 1);
return randomCard;
}

// Calls GetRandom to generate a random card and assigns it to whichever player is entered
int DealCard(int (&playerCard)[52], const int &player) {
		int cardNum = GetRandom(0, 51);
		while (playerCard[cardNum] != 0) {	// If the array that holds the card value isn't empty at the drawn value the function will
			cardNum = GetRandom(0, 51);		// call  GetRanGG
		}
		playerCard[cardNum] = player;
return cardNum;
}

// The Scoring function that will take the card values A-K and add up the scores 
int ScoreHand(string cardNumber1, string cardNumber2) {
	int score = 0;
	if (cardNumber1 == "A" || cardNumber2 == "A") {
		    score = score + 1; }
	if (cardNumber1 == "2" || cardNumber2 == "2") {
			score = score + 2; }
	if (cardNumber1 == "3" || cardNumber2 == "3") {
			score = score + 3; }
	if (cardNumber1 == "4" || cardNumber2 == "4") {
			score = score + 4; }
	if (cardNumber1 == "5" || cardNumber2 == "5") {
			score = score + 5; }
	if (cardNumber1 == "6" || cardNumber2 == "6") {
			score = score + 6; }
	if (cardNumber1 == "7" || cardNumber2 == "7") {
			score = score + 7; }
	if (cardNumber1 == "8" || cardNumber2 == "8") {
			score = score + 8; }
	if (cardNumber1 == "9" || cardNumber2 == "9") {
			score = score + 9; }
	if (cardNumber1 == "10" || cardNumber1 == "J" || cardNumber1 == "Q" || cardNumber1 == "K") {
			score = score + 10; }
	if (cardNumber2 == "10" || cardNumber2 == "J" || cardNumber2 == "Q" || cardNumber2 == "K") {
			score = score + 10; }
return score;
}

int main() {

int numPlayers;
int playerCard[52] = {0};
char suitValues[4] = {'H', 'C', 'D', 'S'};
string numberValues[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

	srand(time(nullptr)); // Uses current time to seed the rand function

	cout << "How many players? ";
	cin >> numPlayers;

	// Loops through the number of players and will draw 2 cards for each player, detemine what the cards are, and score them
	for(int i = 1; i <= numPlayers; ++i) {
		int suit, number, arrayNumber;
		string cardNumber1, cardNumber2, cardSuit, card1, card2, combinedCards;

		arrayNumber = DealCard(playerCard, i); // Draws the first card by calling DealCard
		suit = arrayNumber % 4;				   // Arithmetic for the suit of the card drawn
		number = arrayNumber / 4;			   // Arithmetic for the number of the card drawn
		cardNumber1 = numberValues[number];	   // Determines the number value for the card
		cardSuit = suitValues[suit];		   // Determines the suit value for the card
		card1 = cardNumber1 + cardSuit;		   // Puts the card number and suit into a string to print out

		arrayNumber = DealCard(playerCard, i); // Draws the second card and repeats the same procress as above
		suit = arrayNumber % 4;
		number = arrayNumber / 4;
		cardNumber2 = numberValues[number];
		cardSuit = suitValues[suit];
		card2 = cardNumber2 + cardSuit;		   // Puts the second card number and suit into a string

		combinedCards = card1 + " " + card2;   // Combines the two card strings into one to make correct formatting possible 

		cout << "Player " << i << " has cards: " << setw(20) << setfill(' ') << left << combinedCards;
		cout << "(" << ScoreHand(cardNumber1, cardNumber2) << ")" << '\n';
	}

return 0;
}
