#include "Board.h"
#include <iostream>
/*
Constractur.
*/
Board::Board(string base_board[], unsigned int offset)
{
	for (int i = 0; i < 8; i++)
	{
		this->_base_board[i] = base_board[i];
	}
	this->_offset = offset;
}

/*
Get the whole board as string.
*/
string* Board::get_board()
{
	return this->_base_board;
}


void Board::wordsToNums(string& point)
{
	string abc = "abcdefgh";
	string num = "12345678";
	for (int i = 0; i < 8; i++)
	{
		if (point[0] == abc[i])
		{
			point[0] = num[i];
		}
		if (point[2] == abc[i])
		{
			point[2] = num[i];
		}
	}

}


/*
This function gets a char in board.
*/
unsigned char Board::get_char_in_board(Point dest) const
{
	if (this->is_valid_point(dest))
	{
		//return this->_base_board[this->convert_point_to_index_in_board(dest)];
		if (dest.getPointY() == 0)
		{
			return this->_base_board[dest.getPointY()][dest.getPointX() - 1];
		}
		else
		{
			return this->_base_board[dest.getPointY() - 1][dest.getPointX() - 1];
		}
		
	}
	else
	{
		//TODO.
	}
}

/*
This function gets a char in board.
*/
unsigned char Board::get_char_in_board2(Point dest) const
{
	if (this->is_valid_point(dest))
	{
		//return this->_base_board[this->convert_point_to_index_in_board(dest)];
		return this->_base_board[dest.getPointY()][dest.getPointX()];
	}
	else
	{
		//TODO.
	}
}

/*
This function gets a char in board.
*/
unsigned char Board::get_char_in_board(size_t destx ,size_t desty) const
{
	if (this->is_valid_point(destx, desty))
	{
		//return this->_base_board[dest];
		return this->_base_board[desty][destx];
	}
	else
	{
		//TODO.
	}
}

/*
This function updates a specific value in the board.
*/
bool Board::update_value_in_point(Point dest, unsigned char new_value)
{
	if (this->is_valid_point(dest) && (this->is_chess_tool(new_value) || new_value == TOOLS::EMPTY))
	{
		//this->_base_board[this->convert_point_to_index_in_board(dest)] = new_value;
		//std::cout << this->_base_board[dest.getPointY()][dest.getPointX()] << " " << new_value << std::endl;
		this->_base_board[dest.getPointY()][dest.getPointX()] = new_value;
		return true;
	}
	return false;
}

bool Board::update_value_in_point(size_t destx,size_t desty, unsigned char new_value)
{
	if (this->is_valid_point(destx, desty) && (this->is_chess_tool(new_value) || new_value == TOOLS::EMPTY))
	{
		this->_base_board[desty][destx] = new_value;
		return true;
	}
	return false;
}

/*
Checks if in dest there's a chess tool.
*/
bool Board::is_there_tool(Point dest)
{
	if (this->is_valid_point(dest))
	{
		return this->is_chess_tool(this->get_char_in_board(dest));
	}
	return false;
}

/*
Checks if in dest there's a chess tool.
*/
bool Board::is_there_tool(size_t destx,size_t desty)
{
	if (this->is_valid_point(destx, desty))
	{
		return this->is_chess_tool(this->get_char_in_board(destx, desty));
	}
	return false;
}

/*
Check if position is in the board.
*/
bool Board::is_valid_point(Point& dest) const
{
	//return this->convert_point_to_index_in_board(dest) <= this->get_board().length();
	return dest.getPointY() <= 8 && dest.getPointY() >= 0 && dest.getPointX() <= 8 && dest.getPointX() >= 0;
}

/*
Check if position is in the board.
*/
bool Board::is_valid_point(size_t destx, size_t desty) const
{
	return destx < 8 && destx >= 0 && desty < 8 && desty >= 0;
}

/*
This function convert an point (x, y) to index in the board.
*/
int Board::convert_point_to_index_in_board(Point& dest) const
{
	return dest.getPointX() + (dest.getPointY() * this->_offset);
}

/*
Check if a tool is a chess tool.
*/
bool Board::is_chess_tool(unsigned char chess_tool)
{
	bool is_tool = false;

	//if it's empty.
	if (chess_tool == TOOLS::EMPTY)
	{
		return false;
	}

	//if it's a bishop.
	is_tool = is_tool || chess_tool == TOOLS::BLACK_BISHOP || chess_tool == TOOLS::WHITE_BISHOP;

	//if it's a king.
	is_tool = is_tool || chess_tool == TOOLS::BLACK_KING || chess_tool == TOOLS::WHITE_KING;

	//if it's a knight.
	is_tool = is_tool || chess_tool == TOOLS::BLACK_KNIGHT || chess_tool == TOOLS::WHITE_KNIGHT;

	//if it's a pawn.
	is_tool = is_tool || chess_tool == TOOLS::BLACK_PAWN || chess_tool == TOOLS::WHITE_PAWN;

	//if it's a queen.
	is_tool = is_tool || chess_tool == TOOLS::BLACK_QUEEN || chess_tool == TOOLS::WHITE_QUEEN;
	
	//if it's a rook.
	is_tool = is_tool || chess_tool == TOOLS::BLACK_ROOK || chess_tool == TOOLS::WHITE_ROOK;

	return is_tool;
}
