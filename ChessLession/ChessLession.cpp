#include "ChessPieces.h"
#include "Player.h"
#include "Board.h"
#include "MoveLogic.h"
#include "GameLogic.h"
#include "Button.h"
#include "MovingElements.h"
#include <iostream>

int main()
{
	if (selectGameMode())
	{
		if (selectStartColor())
		{
			bool endGameCheck = false;
			SetConsoleOutputCP(CP_UTF8);
			SetConsoleCP(CP_UTF8);
			const int size = 8;
			Figure** map = mapCreate(size);
			firstFillingMap(map, size);
			do
			{
				endGameCheck = false;

				printMap(map, size);

				matCheck(map, size, false);

				if (!player.getMate())
				{
					if (!player.getPlayerTurn())
						botTurn(map, size);
					else
						stepFigure(map, size);
				}
				else
				{
					if (!player.getPlayerTurn())
					{
						if (!botMateTurn(map, size))
						{
							return 0;
						}
						else
						{
							player.changeColorStep();
							player.changePlayerTurn();
						}
					}
					else
						stepFigure(map, size);
				}


				system("cls");

			} while (true);
		}
		else
		{
			bool endGameCheck = false;
			SetConsoleOutputCP(CP_UTF8);
			SetConsoleCP(CP_UTF8);
			const int size = 8;
			Figure** map = mapCreate(size);
			firstFillingMap(map, size);
			do
			{
				endGameCheck = false;

				printMap(map, size);

				matCheck(map, size, false);

				if (!player.getMate())
				{
					if (player.getPlayerTurn())
						botTurn(map, size);
					else
						stepFigure(map, size);
				}
				else
				{
					if (player.getPlayerTurn())
					{
						if (!botMateTurn(map, size))
						{
							return 0;
						}
						else
						{
							player.changeColorStep();
							player.changePlayerTurn();
						}
					}
					else
						stepFigure(map, size);
				}


				system("cls");

			} while (true);
		}
	}
	else
	{
		bool endGameCheck = false;
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		const int size = 8;
		Figure** map = mapCreate(size);
		firstFillingMap(map, size);
		do
		{
			endGameCheck = false;

			printMap(map, size);

			matCheck(map, size, false);

			
			stepFigure(map, size);


			system("cls");

		} while (true);
	}
}
