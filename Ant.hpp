/*********************************************************************
** Author: ku3nsting
** Date: September 27, 2016
** Description: Assignment 1 - Ant header file
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
private:
	int rPosition, cPosition, nextRPosition, nextCPosition;
	bool color; //white is true and black is false. 
				//The color of the space the ant is stanfing on.
	char facing; //use U, D, L, R for directions
public:
	//constructor
	Ant(int, int, char); //two ints for position
						 //final char for facing
	//print matrix:
	void facingAnt(bool); //update the ant's position
								  //for re-printing
								  //takes positions (ints)
								  //and new color (bool)
	void positionAnt(int, int);
	int getNextRPosition();
	int getNextCPosition();
	int getRPosition();
	int getCPosition();
	void updateAnt(bool);
};



#endif