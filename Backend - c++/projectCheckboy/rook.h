#ifndef __ROOK_H__
#define __ROOK_H__

#include "ChessTool.h"
#include "Board.h"
#include <cmath> //for abs.
#include <cctype> //for islower and isupper.

class Rook : public ChessTool
{
public:
	Rook(Point& position, bool is_black);
	bool virtual is_valid_move(Point& nextPoint, Board& board);
	bool move(Point& nextPoint, Board& boad, string& posX, string& posY);
	std::string check(Point& nextPoint, Board& boad, string& posX, string& posY);
};

#endif //!__ROOK_H__
