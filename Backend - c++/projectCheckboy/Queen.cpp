#include "Queen.h"

Queen::Queen(Point& position, bool is_black)
	:ChessTool(position, is_black ? TOOLS::BLACK_QUEEN : TOOLS::WHITE_QUEEN)
{
}

Queen::~Queen()
{
}

bool Queen::is_valid_move(Point& nextPoint, Board& boad)
{
	if (this->is_valid_move_Bishop(nextPoint, boad) || this->is_valid_move_Rook(nextPoint, boad))
	{
		return true;
	}
	return false;
}


bool Queen::move(Point& nextPoint, Board& boad, string& posX, string& posY)
{
	Point movePos(nextPoint.getPointX() - 1, nextPoint.getPointY() - 1);
	Point pastPos(this->get_position().getPointX() - 1, this->get_position().getPointY() - 1);

	char temp_player = 0;
	//if the point is invalid one, or trying to move to the same position.
	if (!boad.is_valid_point(nextPoint))
	{
		return false;
	}
	else if (boad.is_there_tool(nextPoint))
	{
		temp_player = boad.get_char_in_board(nextPoint);
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

	this->_position.setX(nextPoint.getPointX());
	this->_position.setY(nextPoint.getPointY());

	boad.update_value_in_point(pastPos, TOOLS::EMPTY);
	this->_is_black ? boad.update_value_in_point(movePos, BLACK_QUEEN) : boad.update_value_in_point(movePos, WHITE_QUEEN);
	return true;
}

bool Queen::is_valid_move_Rook(Point& nextPoint, Board& board)
{
	unsigned char temp_char = 0;
	unsigned int counter = 0;
	int chagne_in_position = 0;
	bool change_in_x = false, negetive_change = false;

	int differenceX = nextPoint.getPointX() - this->_position.getPointX();
	int differenceY = nextPoint.getPointY() - this->_position.getPointY();
	std::cout << differenceX << " " << differenceY << std::endl;
	//if the point is invalid one, or trying to move to the same position.
	if (!board.is_valid_point(nextPoint))
	{
		return false;
	}

	//check if there's a tool.
	else if (board.is_there_tool(nextPoint))
	{
		temp_char = board.get_char_in_board(nextPoint);
		//if he is about to eat item on the same team.
		if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
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
					Point point(this->get_position().getPointX(), this->get_position().getPointY() + 1);
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					temp_char = board.get_char_in_board(point);
					//if he is about to eat item on the same team.
					if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
					{
						return false;
					}
					return true;
				}
				for (int j = 0; j < differenceY - 1; j++)
				{

					Point point(this->get_position().getPointX(), this->get_position().getPointY() + 1 + j);
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
				for (int j = 0; j > differenceY + 1; j--)
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
					Point point(this->get_position().getPointX() + 1, this->get_position().getPointY());
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					temp_char = board.get_char_in_board(point);
					//if he is about to eat item on the same team.
					if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
					{
						return false;
					}
					return true;
				}
				for (int j = 0; j < differenceX - 1; j++)
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
					Point point(this->get_position().getPointX() - 1, this->get_position().getPointY());
					//std::cout << board.is_there_tool(point) << " " << point.getPointX() << " " << point.getPointY() << std::endl;
					temp_char = board.get_char_in_board(point);
					//if he is about to eat item on the same team.
					if ((islower(temp_char) && this->_is_black) || (isupper(temp_char) && !this->_is_black))
					{
						return false;
					}
					return true;
				}
				for (int j = 0; j > differenceX + 1; j--)
				{
					Point point(this->get_position().getPointX() - 1 + j, this->get_position().getPointY());
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

bool Queen::is_valid_move_Bishop(Point& nextPoint, Board& board)
{
	int differenceX = nextPoint.getPointX() - this->_position.getPointX();
	int differenceY = nextPoint.getPointY() - this->_position.getPointY();

	for (int i = 0; i < 8; i++)
	{
		if (this->get_position().getPointX() + i == nextPoint.getPointX() && this->get_position().getPointY() + i == nextPoint.getPointY())
		{
			if (differenceX > 0 && differenceY > 0)
			{
				for (int j = 0; j < differenceX - 1; j++)
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
					Point point(this->get_position().getPointX() - 1 + j, this->get_position().getPointY() - 1 + j);
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

std::string Queen::check(Point& nextPoint, Board& boad, string& posX, string& posY)
{
	if (this->bishop_check(nextPoint, boad, posX, posY) == "CHECK" || this->rook_check(nextPoint, boad, posX, posY) == "CHECK")
	{
		return "CHECK";
	}
	else
	{
		return "NO CHECK";
	}
}

std::string Queen::rook_check(Point& nextPoint, Board& boad, string& posX, string& posY)
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

std::string Queen::bishop_check(Point& nextPoint, Board& boad, string& posX, string& posY)
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
	if (differenceX == differenceY || differenceX * -1 == differenceY || differenceX == differenceY * -1 || differenceX * -1 == differenceY * -1 && this->is_valid_move(kingpos, boad))
	{
		return "CHECK";
	}
	else
	{
		return "NOT CHECK";
	}
}

