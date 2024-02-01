#include "Knight.h"
#include <iostream>
/*
Constractur.
*/
Knight::Knight(Point& position, bool is_black) 
	: ChessTool(position, is_black ? TOOLS::BLACK_KNIGHT : TOOLS::WHITE_KNIGHT)
{

}

Knight::~Knight()
{
}

bool Knight::move(Point& nextPoint, Board& boad, string& posX, string& posY)
{
	
	//std::cout << this->check(nextPoint, boad, posX, posY) << std::endl;
	char temp_char = ' ';
	Point movePos(nextPoint.getPointX() - 1, nextPoint.getPointY() - 1);
	Point pastPos(this->get_position().getPointX() - 1, this->get_position().getPointY() - 1);

	temp_char = boad.get_char_in_board(nextPoint);
	//std::cout << temp_char << " " << this->get_position().getPointX() - 1 << " " << this->get_position().getPointY() - 1 << std::endl;
	//if he is about to eat item on the same team.
	
	

	if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < posX.length(); i++)
		{
			int x = posX[i] - '0';
			int y = posY[i] - '0';
			if (nextPoint.getPointX() == x && nextPoint.getPointY() == y)
			{

				posX[i] = 'X';
				posY[i] = 'Y';
			}
		}
	}


	this->_position.setX(nextPoint.getPointX());
	this->_position.setY(nextPoint.getPointY());

	boad.update_value_in_point(pastPos, TOOLS::EMPTY);

	this->_is_black ? boad.update_value_in_point(movePos, BLACK_KNIGHT) : boad.update_value_in_point(movePos, WHITE_KNIGHT);
	return true;
}

/*
Check if the knight can go to nextPoint in the board.
*/
bool Knight::is_valid_move(Point& nextPoint, Board& board)
{
	int differenceX = nextPoint.getPointX() - this->_position.getPointX();
	int differenceY = nextPoint.getPointY() - this->_position.getPointY();

	if (differenceX == 2 && differenceY == 1 || differenceX == 2 && differenceY == -1)
	{
		Point point(this->get_position().getPointX() + 1, this->get_position().getPointY());
		if (board.is_there_tool(point))
		{
			//return false;
		}
	}
	else if (differenceX == -2 && differenceY == 1 || differenceX == -2 && differenceY == -1)
	{
		Point point(this->get_position().getPointX() - 1, this->get_position().getPointY());
		if (board.is_there_tool(point))
		{
			//return false;
		}
	}
	else if (differenceX == 1 && differenceY == 2 || differenceX == -1 && differenceY == 2)
	{
		Point point(this->get_position().getPointX(), this->get_position().getPointY() + 1);
		if (board.is_there_tool(point))
		{
			//return false;
		}
	}
	else if (differenceX == 1 && differenceY == -2 || differenceX == -1 && differenceY == -2)
	{
		Point point(this->get_position().getPointX(), this->get_position().getPointY() - 1);
		if (board.is_there_tool(point))
		{
			//return false;
		}
	}

	//If it want it to move to the same position, or the next point is invalid one.
	if (!board.is_valid_point(nextPoint))
	{
		return false;
	}
	//point that will have the difference between the 2 points.
	Point difference = Point(abs((int)this->_position.getPointX() - (int)nextPoint.getPointX()), abs((int)this->_position.getPointY() - (int)nextPoint.getPointY()));
	//if it moved like knight should move.
										//3											1
	if ((difference.getPointX() == MOVE_FIRST_LANE && difference.getPointY() == MOVE_SECOND_LANE) || (difference.getPointY() == MOVE_FIRST_LANE && difference.getPointX() == MOVE_SECOND_LANE))
	{
		//if ther's a tool.
		/*
		if (board.is_there_tool(nextPoint))
		{
			return false;
		}
		else
		{
			return true;
		}
		*/
		return true;
	}
	return false;
}

std::string Knight::check(Point& nextPoint, Board& board, string& posX, string& posY)
{
	int differenceX = 0;
	int differenceY = 0;
	char temp_player = 0;
	int king_x = 0, king_y = 0;
	for (int i = 0; i < posX.length(); i++)
	{
		king_x = posX[i] - '0';
		king_y = posY[i] - '0';
		temp_player = board.get_char_in_board(Point(king_x, king_y));
		if (this->_is_black)
		{
			if (temp_player == 'K')
			{
				i = posX.length();
			}
		}
		else
		{
			if (temp_player == 'k')
			{
				i = posX.length();
			}
		}
		//this->_is_black ? temp_player == 'K' ? i = posX.length() : NULL : temp_player == 'k' ? i = posX.length() : NULL;
	}
	if (this->_is_black)
	{
		differenceX = nextPoint.getPointX() - king_x;
		differenceY = nextPoint.getPointY() - king_y;
	}
	else
	{
		differenceX = king_x - nextPoint.getPointX();
		differenceY = king_y - nextPoint.getPointY();
	}
	//std::cout << differenceX << " " << differenceY << " " << king_x << " " << king_y << std::endl;
	Point kingpos(king_x, king_y);


	if (differenceX == 2 && differenceY == 1 || differenceX == 2 && differenceY == -1)
	{
		return "CHECK";
	}
	else if (differenceX == -2 && differenceY == 1 || differenceX == -2 && differenceY == -1)
	{
		return "CHECK";
	}
	else if (differenceX == 1 && differenceY == 2 || differenceX == -1 && differenceY == 2)
	{
		return "CHECK";
	}
	else if (differenceX == 1 && differenceY == -2 || differenceX == -1 && differenceY == -2)
	{
		return "CHECK";
	}
	else
	{
		return "NOT CHECK";
	}


}
