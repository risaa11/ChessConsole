#include "GameLogic.h"
#include "ChessPieces.h"
#include "Player.h"
#include "MoveLogic.h"
#include "Board.h"
#include "MovingElements.h"

bool checkAbilityStep(int stepFromX, int stepFromY, Figure** map, bool botMode)
{
	if (!botMode)
	{
		if (!map[stepFromX][stepFromY].getNull())
		{
			std::cout << "SO BULL" << std::endl;
			Sleep(2000);
			return false;
		}
		if ((map[stepFromX][stepFromY].getColor() == 'B' && !player.getColorCurrentStep()) || (map[stepFromX][stepFromY].getColor() == 'W' && player.getColorCurrentStep()))
		{
			return true;
		}
		else
		{
			std::cout << "So Bad Move" << std::endl;
			Sleep(2000);
			return false;
		}
	}
	else
	{
		if (!map[stepFromX][stepFromY].getNull())
		{
			std::cout << "SO BULL" << std::endl;
			return false;
		}
		if ((map[stepFromX][stepFromY].getColor() == 'B' && !player.getColorCurrentStep()) || (map[stepFromX][stepFromY].getColor() == 'W' && player.getColorCurrentStep()))
			return true;
		else
			return false;
	}
}

bool checkKingAlive(Figure** map, int size)
{
	if (searchKing(map, size) == "BlackLose")
	{
		std::cout << "Black Player WIN!!!!" << std::endl;
		Sleep(2000);
		return false;
	}
	if (searchKing(map, size) == "WhiteLose")
	{
		std::cout << "White Player WIN!!!!" << std::endl;
		Sleep(2000);
		return false;
	}
	return true;
}

bool matCheck(Figure** map, int size, bool botMode)
{
	bool stopSearch = false;
	int kingX = 0;
	int kingY = 0;
	for (int toX = 0; toX < size; ++toX)
	{
		for (int toY = 0; toY < size; ++toY)
		{
			if (map[toX][toY].getCharValue() == 'k' && (map[toX][toY].getColor() == 'W' && player.getColorCurrentStep() || map[toX][toY].getColor() == 'B' && !player.getColorCurrentStep()))
			{
				kingX = toX;
				kingY = toY;
				stopSearch = true;
				break;
			}
		}
		if (stopSearch)
			break;
	}

	for (int i = 0;i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j].getNull() && map[i][j].getColor() != map[kingX][kingY].getColor())
			{
				player.changePlayerTurn();
				player.changeColorStep();
				if (newStep(map, size, j + 1, size - i, kingY + 1, size - kingX, true, true))
				{
					player.changePlayerTurn();
					player.changeColorStep();
					if (kingX == 0)
					{
						if (!botMode)
							std::cout << "\nBlack king has a check!!!\n" << std::endl;
						player.setTrueBlackMate();
						player.setFalseWhiteMate();
					}
					else
					{
						if (!botMode)
							std::cout << "\nWhite king has a check!!!\n" << std::endl;
						player.setTrueWhiteMate();
						player.setFalseBlackMate();
					}
					if (!botMode)
						Sleep(2000);
					player.setTrueMate();
					return true;
				}
				else
				{
					player.changePlayerTurn();
					player.changeColorStep();
				}
			}
		}
	}
	player.setFalseBlackMate();
	player.setFalseWhiteMate();
	player.setFalseMate();
	return false;
}
bool botMateTurn(Figure** map, int size)
{
	int tempX = 0;
	int tempY = 0;
	bool close = false;
	for (int tempX = 0; tempX < size; ++tempX)
	{
		for (int tempY = 0; tempY < size; ++tempY)
		{
			if (map[tempX][tempY].getNull() && (map[tempX][tempY].getColor() == 'W' && player.getColorCurrentStep()) || (map[tempX][tempY].getColor() == 'B' && !player.getColorCurrentStep()))
			{
				for (int i = 0; i < size; ++i)
				{
					for (int j = 0; j < size; ++j)
					{
						close = false;
						if (map[i][j].getNull())
						{
							char tempVal = map[i][j].getCharValue();
							if (newStep(map, size, tempY + 1, size - tempX, j + 1, size - i, true, false))
							{
								player.changeColorStep();
								player.changePlayerTurn();
								matCheck(map, size, true);
								if (player.getMate())
								{
									map[tempX][tempY].setValue(map[i][j].getCharValue(), map[i][j].getColor());
									map[i][j].setValue(tempVal, (map[tempX][tempY].getColor() == 'W') ? 'B' : 'W');
								}
								else
								{
									close = true;
									return true;
								}
							}
						}
						else
						{
							if (newStep(map, size, tempY + 1, size - tempX, j + 1, size - i, true, false))
							{
								player.changeColorStep();
								player.changePlayerTurn();
								matCheck(map, size, true);
								if (player.getMate())
								{
									map[tempX][tempY].setValue(map[i][j].getCharValue(), map[i][j].getColor());
									map[i][j].setValue('n', (map[tempX][tempY].getColor() == 'W') ? 'W' : 'B');
								}
								else
								{
									close = true;
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	system("cls");
	printMap(map, size);
	(player.getBlackMate()) ? std::cout << "Black king has a CheckMate" << std::endl : std::cout << "White king has a CheckMate" << std::endl;
	Sleep(5000);
	player.changeColorStep();
	player.changePlayerTurn();
	return false;
}
std::string searchKing(Figure** map, int size)
{
	bool endGameCheckBlack = true;
	bool endGameCheckWhite = true;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j].getValue() == u8"♚")
			{
				endGameCheckWhite = false;
			}

			if (map[i][j].getValue() == u8"♔")
			{
				endGameCheckBlack = false;
			}
		}
	}
	if (endGameCheckBlack)
		return "WhiteLose";
	if (endGameCheckWhite)
		return "BlackLose";
	if (!endGameCheckBlack && !endGameCheckWhite)
		return "ALL";
}