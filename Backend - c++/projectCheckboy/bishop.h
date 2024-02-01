#pragma once
#include "ChessTool.h"
#include "Board.h"
#include <cmath> //for abs.
#include <cctype> //for islower and isupper.

class Bishop : public ChessTool
{
public:
	Bishop(Point& position, bool is_black);
	~Bishop();
	bool virtual is_valid_move(Point& nextPoint, Board& board);
	bool move(Point& nextPoint, Board& board, string& posX, string& posY);
	std::string check(Point& nextPoint, Board& board, string& posX, string& posY);

};


