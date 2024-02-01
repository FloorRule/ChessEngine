#include "ChessTool.h"

/*
Constractur.
Point position - the position of the tool. WARNING! It doesn't check if the position is valid on the board.
unsigned char type - the type of tool.
*/
ChessTool::ChessTool(Point& position, unsigned char type)
{
	this->_position = position;
	this->_type = type;
	this->_is_black = islower(type);
	this->_is_Castling = false;
}

/*
Set color of the tool.
*/
void ChessTool::setColor(bool is_black)
{
	this->_is_black = is_black;
}

/*
TODO.
Move the tool to nextPoint in the board.
*/
bool ChessTool::move(Point& nextPoint, Board& board, string& posX, string& posY)
{
	if (this->is_valid_move(nextPoint, board))
	{
		board.update_value_in_point(this->get_position(), TOOLS::EMPTY); //Update his previous position to EMPTY.
		board.update_value_in_point(nextPoint, this->get_type()); //Update next position to his type.
		this->_position = nextPoint; //change position in the tool.
		return true;
	}
	return false;
}

/*
Return if the tool is in black team or white team.
*/
bool ChessTool::is_black_team() const
{
	return this->_is_black;
}

/*
bool ChessTool::is_checkmate(int check, Board& boad)
{
	char temp_char = 0;
	for (int i = -1; i < 2; i++)
	{
		try
		{
			Point a(this->_position.getPointX() + 1, this->_position.getPointY() + i);
			temp_char = boad.get_char_in_board(a);
			if ((islower(temp_char) && !this->_is_black) || (isupper(temp_char) && this->_is_black))
			{
				return false;
			}
		}
		catch (...)
		{

		}
			

		
		Point b(this->_position.getPointX() - 1, this->_position.getPointY() + i);
		temp_char = boad.get_char_in_board(b);

		if ((islower(temp_char) && !this->_is_black) || (isupper(temp_char) && this->_is_black))
		{
			return false;
		}
		Point c(this->_position.getPointX() + i, this->_position.getPointY() - 1);
		temp_char = boad.get_char_in_board(c);

		if ((islower(temp_char) && !this->_is_black) || (isupper(temp_char) && this->_is_black))
		{
			return false;
		}
		Point d(this->_position.getPointX() + i, this->_position.getPointY() + 1);
		temp_char = boad.get_char_in_board(d);

		if ((islower(temp_char) && !this->_is_black) || (isupper(temp_char) && this->_is_black))
		{
			return false;
		}
	}
	if (check)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

/*
Get the position of the tool.
*/
Point ChessTool::get_position() const
{
	return this->_position;
}

unsigned char ChessTool::get_type() const
{
	return this->_type;
}
