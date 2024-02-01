#ifndef __CHESS_TOOL_H__

#define __CHESS_TOOL_H__

#include "Point.h"
#include "Board.h"

class ChessTool
{
protected:
	bool _is_black;
	Point _position;
	unsigned char _type;
	bool _is_Castling;

public:
	ChessTool(Point& position, unsigned char type);
	
	Point get_position() const;
	unsigned char get_type() const;

	void setColor(bool is_black);//?
	//bool is_checkmate(int check, Board& boad);
	/*
	Move the tool to the nextPoint in the board.
	*/
	//bool move(Point& nextPoint, Board& board);
	bool virtual move(Point& nextPoint, Board& boad, string& posX, string& posY) = 0;

	virtual std::string check(Point& nextPoint, Board& boad, string& posX, string& posY) = 0;
	
	/*
	Checks if a move to nextPoint on the board is a valid one.
	*/
	bool virtual is_valid_move(Point& nextPoint, Board& board) = 0;
	/*
	Checks if the tool is in the black team.
	*/
	bool is_black_team() const;
};

#endif // !__CHESS_TOOL_H__
