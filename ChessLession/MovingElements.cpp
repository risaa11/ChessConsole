#include <iostream>
#include "MovingElements.h"
#include "ChessPieces.h"
#include "Player.h"
#include "GameLogic.h"
#include "MoveLogic.h"

void botTurn(Figure** map, int size)
{
	rand() % 500 + 200;
	Sleep(200);
	int fromX = 0;
	int fromY = 0;
	int toX = 0;
	int toY = 0;
	do {
		fromX = rand() % 8 + 1;
		fromY = rand() % 8 + 1;
		if (map[size - fromX][fromY - 1].getNull())
		{
			toX = rand() % 8 + 1;
			toY = rand() % 8 + 1;
			if (newStep(map, size, fromY, fromX, toY, toX, true, false))
			{
				break;
			}
		}

	} while (true);
}

void stepFigure(Figure** map, int size)
{
	int tempFigure = 0, tempFigure2 = 0;
	char figg;
	int tempFinalPoint = 0, tempFinalPoint2 = 0;
	char finn;
	std::cout << "Choose ur figure (x y)" << std::endl;
	std::cin >> figg;
	if (figg == 'A' || figg == 'a')
		tempFigure = 1;
	else if (figg == 'B' || figg == 'b')
		tempFigure = 2;
	else if (figg == 'C' || figg == 'c')
		tempFigure = 3;
	else if (figg == 'D' || figg == 'd')
		tempFigure = 4;
	else if (figg == 'E' || figg == 'e')
		tempFigure = 5;
	else if (figg == 'F' || figg == 'f')
		tempFigure = 6;
	else if (figg == 'G' || figg == 'g')
		tempFigure = 7;
	else if (figg == 'H' || figg == 'h')
		tempFigure = 8;
	std::cin >> tempFigure2;
	std::cout << "Choose final point (x y)" << std::endl;
	std::cin >> finn;
	if (finn == 'A' || finn == 'a')
		tempFinalPoint = 1;
	else if (finn == 'B' || finn == 'b')
		tempFinalPoint = 2;
	else if (finn == 'C' || finn == 'c')
		tempFinalPoint = 3;
	else if (finn == 'D' || finn == 'd')
		tempFinalPoint = 4;
	else if (finn == 'E' || finn == 'e')
		tempFinalPoint = 5;
	else if (finn == 'F' || finn == 'f')
		tempFinalPoint = 6;
	else if (finn == 'G' || finn == 'g')
		tempFinalPoint = 7;
	else if (finn == 'H' || finn == 'h')
		tempFinalPoint = 8;
	std::cin >> tempFinalPoint2;

	if (player.getMate())
	{
		if (!newStep(map, size, tempFigure, tempFigure2, tempFinalPoint, tempFinalPoint2, true, true))
		{
			std::cout << "Your king is checkmated, you can only move your king!!!!" << std::endl;
			Sleep(2000);
		}
	}
	else
		newStep(map, size, tempFigure, tempFigure2, tempFinalPoint, tempFinalPoint2, false, false);
}

bool newStep(Figure** map, int size, int tempFigure, int tempFigure2, int tempFinalPoint, int tempFinalPoint2, bool botMode, bool matCheck)
{
	char closeFunc = false;
	bool checkEnemy = false;
	(map[size - (tempFigure2)][tempFigure - 1].getColor() == map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor()) ? checkEnemy = false : checkEnemy = true;
	if (map[size - (tempFigure2)][tempFigure - 1].getNull() && (!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull() || checkEnemy))
	{
		(checkAbilityStep(size - (tempFigure2), tempFigure - 1, map, botMode)) ? closeFunc = true : closeFunc = false;

		if (closeFunc)
		{
			if (map[size - (tempFigure2)][tempFigure - 1].getNull() && ((!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull() || checkEnemy)))
			{
				if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♘" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♞")
				{
					return (hStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♔" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♚")
				{
					return (kStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♙" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♟")
				{
					return (pStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♖" || map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♜")
				{
					return (rStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if ((map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♗") || (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♝"))
				{
					return (eStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
				else if (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♕" || (map[size - (tempFigure2)][tempFigure - 1].getValue() == u8"♛"))
				{
					return (quennStep(tempFigure, tempFinalPoint, map, size, tempFigure2, tempFinalPoint2, !botMode, matCheck)) ? true : false;
				}
			}
			else
			{
				if (!botMode)
				{
					std::cout << "Impossible point(" << std::endl;
					Sleep(2000);
				}
				return false;
			}
		}
	}
	else
	{
		if (!botMode)
		{
			std::cout << "Impossible move!!! He busy field" << std::endl;
			Sleep(2000);
		}
		return false;
	}
	return false;
}