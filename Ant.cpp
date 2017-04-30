/*********************************************************************
** Author: ku3nsting
** Date: September 27, 2016
** Description: Assignment 1 - Ant implementation file
*********************************************************************/

#include <iostream>
#include "Ant.hpp"

using namespace std;

Ant::Ant(int r, int c, char f){
	rPosition = r;
	cPosition = c;
	nextRPosition = 0;
	nextCPosition = 0;
	facing = f;
	color = true;
}

//Update which direction the ant is facing
//based on its current facing value and the
//color of the square it's occupying
void Ant::facingAnt(bool newColor){
	color = newColor;
	//ant is on a white square
	if (color == true){
		if (facing == 'U'){
			facing = 'R';
		}
		else if (facing == 'D'){
			facing = 'L';
		}
		else if (facing == 'L'){
			facing = 'U';
		}
		else{
			facing = 'D';
		}
	}
	//ant is on a black square
	else if (color == false){
		if (facing == 'U'){
			facing = 'L';
		}
		else if (facing == 'D'){
			facing = 'R';
		}
		else if (facing == 'L'){
			facing = 'D';
		}
		else{
			facing = 'U';
		}
	}
}

//Calculate the Ant's next position based on its current
//position and the direction it's facing
void Ant::positionAnt(int h, int w){
	if (facing == 'U'){
		if (rPosition > 0){
			nextRPosition = (rPosition - 1);
		}
		else{
			nextRPosition = (h - 1);
		}
		nextCPosition = cPosition;
	}
	else if (facing == 'D'){
		if (rPosition < (h - 1)){
			nextRPosition = (rPosition + 1);
		}
		else{
			nextRPosition = 0;
		}
		nextCPosition = cPosition;
	}
	else if (facing == 'L'){
		if (cPosition > 0){
			nextCPosition = (cPosition - 1);
		}
		else{
			nextCPosition = (w - 1);
		}
		nextRPosition = rPosition;
	}
	else{
		if (cPosition < (w-1)){
			nextCPosition = (cPosition + 1);
		}
		else{
			nextCPosition = 0;
		}
		nextRPosition = rPosition;	
	}
}

int Ant::getNextRPosition(){
	return nextRPosition;
}
int Ant::getNextCPosition(){
	return nextCPosition;
}

int Ant::getRPosition(){
	return rPosition;
}
int Ant::getCPosition(){
	return cPosition;
}

void Ant::updateAnt(bool c){
	rPosition = nextRPosition;
	cPosition = nextCPosition;
	color = c;
}