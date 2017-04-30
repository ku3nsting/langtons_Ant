/*********************************************************************
** Date: September 27, 2016
** Description: 162 - Utils implementation file
*********************************************************************/

#include <iostream>
#include "utils.hpp"
#include <string>

using namespace std;

//Menu constructor
Menu::Menu(int opt, int input){
	options = opt;
	goodInputs = input;
}

//Menu header function
void Menu::drawMenuHeader(string title){
	cout << endl << "* * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * *      " << title << "      * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * *" << endl << endl;
}

//Catch bad data type function
bool Menu::catchBadInputs(){
	if(cin.fail()){
		cout << "Invalid input. Try again" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		return true;
	}
	else{
		return false;
	}
}

//play again conclusion menu
bool Menu::playAgainMenu(){
	cout << "Would you like to repeat the simulation?" << endl;
	cout << "1. Yes, begin again with new values" << endl;
	cout << "2. No, exit program" << endl;
	
	int conclusionDecision;
	cin >> conclusionDecision;
	while (catchBadInputs()){
		cin >> conclusionDecision;
	}
	if (conclusionDecision == 1){
		return true;
	}
	else if (conclusionDecision == 2){
		cout << endl << "Thanks! Bye!" << endl;
		return false;
	}
	else{
		cout << "Invalid choice. Try again.";
	}
}