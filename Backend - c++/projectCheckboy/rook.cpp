#include "rook.h"
#include <iostream>
/*
Constractur.
*/
Rook::Rook(Point& position, bool is_black) 
	: ChessTool(position, is_black ? TOOLS::BLACK_ROOK : TOOLS::WHITE_ROOK)//checks if it's a black rook or white rook.
{

}

bool Rook::is_valid_move(Point& nextPoint, Board& board)
{	
	unsigned char temp_char = 0;
	unsigned int counter = 0;
	int chagne_in_position = 0;
	bool change_in_x = false, negetive_change = false;
	
	int differenceX = nextPoint.getPointX() - this->_position.getPointX();
	int differenceY = nextPoint.getPointY() - this->_position.getPointY();
	std::cout << differenceX << " " << differenceY<< std::endl;
	//if the point is invalid one, or trying to move to the same position.
	if(!board.is_valid_point(nextPoint) )
	{
		return false;
	}
	
	//check if there's a tool.
	else if(board.is_there_tool(nextPoint))
	{
		//if he is about to eat item on the same team.
		if((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
		{
			return false;
		}
	}
	

	for (int i = -7; i < 8; i++)
	{
		if (this->get_position().getPointX() == nextPoint.getPointX() && this->get_position().getPointY() + i == nextPoint.getPointY())
		{
			
			if (differenceY > 0)
			{
				if (differenceY == 1)
				{
					Point point(this->get_position().getPointX(), this->get_position().getPointY()+1);
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					temp_char = board.get_char_in_board(point);
					//if he is about to eat item on the same team.
					if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
					{
						return false;
					}
					return true;
				}
				for (int j = 0; j < differenceY-1; j++)
				{

					Point point(this->get_position().getPointX(), this->get_position().getPointY() + 1+j);
					std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					if (board.is_there_tool(point))
					{
						return false;
					}
				}
				
			}
			else
			{
				if (differenceY == -1)
				{
					Point point(this->get_position().getPointX(), this->get_position().getPointY() - 1);
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					temp_char = board.get_char_in_board(point);
					//if he is about to eat item on the same team.
					if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
					{
						return false;
					}
					return true;
					
				}
				for (int j = 0; j > differenceY+1; j--)
				{
					Point point(this->get_position().getPointX(), this->get_position().getPointY() - 1 + j);
					std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					if (board.is_there_tool(point))
					{
						return false;
					}
				}
				
				
			}
			
			return true;
		}
		if (this->get_position().getPointX() + i == nextPoint.getPointX() && this->get_position().getPointY() == nextPoint.getPointY())
		{
			if (differenceX > 0)
			{
				if (differenceX == 1)
				{
					Point point(this->get_position().getPointX()+1, this->get_position().getPointY());
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					temp_char = board.get_char_in_board(point);
					//if he is about to eat item on the same team.
					if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
					{
						return false;
					}
					return true;
				}
				for (int j = 0; j < differenceX-1; j++)
				{
					Point point(this->get_position().getPointX() + 1 + j, this->get_position().getPointY());
					std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					if (board.is_there_tool(point))
					{
						return false;
					}
				}

			}
			else
			{
				if (differenceX == -1)
				{
					Point point(this->get_position().getPointX()-1, this->get_position().getPointY());
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					temp_char = board.get_char_in_board(point);
					//if he is about to eat item on the same team.
					if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
					{
						return false;
					}
					return true;
				}
				for (int j = 0; j > differenceX+1; j--)
				{
					Point point(this->get_position().getPointX()-1+j, this->get_position().getPointY());
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

bool Rook::move(Point& nextPoint, Board& boad, string& posX, string& posY)
{
	//std::cout << this->check(nextPoint, boad, posX, posY) << std::endl;
	char temp_char = ' ';
	Point movePos(nextPoint.getPointX() - 1, nextPoint.getPointY() - 1);

	temp_char = boad.get_char_in_board(nextPoint);
	// std::cout << temp_char << " " << this->get_position().getPointX() - 1 << " " << this->get_position().getPointY() - 1 << std::endl;
    //if he is about to eat item on the same team.
	
	if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black) )
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
	boad.update_value_in_point(Point(this->get_position().getPointX() - 1, this->get_position().getPointY() - 1), TOOLS::EMPTY);

	this->_position.setX(nextPoint.getPointX());
	this->_position.setY(nextPoint.getPointY());

	this->_is_black ? boad.update_value_in_point(movePos, BLACK_ROOK) : boad.update_value_in_point(movePos, WHITE_ROOK);
	return true;
}

std::string Rook::check(Point& nextPoint, Board& boad, string& posX, string& posY)
{
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
	int differenceX = king_x - nextPoint.getPointX();
	int differenceY = king_y - nextPoint.getPointY();
	//std::cout << differenceX << " " << differenceY << " " << king_x << " " << king_y << std::endl;
	Point kingpos(king_x, king_y);
	
	if (this->is_valid_move(kingpos, boad) && differenceX == 0 || differenceY == 0)
	{
		return "CHECK";
	}
	else
	{
		return "NOT CHECK";
	}
		
	
}
