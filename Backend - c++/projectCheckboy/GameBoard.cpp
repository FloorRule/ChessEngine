#include "GameBoard.h"
#include "Rook.h"

Board::Board(int maxElements, string game[])
{
	this->_maxElements = maxElements;
	
	for (int i = 0; i < this->_maxElements; i++)
	{
		this->_board[i] = game[i];
	}
	

}

Board::~Board()
{
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

string* Board::get_board()
{
	return this->_board;
}

void Board::set_board(string board)
{
	for (int i = 0; i < this->_maxElements; i++)
	{
		this->_board[i] = board[i];
	}
}

bool Board::is_there_tool(Point nextPos)
{
	//std::cout << this->_board[nextPos.getPointY()][nextPos.getPointX()] <<" "<< nextPos.getPointY() << nextPos.getPointX() <<std::endl;
	if (nextPos.getPointY() - 1 >= 0 && nextPos.getPointX() - 1 >= 0 && nextPos.getPointY() - 1 <= 7 && nextPos.getPointX() - 1 <= 7)
	{
		if (this->_board[nextPos.getPointY() - 1][nextPos.getPointX() - 1] == '#')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
	
}

bool Board::is_there_tool_rook(Rook rook, Point pos, Point nextPos)
{
	int leftOver = 0;
	string marks = "RNBKQPrnbkqp";
	int startPos = 0;
	if (rook.is_black_team())
	{
		startPos = 6;
	}
	else
	{
		startPos = 0;
	}

	

	for (int i = -7; i < 8; i++)
	{
		if (pos.getPointX() == nextPos.getPointX() && pos.getPointY() + i == nextPos.getPointY())
		{
			for (int j = 0; j < i; j++)
			{
				
				if (this->_board[pos.getPointY() + j][pos.getPointX() - 1] != '#')
				{
					return false;
				}
				
				
				
			}
		}
		else if (pos.getPointY() == nextPos.getPointY() && pos.getPointX() + i == nextPos.getPointX())
		{
			
			for (int j = 0; j < i; j++)
			{
				
				if (this->_board[pos.getPointY() - 1][pos.getPointX() + j] != '#')
				{
					return false;
				}
				
				
				
			}
		}
	}


	return true;
}


void Board::updateBoard(Point lastPlace, Point movedPoint, string mark)
{
	this->_board[lastPlace.getPointY() - 1][lastPlace.getPointX() - 1] = '#';
	this->_board[movedPoint.getPointY() - 1][movedPoint.getPointX() - 1] = mark[0];
}

