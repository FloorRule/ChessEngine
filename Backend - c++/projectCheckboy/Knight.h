#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "ChessTool.h"
#include <cmath>

#define MOVE_FIRST_LANE 2
#define MOVE_SECOND_LANE 1

class Knight : public ChessTool
{
public:
	Knight(Point& position, bool is_black);
	~Knight();
	bool move(Point& nextPoint, Board& boad, string& posX, string& posY);
	bool virtual is_valid_move(Point& nextPoint, Board& board);

	std::string check(Point& nextPoint, Board& board, string& posX, string& posY);
};

#endif // !__KNIGHT_H__
