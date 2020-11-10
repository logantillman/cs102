/* This lab will have the user enter all of the scores in a bowling game and add up all of the scores to determine who is the winner and who did the worst
 * Author: Logan Tillman
 * Date: September 19, 2018 */

#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<string> playerName;
	string tempName;
	vector<int> totalScore;
	int frameNumber = 1; //this keeps track of the framenumber
	int rollValue[21]; //maybe include in for statement
	int i = 0;
	int j = 1;
	int lowScore;	//the int value of the lowest score
	int lowScore_i;	//the i value where the lowest score is located
	int highScore;	//the int value of the highest score
	int highScore_i;	//the i value where the highest score is located

		cout << "Enter player's name (done for no more players): ";
		cin >> tempName;	//tempName is used to determine if the user enters "done" or not

			while (tempName != "done") {
				playerName.push_back(tempName); //when the user enters a name it'll enter the name into the vector
				
				for (frameNumber = 1; frameNumber <= 10; ++frameNumber, i=+2, j=+2); {	//FIXME fix the framenumber and infinite loop
					cout << "Enter score for frame " << frameNumber << ", roll 1: ";	//this is the loop that will enter all of the rolls into the array (at least it's supposed to)
					cin >> rollValue[i];
						if (rollValue[i] == 10) {	//if the user rolls a strike, it'll set the second roll to 0 and enter the next iteration of the loop
							rollValue[j] = 0;
							continue;
						}	
						else {
							cout << "Enter score for frame " << frameNumber << ", roll 2: ";	//this inputs the value for the second roll
							cin >> rollValue[j];

							if (frameNumber == 10) {	//on the 10th frame, it'll have the user input a third frame if they roll a strike or spare
							if (rollValue[i] + rollValue[j] == 10 || rollValue[i] == 10)
								cout << "Enter score for frame 10, roll 3: ";
								cin >> rollValue[21];
							}
						}
				}
			}

			
			if (playerName.size() == 0) {	//if there are no names entered, this statement will execute when the user types done
				cout << "No players were entered." << '\n';
				return 1;
			}

		for (i = 0, j = 1; j <= 21; i=+2, j=+2) {	//this is the counting function for the rollValue array that will add up the scores
			if (rollValue[i] == 10) {	//if the user rolls a strike, it'll add the next 2 rolls to the value
				rollValue[i] = rollValue[i+2] + rollValue[j+2];
			}
			else if (rollValue[i] + rollValue[j] == 10) {	//if the user rolls a spare it'll add the next roll
				rollValue[i] = rollValue[i] + rollValue[j] + rollValue[i+2];
				rollValue[j] = 0;
			}
		}
			
		lowScore = totalScore.at(0); //setting the initial low and high score
		highScore = totalScore.at(0);

		for (i = 0; i < totalScore.size(); ++i) {
			if (totalScore.at(i) < lowScore) {	//checking to find the lowest score in the whole game and will set that value = to lowScore
				lowScore = totalScore.at(i);
				lowScore_i = i;
			}
			if (totalScore.at(i) > highScore) {	//checks to find the high score for the game
				highScore = totalScore.at(i);
				highScore_i = i;
			}
		}

		for (i = 0; i < playerName.size(); ++i) {	//outputs all of the scores for the game
			cout << playerName.at(i) << " scored " << totalScore.at(i) << ".\n";
		}
		
		cout << playerName.at(lowScore_i) << " did the worst by scoring " << lowScore << ".\n"; //outputs the lowest score for the game
		cout << playerName.at(highScore_i) << " won the game by scoring " << highScore << ".\n"; //outputs the highest score for the game

return 0;
}
