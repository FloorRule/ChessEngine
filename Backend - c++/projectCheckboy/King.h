#pragma once
#include "ChessTool.h"
#include <iostream>


class King : public ChessTool
{
public:
	King(Point& position, bool is_black);
	~King();
	bool virtual is_valid_move(Point& nextPoint, Board& boad);
	bool move(Point& nextPoint, Board& boad, string& posX, string& posY);
	std::string check(Point& nextPoint, Board& boad, string& posX, string& posY);

	//bool is_checkmate(int check, Board& boad);

};
