#include "King.h"
#include <iostream>

King::King(Point& position, bool is_black) 
	:ChessTool(position, is_black ? TOOLS::BLACK_KING : TOOLS::WHITE_KING)
{
}

King::~King()
{
}

bool King::move(Point& nextPoint, Board& boad, string& posX, string& posY)
{
	char temp_char = ' ';
	Point movePos(nextPoint.getPointX() - 1, nextPoint.getPointY() - 1);

	temp_char = boad.get_char_in_board(nextPoint);
	 std::cout << temp_char << " " << this->get_position().getPointX() - 1 << " " << this->get_position().getPointY() - 1 << std::endl;
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
	boad.update_value_in_point(Point(this->get_position().getPointX()-1, this->get_position().getPointY()-1), TOOLS::EMPTY);
	
	this->_position.setX(nextPoint.getPointX());
	this->_position.setY(nextPoint.getPointY());
	if (this->_is_black)
	{
		boad.update_value_in_point(movePos, BLACK_KING);
	}
	else
	{
		boad.update_value_in_point(movePos, WHITE_KING);
	}
	
	return true;
}

std::string King::check(Point& nextPoint, Board& boad, string& posX, string& posY)
{
	int differenceX = 0;
	int differenceY = 0;
	char temp_player = 0;
	int king_x = 0, king_y = 0;
	for (int i = 0; i < posX.length(); i++)
	{
		king_x = posX[i] - '0';
		king_y = posY[i] - '0';
		temp_player = boad.get_char_in_board(Point(king_x, king_y));
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
	if (differenceX == 1 && differenceY == 1 || differenceX == -1 && differenceY == 1 || differenceX == 1 && differenceY == -1)
	{
		return "CHECK";
	}
	else
	{
		return "NOT CHECK";
	}

}



bool King::is_valid_move(Point& nextPoint, Board& boad)
{
	std::cout << boad.is_there_tool(nextPoint)  << true << std::endl;
	for (int i = -1; i < 2; i++)
	{
		//std::cout << i << std::endl;
		//std::cout << this->_position.getPointX() + 1 << " " << this->_position.getPointX() << std::endl;
		//std::cout << nextPoint.getPointX() << " " << nextPoint.getPointY() << std::endl;
		if (this->_position.getPointX() + 1 == nextPoint.getPointX() && this->_position.getPointY() + i == nextPoint.getPointY())
		{
			return true;
		}
		else if (this->_position.getPointX() - 1 == nextPoint.getPointX() && this->_position.getPointY() + i == nextPoint.getPointY())
		{
			return true;
		}
		else if (this->_position.getPointY() - 1 == nextPoint.getPointY() && this->_position.getPointX() + i == nextPoint.getPointX())
		{
			return true;
		}
		else if (this->_position.getPointY() + 1 == nextPoint.getPointY() && this->_position.getPointX() + i == nextPoint.getPointX())
		{
			return true;
		}
		

	}
	return false;
}

