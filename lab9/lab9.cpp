/* This program is a game of blackjack. Two cards are dealt to the dealer as well as the player. The player can either hit or stand,
 * where hitting will draw another card. The goal is for the player to get closer to 21 than the dealer without going over */
// Author: Logan Tillman
// Date: October 25, 2018

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;
 
// Gets a random number 0-51 , which corresponds to one card in a 52 card deck
int GetRandom(int minimumValue, int maximumValue);

// Calls GetRandom to generate a random card and assigns it to whichever player is entered
int DealCard(int playerCard[52],const int player);

// The Scoring function that will take the card values A-K and add up the scores 
int ScoreHand(const vector<int> &);

// Converts the randomly generated number into a card value and suit
string NumToHand(int arrayNumber);

// Outputs the current hand along with the score of the dealer's hand
void OutputDealer(const vector<string> &, const vector<int> &);

// Outputs the current hand along with the score of the player's hand
void OutputPlayer(const vector<string> &, const vector<int> &);

// Outputs the statement when the dealer hits along with his newly updated hand and score
void DealerHit(const vector<string> &, const vector<int> &);

// Outputs the stand statement for the dealer along with his final hand
void DealerStand(const vector<string> &, const vector<int> &);

// Initializes the card array to 0 (which means unassigned)
void InitializeCards(int playerCard[52]);

int main() 
{

	// The array for the 52 deck of cards
	int playerCard[52];
	
	// Holds the players action whether it's hit or stand
	string playerAction;
	
	// The Dealer's player number to assign him cards
	const int DEALER = 1;
	
	// The Player's player number to assign him cards
	const int PLAYER = 2;

	// Holds the array numbers for the dealers cards
	vector<int> DealerCardNumber;
	
	// Holds the array numbers for the players cards
	vector<int> PlayerCardNumber;
	
	// Holds the card value and card suit for the dealer
	vector<string> DealerCardHand;
	
	// Holds the card value and card suit for the player
	vector<string> PlayerCardHand;

		// Initializes the cards to 0 which means they're unassigned
		InitializeCards(playerCard);

		// Uses the current time to seed the rand function
		srand(time(nullptr));

		// Initially draws 2 cards for the dealer and outputs his hand
			for(int i = 0; i < 2; ++i)
			{
				DealerCardNumber.push_back(DealCard(playerCard, DEALER));
				DealerCardHand.push_back(NumToHand(DealerCardNumber.at(i)));
			}
	
		OutputDealer(DealerCardHand, DealerCardNumber);
		
		// Initially draws 2 cards for the player and outputs the hand
			for(int i = 0; i < 2; ++i)
			{
				PlayerCardNumber.push_back(DealCard(playerCard, PLAYER));
				PlayerCardHand.push_back(NumToHand(PlayerCardNumber.at(i)));
			}

		OutputPlayer(PlayerCardHand, PlayerCardNumber);

		cout << "Hit or stand? ";
		cin >> playerAction;
		
	while (true)
	{

	// While the player hits this will draw another card and add it to the player's card vector
		while (playerAction == "Hit" || playerAction == "hit")
		{
			PlayerCardNumber.push_back(DealCard(playerCard, PLAYER));
			PlayerCardHand.push_back(NumToHand(PlayerCardNumber.at(PlayerCardNumber.size() - 1)));

			OutputDealer(DealerCardHand, DealerCardNumber);
			OutputPlayer(PlayerCardHand, PlayerCardNumber);
				
			// If the user hits and gets a card value greater than 21 he will bust
				if (ScoreHand(PlayerCardNumber) > 21)
				{
				cout << "Player busts, dealer wins!\n";
				return 1;
				}

			// If the user hits and gets 21 he will automatically win the game
				if (ScoreHand(PlayerCardNumber) == 21)
				{
				cout << "Player wins!\n";
				return 1;
				}
				
			// Otherwise will ask the user if they want to hit or stand
				cout << "Hit or stand? ";
				cin >> playerAction;
		}

		if (playerAction == "Stand" || playerAction == "stand")
		{
			// If the user stands and the scores are equal they will tie
			if (ScoreHand(DealerCardNumber) == ScoreHand(PlayerCardNumber))
			{
				OutputDealer(DealerCardHand, DealerCardNumber);
				OutputPlayer(PlayerCardHand, PlayerCardNumber);
				cout << "Player and dealer draw. \n";
				return 1;
			}
			
			// If the user stands and the dealer has a greater score, the dealer wins
			if (ScoreHand(DealerCardNumber) > ScoreHand(PlayerCardNumber))
			{
				OutputDealer(DealerCardHand, DealerCardNumber);
				OutputPlayer(PlayerCardHand, PlayerCardNumber);
				cout << "Dealer wins! \n";
				return 1;
			}

			// While the dealer's score is less than 18 and less than or equal to the player's score, he will keep hitting
			while (ScoreHand(DealerCardNumber) < 18 && ScoreHand(DealerCardNumber) <= ScoreHand(PlayerCardNumber))
			{
				// This will push back the dealer's cards after drawing one
				DealerCardNumber.push_back(DealCard(playerCard, DEALER));
				
				// Pushes back the dealer's card value and suit vector after converting the newly drawn card into a hand
				DealerCardHand.push_back(NumToHand(DealerCardNumber.at(DealerCardNumber.size() - 1)));
				
				// Outputs the hit statement for the dealer along with his updated hand
				DealerHit(DealerCardHand, DealerCardNumber);
			}

			// Once the dealer stands, if the scores are equal they tie
			if (ScoreHand(DealerCardNumber) == ScoreHand(PlayerCardNumber))
			{
				DealerStand(DealerCardHand, DealerCardNumber);
				OutputDealer(DealerCardHand, DealerCardNumber);
				OutputPlayer(PlayerCardHand, PlayerCardNumber);
				cout << "Player and dealer draw. \n";
				return 1;
			}

			// If the dealer's hand is greater than or equal to 18 or his hand is higher than the player's, he will stand
			if ((ScoreHand(DealerCardNumber) >= 18 && ScoreHand(DealerCardNumber) <= 21) || 
				(ScoreHand(DealerCardNumber) > ScoreHand(PlayerCardNumber) && ScoreHand(DealerCardNumber) <= 21))
			{
				DealerStand(DealerCardHand, DealerCardNumber);
			}

			// If the dealer's hand is greater than the player's and less than or equal to 21, he wins
			if (ScoreHand(DealerCardNumber) > ScoreHand(PlayerCardNumber) && ScoreHand(DealerCardNumber) <= 21)
			{
				OutputDealer(DealerCardHand, DealerCardNumber);
				OutputPlayer(PlayerCardHand, PlayerCardNumber);
				cout << "Dealer wins!\n";
				return 1;
			}

			// If the dealer's hand is less than the player's, the player wins
			if (ScoreHand(DealerCardNumber) < ScoreHand(PlayerCardNumber) && ScoreHand(DealerCardNumber) <= 21)
			{
				OutputDealer(DealerCardHand, DealerCardNumber);
				OutputPlayer(PlayerCardHand, PlayerCardNumber);
				cout << "Player wins!\n";
				return 1;
			}

			// If the dealer goes over 21, he busts and the player wins
			if (ScoreHand(DealerCardNumber) > 21)
			{
				cout << "Dealer busts, player wins!\n";
				return 1;
			}
		}
		// Takes the input of the player
		cout << "Hit or stand? ";
		cin >> playerAction;
	}
return 0;
}

// Initializes the cards and sets the intial value to 0 (unassigned) for all of them
void InitializeCards(int playerCard[52])
{
	 playerCard[52] = {0};
}

// Randomly generates a number 0-51 which will correspond to a card in a deck of 52 cards
int GetRandom(int minimumValue, int maximumValue)
{
	int randomCard;
	randomCard = minimumValue + rand() % (maximumValue - minimumValue + 1);
return randomCard;
}

// Takes a randomly generated card and assigns it to either the dealer or player
int DealCard(int playerCard[52], const int player) 
{
	int cardNum = GetRandom(0, 51);

	// Keeps generating a new card if the drawn one is already assigned to someone
	while (playerCard[cardNum] != 0)
	{									
		cardNum = GetRandom(0, 51);     
	}
	playerCard[cardNum] = player;
return cardNum;
}

// Takes the array number of a card and scores it
int ScoreHand(const vector<int> &CardNumber)
{
	int score = 0;
	
		for(int i = 0; i < CardNumber.size(); ++i)
		{
			int tempscore = CardNumber.at(i) / 4;
			tempscore = tempscore % 14;
			if (tempscore > 9)
			{
				tempscore = 10;
			}
			else
			{
				tempscore = tempscore + 1;
			}
			
			score = score + tempscore;
		}
return score;
}

// Takes the array number of a card and converts it into a hand with a card value and suit
string NumToHand(int arrayNumber)
{
	const char suitValues[4] = {'H', 'C', 'D', 'S'};
	const string numberValues[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	int suit, number;	
	string cardSuit, cardNumber, card;

		suit = arrayNumber % 4;
		number = arrayNumber / 4;
		cardSuit = suitValues[suit];
		cardNumber = numberValues[number];
		card = cardNumber + cardSuit;
return card;
}

// The output statement for the dealer, which will output the dealer's current hand whenever called
void OutputDealer(const vector<string> &DealerCardHand, const vector<int> &DealerCardNumber)
{

// Uses a string and combines all of the cards into it for formatting purposes
string combinedcards = DealerCardHand.at(0);

	cout << '\n' << "Dealer has cards: ";
		for (int i = 1; i < DealerCardHand.size(); ++i)
		{
			combinedcards = combinedcards + " " + DealerCardHand.at(i);
		}
	cout << setw(20) << setfill (' ') << left << combinedcards << right << "(" << ScoreHand(DealerCardNumber) << ")" << '\n';
}

// The output statement for the player, which will output his current hand
void OutputPlayer(const vector<string> &PlayerCardHand, const vector<int> &PlayerCardNumber)
{	

// Same concept as the output statement for the dealer, uses a string for formatting
string combinedcards = PlayerCardHand.at(0);

	cout << "You have cards  : ";
		for (int i = 1; i < PlayerCardHand.size(); ++i)
		{
			combinedcards = combinedcards + " " + PlayerCardHand.at(i);
		}
	cout << setw(20) << setfill(' ') << left << combinedcards << right << "(" << ScoreHand(PlayerCardNumber) << ")" << '\n';
}

// The output statement for the dealer whenever he hits, will also output his current hand
void DealerHit(const vector<string> &DealerCardHand, const vector<int> &DealerCardNumber)
{
string combinedcards = DealerCardHand.at(0);

	cout << "Dealer hits     : ";
		for (int i = 1; i < DealerCardHand.size(); ++i)
		{
			combinedcards = combinedcards + " " + DealerCardHand.at(i);
		}
	cout << setw(20) << setfill(' ') << left << combinedcards << right << "(" << ScoreHand(DealerCardNumber) << ")" << '\n';
}

// The output statement for the dealer whenever he stands, outputs current hand
void DealerStand(const vector<string> &DealerCardHand, const vector<int> &DealerCardNumber)
{
string combinedcards = DealerCardHand.at(0);

	cout << "Dealer stands   : ";
		for (int i = 1; i < DealerCardHand.size(); ++i)
		{
			combinedcards = combinedcards + " " + DealerCardHand.at(i);
		}
	cout << setw(20) << setfill(' ') << left << combinedcards << right << "(" << ScoreHand(DealerCardNumber) << ")" << '\n';
}

