#ifndef  __BOARD_H__

#define __BOARD_H__

#define DEFAULT_NUM_TOOLS 32

#include "Point.h"
#include <string>
#include <cstdio> //for size_t

using std::string;

enum TOOLS
{
	WHITE_KING = 'K',
	WHITE_QUEEN = 'Q',
	WHITE_ROOK = 'R',
	WHITE_KNIGHT = 'N',
	WHITE_BISHOP = 'B',
	WHITE_PAWN = 'P',
	BLACK_KING = 'k',
	BLACK_QUEEN = 'q',
	BLACK_ROOK = 'r',
	BLACK_KNIGHT = 'n',
	BLACK_BISHOP = 'b',
	BLACK_PAWN = 'p',
	EMPTY = '#'
};

class ChessTool;
class Board
{
protected:
	string _base_board[8];
	unsigned int _offset;

public:
	Board(string base_board[], unsigned int offset);
	string* get_board();
	unsigned char get_char_in_board(Point dest) const;
	//unsigned char get_char_in_board(const Point& dest) const;
	unsigned char get_char_in_board(size_t destx, size_t desty) const;
	bool update_value_in_point(Point dest, unsigned char new_value);
	//bool update_value_in_point(const Point& dest, unsigned char new_value);
	bool update_value_in_point(size_t destx, size_t desty, unsigned char new_value);
	bool is_there_tool(Point dest);
	bool is_there_tool(size_t destx, size_t desty);
	bool is_valid_point(Point& dest) const;
	bool is_valid_point(size_t destx, size_t desty) const;
	int convert_point_to_index_in_board(Point& dest) const;
	static bool is_chess_tool(unsigned char chess_tool);
	void wordsToNums(string& point);
	unsigned char get_char_in_board2(Point dest) const;
};

#endif // ! __BOARD_H__
