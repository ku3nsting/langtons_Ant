/*********************************************************************
** Date: September 27, 2016
** Description: 162 - Utils header file
*********************************************************************/

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

class Menu
{
private:
	int options;
	int goodInputs;
public:
//Menu constructor
Menu(int, int);

//Menu header function
void drawMenuHeader(std::string);

//catch bad inputs function
bool catchBadInputs();

//play again conclusion menu
bool playAgainMenu();
};

#endif