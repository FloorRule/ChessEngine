#ifndef __PAWN_H__

#define __PAWN_H__

#include "ChessTool.h"
#include "Point.h"

#define FIRST_TURN_DEFAULT_PAWN true //Chess Tool always start at first turn.

class Pawn : public ChessTool
{
    protected:
        //if it's the first turn of the specific pawn.
        bool _first_turn;
    public:
        Pawn(Point Position, bool is_black);
        bool is_first_turn(void) const;
        bool virtual is_valid_move(Point& nextPoint, Board& board);
        bool virtual move(Point& nextPoint, Board& board, string& posX, string& posY);

		std::string check(Point& nextPoint, Board& board, string& posX, string& posY);
};

enum FIRST_TURN_MOVE_PAWN
{
    FIRST_TURN_MOVE_X = 0,
    FIRST_TURN_MOVE_Y = 2,
	B_FIRST_TURN_MOVE_Y = -2
};

enum REGULAR_MOVE_PAWN
{
    REGULAR_MOVE_X = 0,
    REGULAR_MOVE_Y = 1,
	B_REGULAR_MOVE_Y = -1
};

enum EATING_MOVE_PAWN
{
    EATING_MOVE_X = 1,
    EATING_MOVE_Y = 1,
	B_EATING_MOVE_X = -1,
	B_EATING_MOVE_Y = -1
};

#endif __PAWN_H__ //!__PAWN_H__
