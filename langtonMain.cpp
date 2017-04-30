/*********************************************************************
** Author: ku3nsting
** Date: September 27, 2016
** Description: Assignment 1 - Langton's Ant
*********************************************************************/

#include <iostream>
#include "Matrix.hpp"
#include "Ant.hpp"
#include <stdlib.h>
#include <time.h>
#include "utils.hpp"

using namespace std;

//MAIN METHOD
//includes setup functions and game loop
int main(){
	
//Prototypes for input variables:
int rCoord, cCoord, height, width, choice, moves;

//replay loop bool
bool play = true;
	
//loop all for replayability:
while (play == true){
	
	//updateColor -- keeps track of the color of the present position of the ant. Necessary since the ant moves by overwriting the character previously  occupying its position.
	//startingFacinf -- keeps track of which direction the ant is facing. They are predefined because they are needed for move #1, and do not come from user input.
	bool updateColor = true;
	char startingFacing = 'U';
	
	//MENU to get board dimensions and number of turns from user:
	Menu newMenu(5, 5);
	
	//Menu for replayability:
	Menu endMenu(1, 1);

	//INTRO MESSAGE:
	newMenu.drawMenuHeader("Langton's Ant");
	
	//loop each part of menu until all input is valid

	//menu header:
	newMenu.drawMenuHeader("    SETUP    ");
	
	//Offer the user default or custom values
	bool goodInput = false;
	int custOrDef = 0;
	while (goodInput == false){
		cout << "I.  Would you like to use default values," << endl << "    or define custom ones?" << endl;
		cout << "    The default is a 60 X 60 matrix, 11,000 moves," << endl <<  "    with the ant starting in the center." << endl;
		cout << endl << "    1. Default" << endl;
		cout << "    2. Custom"  << endl;
		cin >> custOrDef;
		//if the input is not an integer, get input again:
		while (newMenu.catchBadInputs()){
			cin >> custOrDef;
		}
		//check to make sure integer is in acceptable range
		if (custOrDef == 1 || custOrDef == 2){
			goodInput = true;
		}
		else{
			cout << endl << "Please give the width as an integer between 1 and 100 units" << endl;
		}
	}
	if (custOrDef == 2){
		//get width from user:
		bool goodInput = false;
		while (goodInput == false){
			cout << "II.  Enter the board width as an integer," << endl << "    and press ENTER:" << endl;
			cin >> width;
			//if the input is not an integer, get input again:
			while (newMenu.catchBadInputs()){
				cin >> width;
			}
			//check to make sure integer is in acceptable range
			if (width > 0 && width <= 1000){
				goodInput = true;
			}
			else{
				cout << endl << "Please give the width as an integer between 1 and 1000 units" << endl;
			}
		}

		//get height from user:
		goodInput = false;
		while (goodInput == false){
			cout << endl << "III.  Enter the board height as an integer," << endl << "    and press ENTER:" << endl;
			cin >> height;
			//if the input is not an integer, get input again:
			while (newMenu.catchBadInputs()){
				cin >> height;
			}
			if (height > 0 && height <= 1000){
				goodInput = true;
			}
			else{
				cout << endl << "Please give the height as an integer between 1 and 1000 units" << endl;
			}
		}

		//get moves from user:
		goodInput = false;
		while (goodInput == false){
			cout << endl << "IV.  How many moves should the ant make?" << endl;
			cout << "    [Try 400 for a cool symmetrical design," << endl;
			cout << "    or 11,000 for a repeating highway.]" << endl; 
			cout << endl << "    Enter your chosen number of moves as an" << endl;
			cout << "    integer, then press ENTER: " << endl;
			cin >> moves;
			//if the input is not an integer, get input again:
			while (newMenu.catchBadInputs()){
				cin >> moves;
			}
			if (moves > 0 && moves < 50000){
				goodInput = true;
			}
			else{
				cout << endl << "Please give the number of moves as an integer between 1 and 50,000 units." << endl;
			}
		}

		//get starting position from user:
		goodInput = false;
		while (goodInput == false){
			cout << endl << "V.  Choose an option for the Ant's starting position," << endl;
			cout << "     then press ENTER:" << endl;
			cout << "1.   Start in the center of the board." << endl;
			cout << "2.   Start in a random position." << endl;
			cout << "3.   Choose custom coordinates."  << endl;

			cin >> choice;
			//if the input is not an integer, get input again:
			while (newMenu.catchBadInputs()){
				cin >> choice;
			}
	
			if (choice == 1){
			//Start ant in the center of the board
			rCoord = ((height -1) / 2);
			cCoord = ((width -1) / 2);
			goodInput = true;
			}
			else if (choice == 2){
			// seed the random number: //
			srand (time(NULL));
			//Start in a random position
			rCoord = (rand() % height + 1);
			cCoord = (rand() % width + 1);
			goodInput = true;
			}
			else if (choice == 3){
			//Input custom coordinates
			bool goodCoords;
			goodCoords = false;
			while (goodCoords == false){
				cout << "Input row position and press ENTER" << endl;
				cin >> rCoord;
				cout << "Input column position and press ENTER" << endl;
				cin >> cCoord;
					if (rCoord >=0 && rCoord <= height && cCoord >= 0 && cCoord <= width){
						goodCoords = true;
						goodInput = true;
					}
				else{
					cout << "Invalid input. Try again." << endl;
				}
				}
			}
			else {
			cout << "Invalid input. Select 1, 2, or 3, and press ENTER." <<endl;
			}
		}
	}
	else if (custOrDef == 1){
		width = 60;
		height = 60;
		moves = 11000;
		rCoord = ((height -1) / 2);
		cCoord = ((width -1) / 2);
	}
	//Initialize the Ant:
	Ant newAnt(rCoord, cCoord, startingFacing);

	//Build the board:
	Matrix newMatrix(width, height);

	//Put the ant object into the board object:
	newMatrix.getAnt(newAnt);

	//Print the board before beginning simulation loop with user-defined ant location:
		//Add the ant to the board data:
	newMatrix.printAnt(rCoord, cCoord);
		//Print the board
	newMatrix.printMatrix(width, height);

	//*********************
	//MAIN SIMULATION LOOP:
	//*********************
	for (int i = 0; i < moves; i++){

	//1. turn the ant
		newAnt.facingAnt(updateColor);
	//2. calculate its next target
		newAnt.positionAnt(height, width);
	//3. change the color of its current square
		newMatrix.antTrail(rCoord, cCoord, updateColor);
	
	//4. get ant target positions
		int r = newAnt.getNextRPosition();
		int c = newAnt.getNextCPosition();

	//5. get color at target matrix position
		updateColor = newMatrix.getColor(r, c);
	
	//6. update ant location
		newAnt.updateAnt(updateColor);

	//7. get new ant positions
		rCoord = newAnt.getRPosition();
		cCoord = newAnt.getCPosition();
		newMatrix.printAnt(rCoord, cCoord);
		newMatrix.printMatrix(width, height);
	}

//When the loop is done, delete the dynamically-created array to release the memory.
	newMatrix.deleteMatrix(height);
	
//run a menu to determine what happens next after the simulation is finished.
	if (endMenu.playAgainMenu() == false){
		play = false;
		}

}
return 0;
}

	

