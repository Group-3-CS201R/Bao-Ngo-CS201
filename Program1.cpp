// Name: Bao Ngo
// Email: bndbv@mail.umkc.edu
// Class: CS 201R 
// Instructor: Michael Essmyer
// Assignment 1 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//declaring function
int dicerollMethod();
int playerTurn(int humanScore);
int aiTurn(int aiScore);

// Main function
int main() {
	srand(time(0));
	int humanScore = 0; //set human's score to 0
	int aiScore = 0; // set ai's score to 0
	bool k = true;
	bool turn = true; // set turn to P for player turn
	char option = 'Y';
	while (k) {
		cout << "Score you: " << humanScore << "   AI: " << aiScore << endl;
		while (humanScore < 50 && aiScore < 50) {
			if (turn == true) {
				humanScore = playerTurn(humanScore);
				cout << "Score you: " << humanScore << "   AI: " << aiScore << endl;
				turn = false;
			}
			if (turn == false) {
				aiScore = aiTurn(aiScore);
				cout << "Score you: " << humanScore << "   AI: " << aiScore << endl;
				turn = true;
			}
		}
		if (humanScore > 50 || aiScore > 50) {
			k = false;
			break;
		} 
		if (humanScore >= 50) {
			cout << "You win the game   " << "Total point  " << humanScore << endl;
		}
		else {
			cout << "AI win the game  " << "Total point  " << aiScore << endl;
		}
		cout << "Do you want to play again?" << endl;
		cin >> option;
		switch (option) {
		case 'Y':
		case 'y':
			k = true; // set the game to start again
			humanScore = 0;
			aiScore = 0;
			break;
		case 'n':
		case 'N':
			k = false; // out game
			cout << "bye bye" << endl;
			system("pause");
			break;
		default:
			cout << "You have to type y, Y, n, N" << endl;
			cout << "Do you want to play again?" << endl;
			cin >> option;
			break;

		}
	}
	return 0;
}

// Function for rolling the dice

int dicerollMethod() {
	int diceValue;
	diceValue = rand() % 6 + 1;
	return diceValue;
}

// Function for getting player score

int playerTurn(int humanScore) {
	int pot = 0; // set pot to 0
	char choice; // declare variable choice
	cout << endl;
	cout << "Player turn" << endl;
	cin.get(); //Player hits enter to start the game
	while (humanScore < 50) {
		int diceValue = dicerollMethod(); //call dicerollMethod() to get the value of dice.
		if (diceValue == 1) {
			cout << endl;
			cout << "Die Roll  : " << diceValue << " BUST" << endl;
			pot = 0;
			return humanScore;
		}
		else {
			pot += diceValue;
			cout << "Die Roll  : " << diceValue << " Pot: " << pot << " (R)oll again or (H)old ? ";
			cin >> choice;
			while (choice != 'r' && choice != 'h' && choice != 'R' && choice != 'H') {
				cout << "You must enter R or H" << endl;
				cout << "   (R)oll again or (H)old?";
				cin >> choice;
			}
			if (choice == 'H' || choice == 'h') {
				humanScore += diceValue;
				return humanScore;
			}
			else if (choice == 'R' || choice == 'r') {
				humanScore += diceValue;
			}
		}
	}
	return humanScore;
}

// function for getting AI score

int aiTurn(int aiScore) {
	int pot = 0; // set pot to 0
	char option; // declare variable option
	int potAmount = 0;//to calculate the number of pot
	cout << endl;
	cout << "AI turn" << endl;
	cin.get(); //Player hits enter to start the game
	while (potAmount < 20 && aiScore < 50) {
		int diceValue = dicerollMethod(); //call dicerollMethod() to get the value of dice.
		potAmount += 1;
		if (diceValue == 1) {
			cout << endl;
			cout << "Die Roll  : " << diceValue << " BUST" << endl;
			pot = 0;
			return aiScore;
		}
		else {
			pot += diceValue;
			cout << "Die Roll  : " << diceValue << " Pot: " << pot << " (R)oll again or (H)old ? ";
			cin >> option;
			while (option != 'r' && option != 'h' && option != 'R' && option != 'H') {
				cout << "You must enter R or H" << endl;
				cout << "   (R)oll again or (H)old?";
				cin >> option;
			}
			if (option == 'H' || option == 'h') {
				aiScore += diceValue;
				return aiScore;
			}
			else if (option == 'R' || option == 'r') {
				aiScore += diceValue;
			}
		}
	}
	return aiScore;
}

