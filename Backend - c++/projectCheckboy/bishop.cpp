#include "bishop.h"
#include <iostream>

Bishop::Bishop(Point& position, bool is_black)
	: ChessTool(position, is_black ? TOOLS::BLACK_BISHOP : TOOLS::WHITE_BISHOP)
{

}

Bishop::~Bishop()
{
}


bool Bishop::is_valid_move(Point& nextPoint, Board& board)
{
	int differenceX = nextPoint.getPointX() - this->_position.getPointX();
	int differenceY = nextPoint.getPointY() - this->_position.getPointY();

	for (int i = 0; i < 8; i++)
	{
		if (this->get_position().getPointX() + i == nextPoint.getPointX() && this->get_position().getPointY() + i == nextPoint.getPointY())
		{
			if (differenceX > 0 && differenceY > 0)
			{
				
				for (int j = 0; j < differenceX-1; j++)
				{
					Point point(this->get_position().getPointX() + 1 + j, this->get_position().getPointY() + 1 + j);
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					if (board.is_there_tool(point))
					{
						return false;
					}
				}
			}
			return true;
		}
		if (this->get_position().getPointX() + i == nextPoint.getPointX() && this->get_position().getPointY() - i == nextPoint.getPointY())
		{
			if (differenceX > 0 && differenceY < 0)
			{
				for (int j = 0; j < differenceX - 1; j++)
				{
					Point point(this->get_position().getPointX() + 1 + j, this->get_position().getPointY() - 1 - j);
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					if (board.is_there_tool(point))
					{
						return false;
					}
				}
			}
			return true;
		}
		if (this->get_position().getPointX() - i == nextPoint.getPointX() && this->get_position().getPointY() + i == nextPoint.getPointY())
		{
			if (differenceX < 0 && differenceY > 0)
			{
				
				for (int j = 0; j < differenceY - 1; j++)
				{
					Point point(this->get_position().getPointX() - 1 - j, this->get_position().getPointY() + 1 + j);
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					if (board.is_there_tool(point))
					{
						return false;
					}
				}
			}
			return true;
		}
		if (this->get_position().getPointX() - i == nextPoint.getPointX() && this->get_position().getPointY() - i == nextPoint.getPointY())
		{
			if (differenceX < 0 && differenceY < 0)
			{
				for (int j = 0; j > differenceY + 1; j--)
				{
					Point point(this->get_position().getPointX()-1 + j, this->get_position().getPointY()-1  + j);
					std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					if (board.is_there_tool(point))
					{
						return false;
					}
				}
			}
			return true;
		}
	}
	
	return false;
}

bool Bishop::move(Point& nextPoint, Board& board, string& posX, string& posY)
{
	//std::cout << this->check(nextPoint, board, posX, posY) << std::endl;

	Point movePos(nextPoint.getPointX() - 1, nextPoint.getPointY() - 1);
	Point pastPos(this->get_position().getPointX() - 1, this->get_position().getPointY() - 1);
	bool isPosMov = false;
	char temp_player = 0;

	//char temp_player = 0;
	//if the point is invalid one, or trying to move to the same position.
	if (!board.is_valid_point(nextPoint))
	{
		return false;
	}
	else if (board.is_there_tool(nextPoint))
	{
		temp_player = board.get_char_in_board(nextPoint);
		std::cout << temp_player << std::endl;
		//if he is about to eat item on the same team.
		if ((islower(temp_player) && this->_is_black) || (isupper(temp_player) && !this->_is_black))
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
	}

	while (nextPoint.getPointX() != this->_position.getPointX() && nextPoint.getPointY() != this->_position.getPointY())
	{
		isPosMov = true;
		if (this->_position.getPointX() > nextPoint.getPointX())
		{
			this->_position.setX(this->_position.getPointX() - 1);
		}
		else if(this->_position.getPointX() < nextPoint.getPointX())
		{
			this->_position.setX(this->_position.getPointX() + 1);
		}
		if (this->_position.getPointY() > nextPoint.getPointY())
		{
			this->_position.setY(this->_position.getPointY() - 1);
		}
		else if(this->_position.getPointY() < nextPoint.getPointY())
		{
			this->_position.setY(this->_position.getPointY() + 1);
		}
		
	}
	if (isPosMov)
	{
		board.update_value_in_point(pastPos, TOOLS::EMPTY);
		this->_is_black ? board.update_value_in_point(movePos, BLACK_BISHOP) : board.update_value_in_point(movePos, WHITE_BISHOP);
		//board.update_value_in_point(movePos, WHITE_BISHOP);
	}
	
	return isPosMov;
}

std::string Bishop::check(Point& nextPoint, Board& board, string& posX, string& posY)
{
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
	int differenceX = king_x - nextPoint.getPointX();
	int differenceY = king_y - nextPoint.getPointY();
	//std::cout << differenceX << " " << differenceY << " " << king_x << " " << king_y << std::endl;
	Point kingpos(king_x, king_y);
	if (differenceX == differenceY || differenceX * -1 == differenceY || differenceX == differenceY * -1 || differenceX * -1 == differenceY * -1 && this->is_valid_move(kingpos, board))
	{
		return "CHECK";
	}
	else
	{
		return "NOT CHECK";
	}
	
}
