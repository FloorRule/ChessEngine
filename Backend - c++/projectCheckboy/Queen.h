#pragma once
#include "ChessTool.h"
#include <iostream>

class Queen : public ChessTool
{
public:
	Queen(Point& position, bool is_black);
	~Queen();
	bool virtual is_valid_move(Point& nextPoint, Board& boad);
	bool move(Point& nextPoint, Board& boad, string& posX, string& posY);

	bool is_valid_move_Rook(Point& nextPoint, Board& board);
	bool is_valid_move_Bishop(Point& nextPoint, Board& board);
	std::string check(Point& nextPoint, Board& boad, string& posX, string& posY);

	std::string rook_check(Point& nextPoint, Board& boad, string& posX, string& posY);
	std::string bishop_check(Point& nextPoint, Board& boad, string& posX, string& posY);
};
