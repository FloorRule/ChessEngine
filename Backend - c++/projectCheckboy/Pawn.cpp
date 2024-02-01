#include "Pawn.h"
#include <iostream>
/*
    Constractur.
*/
Pawn::Pawn(Point Position, bool is_black) : ChessTool(Position, is_black ? TOOLS::BLACK_PAWN : TOOLS::WHITE_PAWN)
{
    this->_first_turn = FIRST_TURN_DEFAULT_PAWN; 
}

/*
If it's the first turn of this specific Pawn.
*/
bool Pawn::is_first_turn(void) const
{
    return this->_first_turn;
}

bool Pawn::is_valid_move(Point& nextPoint, Board& board)
{
    /*
    If moving to the same space or moving to invalid point.
    */
    if(!board.is_valid_point(nextPoint))
    {
        return false;
    }
    else
    {
		if (this->_is_black)
		{
			//Point to store the difference between the 2 points.
			Point difference = Point(nextPoint.getPointX() - this->get_position().getPointX(), nextPoint.getPointY() - this->get_position().getPointY());

			unsigned char temp_char = board.get_char_in_board(nextPoint); //what tool it there in next point.
			//Checks if it isn't eating someting from the same team. Is false if there's nothing there.
			bool about_not_to_eat_from_the_same_team = ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black));
			//If it moved like pawn should move on regular, and also there isn't tool.
			if (difference.getPointX() == REGULAR_MOVE_PAWN::REGULAR_MOVE_X && difference.getPointY() == REGULAR_MOVE_PAWN::B_REGULAR_MOVE_Y && !board.is_there_tool(nextPoint))
			{
				return true;
			}
			//If eating, if it moves right and if there's someting to eat.
			else if (difference.getPointX() == EATING_MOVE_PAWN::B_EATING_MOVE_X && difference.getPointY() == EATING_MOVE_PAWN::B_EATING_MOVE_Y && board.is_there_tool(nextPoint) || difference.getPointX() == EATING_MOVE_PAWN::EATING_MOVE_X && difference.getPointY() == EATING_MOVE_PAWN::B_EATING_MOVE_Y && board.is_there_tool(nextPoint))
			{
				return true;
			}
			//If it's it's first move, also checks if there's nothing in the way.
			else if (this->is_first_turn() && difference.getPointY() == FIRST_TURN_MOVE_PAWN::B_FIRST_TURN_MOVE_Y && difference.getPointX() == FIRST_TURN_MOVE_PAWN::FIRST_TURN_MOVE_X && !board.is_there_tool(nextPoint))// && !board.is_there_tool(Point(nextPoint.getPointX(), nextPoint.getPointY() - 1)))
			{
				Point p(this->get_position().getPointX(), this->get_position().getPointY() - 1);
				char temp_char1 = board.get_char_in_board(p);
				if (temp_char1 != '#')
				{
					return false;
				}
				return true;
			}
			//If none of them.
			else
			{
				return false;
			}
		}
		else
		{
			//Point to store the difference between the 2 points.
			Point difference = Point(nextPoint.getPointX() - this->get_position().getPointX(), nextPoint.getPointY() - this->get_position().getPointY());

			unsigned char temp_char = board.get_char_in_board(nextPoint); //what tool it there in next point.
			//Checks if it isn't eating someting from the same team. Is false if there's nothing there.
			bool about_not_to_eat_from_the_same_team = ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black));
			//If it moved like pawn should move on regular, and also there isn't tool.
			if (difference.getPointX() == REGULAR_MOVE_PAWN::REGULAR_MOVE_X && difference.getPointY() == REGULAR_MOVE_PAWN::REGULAR_MOVE_Y && !board.is_there_tool(nextPoint))
			{
				return true;
			}
			//If eating, if it moves right and if there's someting to eat.
			else if (difference.getPointX() == EATING_MOVE_PAWN::EATING_MOVE_X && difference.getPointY() == EATING_MOVE_PAWN::EATING_MOVE_Y && board.is_there_tool(nextPoint) || difference.getPointX() == EATING_MOVE_PAWN::B_EATING_MOVE_X && difference.getPointY() == EATING_MOVE_PAWN::EATING_MOVE_Y && board.is_there_tool(nextPoint))
			{
				return true;
			}
			//If it's it's first move, also checks if there's nothing in the way.
			else if (this->is_first_turn() && difference.getPointY() == FIRST_TURN_MOVE_PAWN::FIRST_TURN_MOVE_Y && difference.getPointX() == FIRST_TURN_MOVE_PAWN::FIRST_TURN_MOVE_X && !board.is_there_tool(nextPoint)) //&& !board.is_there_tool(Point(nextPoint.getPointX(), nextPoint.getPointY() + 1)))
			{
				Point p(this->get_position().getPointX(), this->get_position().getPointY() + 1);
				char temp_char1 = board.get_char_in_board(p);
				if (temp_char1 != '#')
				{
					return false;
				}
				return true;
			}
			//If none of them.
			else
			{
				return false;
			}
		}
        
        
    }
}

bool Pawn::move(Point& nextPoint, Board& board, string& posX, string& posY)
{
	//std::cout << this->check(nextPoint, board, posX, posY) << std::endl;
	Point movePos(nextPoint.getPointX() - 1, nextPoint.getPointY() - 1);
	Point pastPos(this->get_position().getPointX() - 1, this->get_position().getPointY() - 1);

	char temp_player = 0;
	//if the point is invalid one, or trying to move to the same position.
	if (!board.is_valid_point(nextPoint))
	{
		return false;
	}
	else if (board.is_there_tool(nextPoint))
	{
		temp_player = board.get_char_in_board(nextPoint);
		
		//if he is about to eat item on the same team.
		if ((islower(temp_player) && this->_is_black) || (isupper(temp_player) && !this->_is_black))
		{
			return false;
		}
		else
		{
			
			for (int i = 0; i < posX.length(); i++)
			{
				
				//std::cout << nextPoint.getPointX() << " " << nextPoint.getPointY() << " " << posX[i] << " " << posY[i] << std::endl;
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
	
	board.update_value_in_point(pastPos, TOOLS::EMPTY);
	this->_is_black ? board.update_value_in_point(movePos, BLACK_PAWN) : board.update_value_in_point(movePos, WHITE_PAWN);
    this->_first_turn = false; //After it moved, it isn't it's first turn.
	this->_position = nextPoint; //change position in the tool.
	return true;
	
}

std::string Pawn::check(Point& nextPoint, Board& board, string& posX, string& posY)
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
	Point kingpos(king_x, king_y);
	//std::cout << differenceX << " " << differenceY << " " << king_x << " " << king_y  << " " << this->is_valid_move(kingpos, board) << " " << nextPoint.getPointX() << " " << nextPoint.getPointY() << std::endl;
	//difference.getPointX() == EATING_MOVE_PAWN::B_EATING_MOVE_X && difference.getPointY() == EATING_MOVE_PAWN::B_EATING_MOVE_Y && board.is_there_tool(nextPoint) || difference.getPointX() == EATING_MOVE_PAWN::EATING_MOVE_X && difference.getPointY() == EATING_MOVE_PAWN::B_EATING_MOVE_Y)
	if (differenceX == EATING_MOVE_PAWN::EATING_MOVE_X && differenceY == EATING_MOVE_PAWN::EATING_MOVE_Y || differenceX == EATING_MOVE_PAWN::B_EATING_MOVE_X && differenceY == EATING_MOVE_PAWN::EATING_MOVE_Y)
	{
		return "CHECK";
	}
	else
	{
		return "NOT CHECK";
	}
}
