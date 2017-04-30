/*********************************************************************
** Author: ku3nsting
** Date: September 27, 2016
** Description: Assignment 1 - Matrix header file
*********************************************************************/

#include <iostream>
#include "Matrix.hpp"
using namespace std;

//constructor
Matrix::Matrix(int w, int h){
	width = w;
	height = h;
	
	//build the matrix to represent the board
	boardMatrix = new char*[height];
	for(int i = 0; i < height; i++){
		boardMatrix[i] = new char[width];
	}
	//write blank values in the matrix
	//Blank space placeholder
	char blank = ' ';
	for (int i = 0; i < height; i++){
		for (int x = 0; x < width; x++){
			boardMatrix[i][x] = blank;
		}
	}
}

//put the ant into the matrix
void Matrix::getAnt(Ant a){
	boardAnt = &a;
}

//print function
void Matrix::printMatrix(int width, int height){
	//top border:
	for (int i = 0; i < (width); i++){
		cout << "-";
	}
	cout << endl;
	//board:
	for (int j = 0; j < height; j++){
		for (int x = 0; x < width; x++){
			cout << boardMatrix[j][x]; 
			}
		cout << endl;
		}
	//bottom border:
	for (int k = 0; k < (width); k++){
		cout << "-";
	}
	cout << endl;
}

//deleteMatrix function
void Matrix::deleteMatrix(int rowHeight){
	for(int i = 0; i < rowHeight; i++) {
		delete[] boardMatrix[i];
	}
	delete[] boardMatrix;
	}

//get color from specific coords
bool Matrix::getColor(int r, int c){
	if (boardMatrix[r][c] == ' '){
		return true;
	}
	if (boardMatrix[r][c] == '#'){
		return false;
	}
}

//color the ant's trail
void Matrix::antTrail(int r, int c, bool currentColor){
	if (currentColor == true){
		boardMatrix[r][c] = '#';
	}
	else{
		boardMatrix[r][c] = ' ';
	}
}

//print the ant on the matrix
void Matrix::printAnt(int r, int c){
	boardMatrix[r][c] = '*';
}