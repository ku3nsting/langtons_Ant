/*********************************************************************
** Author: ku3nsting
** Date: September 27, 2016
** Description: Assignment 1 - Matrix header file
*********************************************************************/

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Ant.hpp"

class Matrix
{
private:
	int width, height;
	char** boardMatrix;
	Ant* boardAnt;
public:
	//constructor
	Matrix(int, int);
	void getAnt(Ant); //put the ant into the matrix
	//print matrix:
	void printMatrix(int, int);
	//get color from specific coords
	bool getColor(int, int);
	//add ant to matrix for next printing
	void printAnt(int, int);
	//color the square the ant has left
	void antTrail(int r, int c, bool);
	void deleteMatrix(int);
};


#endif