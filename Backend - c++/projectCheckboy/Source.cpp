/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Board.h"
#include <vector>
#include "King.h"
#include "rook.h"
#include "bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"

using std::cout;
using std::endl;
using std::string;
#define KING_POS 3

#define IDI_ICON_1            102
#define IDI_ICON_2            103


void main()
{

	srand(time_t(NULL));

	HWND hideIt = FindWindow("ConsoleWindowClass", NULL);
	ShowWindow(hideIt, 0);

	system("start ./chessGraphics.exe");
	Sleep(1000);
	Pipe p;
	bool isConnect = p.connect();
	int ExitCount = 0;
	
	string ans;
	while (!isConnect)
	{

		cout << "trying connect again.." << endl;
		Sleep(5000);
		isConnect = p.connect();
		ExitCount++;
		if (ExitCount == 5)
		{
			CloseWindow(hideIt);
			p.close();
			return;
		}

	}

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	
	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	string board[8] = { "RNBKQBNR", "PPPPPPPP", "########", "########", "########", "########", "pppppppp", "rnbkqbnr" };
	Board b(board, 8);

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	cout << "DD" << msgFromGraphics << endl;

	Point KingPos(4, 1);
	Point RookPos(1, 1);
	Point Rook2Pos(8, 1);
	Point BishopPos(3, 1);
	Point Bishop2Pos(6, 1);
	Point KnightPos(2, 1);
	Point Knight2Pos(7, 1);
	Point QueenPos(5, 1);

	King* white_King = new King(KingPos, false);
	Rook* white_Rook1 = new Rook(RookPos, false);
	Rook* white_Rook2 = new Rook(Rook2Pos, false);
	Bishop* white_Bishop1 = new Bishop(BishopPos, false);
	Bishop* white_Bishop2 = new Bishop(Bishop2Pos, false);
	Knight* white_Knight1 = new Knight(KnightPos, false);
	Knight* white_Knight2 = new Knight(Knight2Pos, false);
	Queen* white_Queen = new Queen(QueenPos, false);

	vector<ChessTool*> white_tools;
	white_tools.push_back(white_Rook1);
	white_tools.push_back(white_Knight1);
	white_tools.push_back(white_Bishop1);
	white_tools.push_back(white_King);
	white_tools.push_back(white_Queen);
	white_tools.push_back(white_Bishop2);
	white_tools.push_back(white_Knight2);
	white_tools.push_back(white_Rook2);

	Point white_Pawn_Pos[8];
	vector<Pawn*> white_Pawn_List;

	for (int i = 0; i < 8; i++)
	{
		white_Pawn_Pos[i].setX(i + 1);
		white_Pawn_Pos[i].setY(2);
	}

	for (int i = 0; i < 8; i++)
	{
		Pawn* white_pawn = new Pawn(white_Pawn_Pos[i], false);
		white_Pawn_List.push_back(white_pawn);
		white_tools.push_back(white_Pawn_List[i]);
	}


	Point KingPos2(4, 8);
	Point RookPos2(1, 8);
	Point Rook2Pos2(8, 8);
	Point BishopPos2(3, 8);
	Point Bishop2Pos2(6, 8);
	Point KnightPos2(2, 8);
	Point Knight2Pos2(7, 8);
	Point QueenPos2(5, 8);

	King* black_King = new King(KingPos2, true);
	Rook* black_Rook1 = new Rook(RookPos2, true);
	Rook* black_Rook2 = new Rook(Rook2Pos2, true);
	Bishop* black_Bishop1 = new Bishop(BishopPos2, true);
	Bishop* black_Bishop2 = new Bishop(Bishop2Pos2, true);
	Knight* black_Knight1 = new Knight(KnightPos2, true);
	Knight* black_Knight2 = new Knight(Knight2Pos2, true);
	Queen* black_Queen = new Queen(QueenPos2, true);

	vector<ChessTool*> black_tools;
	black_tools.push_back(black_Rook1);
	black_tools.push_back(black_Knight1);
	black_tools.push_back(black_Bishop1);
	black_tools.push_back(black_King);
	black_tools.push_back(black_Queen);
	black_tools.push_back(black_Bishop2);
	black_tools.push_back(black_Knight2);
	black_tools.push_back(black_Rook2);
	
	Point black_Pawn_Pos[8];
	vector<Pawn*> black_Pawn_List;

	for (int i = 0; i < 8; i++)
	{
		black_Pawn_Pos[i].setX(i + 1);
		black_Pawn_Pos[i].setY(7);
	}

	for (int i = 0; i < 8; i++)
	{
		Pawn* black_pawn = new Pawn(black_Pawn_Pos[i], true);
		black_Pawn_List.push_back(black_pawn);
		black_tools.push_back(black_Pawn_List[i]);
	}

	
	bool is_valid_move = false;


	string white_posX = "1234567812345678";
	string white_posY = "1111111122222222";

	string black_posX = "1234567812345678";
	string black_posY = "8888888877777777";

	bool turn = true;
	bool notFound = false;
	int lock = 0;
	int lock2 = 0;

	int check = 0;
	int check2 = 0;
	
	while (msgFromGraphics != "quit")
	{
		if (black_posX[KING_POS] == 'X' && black_posY[KING_POS] == 'Y' || white_posX[KING_POS] == 'X' && white_posY[KING_POS] == 'Y')
		{
			strcpy_s(msgToGraphics, "8");
			break;
		}
		notFound = false;
		lock = 0;
		lock2 = 0;
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		

		b.wordsToNums(msgFromGraphics);

		//cout << msgFromGraphics << " " << msgFromGraphics[0] - '0' << endl;

		if (turn)
		{
			
			for (int i = 0; i < white_posX.length(); i++)
			{
				
				if (msgFromGraphics[0] == white_posX[i] && msgFromGraphics[1] == white_posY[i] && turn)
				{
					int x = msgFromGraphics[2] - '0';
					int y = msgFromGraphics[3] - '0';
					Point movPos(x, y);
					if (white_tools[i]->is_valid_move(movPos, b))
					{
						//std::cout << black_tools[3]->is_checkmate(check2, b) << std::endl;
						
						if (white_tools[i]->move(movPos, b, black_posX, black_posY))
						{
							
							
							white_tools[i]->check(movPos, b, black_posX, black_posY) == "CHECK" ? check = 1 : check = 0;
							
							if (check)
							{
								
								white_posX[i] = msgFromGraphics[2];
								white_posY[i] = msgFromGraphics[3];
								strcpy_s(msgToGraphics, "1");
								turn ? turn = false : turn = true;

								lock2 = 1;
							}
							else
							{
								white_posX[i] = msgFromGraphics[2];
								white_posY[i] = msgFromGraphics[3];
								strcpy_s(msgToGraphics, "0");
								turn ? turn = false : turn = true;

								lock2 = 1;
							}
							
							
							
						}
						else
						{
							strcpy_s(msgToGraphics, "3");
							lock2 = 1;
						}

					}
					else
					{
						strcpy_s(msgToGraphics, "6");
						lock2 = 1;
					}

				}
				
			}
			lock2 == 0 ? notFound = true : NULL;
			
		}
		else if(!turn)
		{
			for (int i = 0; i < black_posX.length(); i++)
			{
				if (msgFromGraphics[0] == black_posX[i] && msgFromGraphics[1] == black_posY[i] && !turn)
				{
					int x = msgFromGraphics[2] - '0';
					int y = msgFromGraphics[3] - '0';
					Point movPos(x, y);
					if (black_tools[i]->is_valid_move(movPos, b))
					{
						
						if (black_tools[i]->move(movPos, b, white_posX, white_posY))
						{
							//std::cout << black_tools[i]->check(movPos, b, white_posX, white_posY) << (black_tools[i]->check(movPos, b, white_posX, white_posY) == "CHECK" )<< std::endl;
							black_tools[i]->check(movPos, b, white_posX, white_posY) == "CHECK" ? check2 = 1 : check2 = 0;
							
							if (check2)
							{
								
								black_posX[i] = msgFromGraphics[2];
								black_posY[i] = msgFromGraphics[3];
								strcpy_s(msgToGraphics, "1");
								turn ? turn = false : turn = true;
								
								lock = 1;
							}
							else
							{
								black_posX[i] = msgFromGraphics[2];
								black_posY[i] = msgFromGraphics[3];
								strcpy_s(msgToGraphics, "0");
								turn ? turn = false : turn = true;

								lock = 1;
							}
							
						}
						else
						{
							strcpy_s(msgToGraphics, "3");
							lock = 1;
						}

					}
					else
					{
						strcpy_s(msgToGraphics, "6");
						lock = 1;
					}
				}
				
				
			}
			lock == 0 ? notFound = true : NULL;
			
		}
		/*
		if (po)
		{
			strcpy_s(msgToGraphics, "0");
		}
		*/
		if (notFound)
		{
			strcpy_s(msgToGraphics, "2");
		}
		

		for ( int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << b.get_board()[i][j] << " ";
			}
			cout << endl;
		}
		

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);
		
		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
		
		
	}
	p.sendMessageToGraphics(msgToGraphics);

	p.close();
	CloseWindow(hideIt);
	/*
	system("Taskkill /IM chessGraphics.exe /F");
	system("start C:\\Users\\משתמש\\Desktop\\chessGraphics.exe");
	Sleep(1000);
	Pipe d;
	isConnect = d.connect();
	while (!isConnect)
	{

		cout << "trying connect again.." << endl;
		Sleep(5000);
		isConnect = d.connect();
		ExitCount++;
		if (ExitCount == 5)
		{
			//CloseWindow(hideIt);
			d.close();
			return;
		}

	}
	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp#################K##############PPPPPPPPRNB#QBNR1"); // just example...
	d.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	msgFromGraphics = d.getMessageFromGraphics();
	*/
}