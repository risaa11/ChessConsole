#include "MoveLogic.h"
#include "ChessPieces.h"
#include "Player.h"
#include "GameLogic.h"



bool quennStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	if (((tempFigure - tempFinalPoint) == 0 || (tempFigure2 - tempFinalPoint2) == 0) || ((tempFigure + tempFinalPoint) == 0 || (tempFigure2 + tempFinalPoint2) == 0) || ((tempFigure + tempFinalPoint) == 0 || (tempFigure2 - tempFinalPoint2) == 0) || ((tempFigure - tempFinalPoint) == 0 || (tempFigure2 + tempFinalPoint2) == 0))
	{
		int temppf2 = tempFigure2;
		int temppf = tempFigure;
		if (tempFigure2 < tempFinalPoint2)
		{
			do {
				temppf2++;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No quenn!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure2 > tempFinalPoint2)
		{
			do {
				temppf2--;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No quenn!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure > tempFinalPoint)
		{
			do {
				temppf--;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No quenn!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure < tempFinalPoint)
		{
			do {
				temppf++;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No quenn!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else return false;
	}
	else
	{
		int a = (tempFinalPoint > tempFigure) ? tempFinalPoint - tempFigure : tempFigure - tempFinalPoint;
		int b = (tempFinalPoint2 > tempFigure2) ? tempFinalPoint2 - tempFigure2 : tempFigure2 - tempFinalPoint2;
		if (a == b)
		{
			int temppf2 = tempFigure2;
			int temppf = tempFigure;
			if (tempFigure < tempFinalPoint && tempFigure2 < tempFinalPoint2)
			{
				do {
					temppf++;
					temppf2++;
					if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
					{
						if (!matCheck)
						{
							map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
					}
					if (map[size - (temppf2)][temppf - 1].getNull())
					{
						if (botMode)
						{
							std::cout << "Impossible move" << std::endl;
							Sleep(1000);
						}
						return false;
						break;
					}
					if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
					{
						if (!matCheck)
						{
							map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
						break;
					}
					if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
					{
						if (botMode)
						{
							std::cout << "No queen!!" << std::endl;
							Sleep(2000);
						}
						return false;
						break;
					}

				} while (true);
			}
			else if (tempFigure < tempFinalPoint && tempFigure2 > tempFinalPoint2)
			{
				do {
					temppf++;
					temppf2--;
					if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
					{
						if (!matCheck)
						{
							map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
					}
					if (map[size - (temppf2)][temppf - 1].getNull())
					{
						if (botMode)
						{
							std::cout << "Impossible move" << std::endl;
							Sleep(1000);
						}
						return false;
						break;
					}
					if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
					{
						if (!matCheck)
						{
							map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
						break;
					}
					if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
					{
						if (botMode)
						{
							std::cout << "No queen!!" << std::endl;
							Sleep(2000);
						}
						return false;
						break;
					}

				} while (true);
			}
			else if (tempFigure > tempFinalPoint && tempFigure2 < tempFinalPoint2)
			{
				do {
					temppf--;
					temppf2++;
					if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
					{
						if (!matCheck)
						{
							map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
					}
					if (map[size - (temppf2)][temppf - 1].getNull())
					{
						if (botMode)
						{
							std::cout << "Impossible move" << std::endl;
							Sleep(1000);
						}
						return false;
						break;
					}
					if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
					{
						if (!matCheck)
						{
							map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
						break;
					}
					if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
					{
						if (botMode)
						{
							std::cout << "No queen!!" << std::endl;
							Sleep(2000);
						}
						return false;
						break;
					}

				} while (true);
			}
			else if (tempFigure > tempFinalPoint && tempFigure2 > tempFinalPoint2)
			{
				do {
					temppf--;
					temppf2--;
					if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
					{
						if (!matCheck)
						{
							map[size - (temppf2)][temppf - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
					}
					if (map[size - (temppf2)][temppf - 1].getNull())
					{
						if (botMode)
						{
							std::cout << "Impossible move" << std::endl;
							Sleep(1000);
						}
						return false;
						break;
					}
					if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
					{
						if (!matCheck)
						{
							map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('q', map[size - (tempFigure2)][tempFigure - 1].getColor());
							map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
							player.changePlayerTurn();
							player.changeColorStep();
						}
						return true;
						break;
					}
					if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
					{
						if (botMode)
						{
							std::cout << "No queen!!" << std::endl;
							Sleep(2000);
						}
						return false;
						break;
					}

				} while (true);
			}
			else return false;
		}
		else return false;
	}
}

bool pStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	if (map[size - (tempFigure2)][tempFigure - 1].getColor() == 'W')
	{
		if (!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull())
		{
			if (((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) && tempFigure - tempFinalPoint == 0) || (((tempFigure2 - tempFinalPoint2 == 2 || tempFigure2 - tempFinalPoint2 == -2) && tempFigure - tempFinalPoint == 0) && map[size - (tempFigure2)][tempFigure - 1].getFirstStep()))
			{
				if (tempFigure - tempFinalPoint != 0)
					return false;
				if (size - (tempFinalPoint2) < size - (tempFigure2))
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				else
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
				}
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
			}
		}
		else
		{
			if ((tempFinalPoint2 - tempFigure2 == 1 && tempFigure != tempFinalPoint) && (tempFinalPoint - tempFigure == 1 || tempFinalPoint - tempFigure == -1))
			{
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
			}
		}
	}
	else
	{
		if (!map[size - (tempFinalPoint2)][tempFinalPoint - 1].getNull())
		{
			if (((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) && tempFigure - tempFinalPoint == 0) || (((tempFigure2 - tempFinalPoint2 == 2 || tempFigure2 - tempFinalPoint2 == -2) && tempFigure - tempFinalPoint == 0) && map[size - (tempFigure2)][tempFigure - 1].getFirstStep()))
			{
				if (size - (tempFinalPoint2) > size - (tempFigure2))
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				else
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
				}
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
			}
		}
		else
		{
			if ((tempFinalPoint2 - tempFigure2 == -1 && tempFigure != tempFinalPoint) && (tempFinalPoint - tempFigure == 1 || tempFinalPoint - tempFigure == -1))
			{
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('p', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
			else
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
			}
		}
	}
}

bool kStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	if (map[size - (tempFigure2)][tempFigure - 1].getColor() == 'B')
		map[size - (tempFigure2)][tempFigure - 1].changeBlackKing();
	else
		map[size - (tempFigure2)][tempFigure - 1].changeWhiteKing();

	if (((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) && tempFigure - tempFinalPoint == 0) || ((tempFigure - tempFinalPoint == 1 || tempFigure - tempFinalPoint == -1) && tempFigure2 - tempFinalPoint2 == 0) || ((tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1) && ((tempFigure - tempFinalPoint == 1 || tempFigure - tempFinalPoint == -1))))
	{
		if (!matCheck)
		{
			map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('k', map[size - (tempFigure2)][tempFigure - 1].getColor());
			map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			player.changePlayerTurn();
			player.changeColorStep();
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool rStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	int temppf2 = tempFigure2;
	int temppf = tempFigure;
	if (tempFigure2 < tempFinalPoint2)
	{
		do {
			temppf2++;
			if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
			{
				if (!matCheck)
				{
					map[size - (temppf2)][temppf - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
			if (map[size - (temppf2)][temppf - 1].getNull())
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
				break;
			}
			if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No rogue!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
	else if (tempFigure2 > tempFinalPoint2)
	{
		do {
			temppf2--;
			if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
			{
				if (!matCheck)
				{
					map[size - (temppf2)][temppf - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
			if (map[size - (temppf2)][temppf - 1].getNull())
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
				break;
			}
			if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No rogue!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
	else if (tempFigure > tempFinalPoint)
	{
		do {
			temppf--;
			if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
			{
				if (!matCheck)
				{
					map[size - (temppf2)][temppf - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
			if (map[size - (temppf2)][temppf - 1].getNull())
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
				break;
			}
			if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No rogue!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
	else if (tempFigure < tempFinalPoint)
	{
		do {
			temppf++;
			if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
			{
				if (!matCheck)
				{
					map[size - (temppf2)][temppf - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
			}
			if (map[size - (temppf2)][temppf - 1].getNull())
			{
				if (botMode)
				{
					std::cout << "Impossible move" << std::endl;
					Sleep(1000);
				}
				return false;
				break;
			}
			if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
			{
				if (!matCheck)
				{
					map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('r', map[size - (tempFigure2)][tempFigure - 1].getColor());
					map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
					player.changePlayerTurn();
					player.changeColorStep();
				}
				return true;
				break;
			}
			if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
			{
				if (botMode)
				{
					std::cout << "No rogue!!" << std::endl;
					Sleep(2000);
				}
				return false;
				break;
			}

		} while (true);
	}
	else return false;
}

bool eStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	int a = (tempFinalPoint > tempFigure) ? tempFinalPoint - tempFigure : tempFigure - tempFinalPoint;
	int b = (tempFinalPoint2 > tempFigure2) ? tempFinalPoint2 - tempFigure2 : tempFigure2 - tempFinalPoint2;
	if (a == b)
	{
		int temppf2 = tempFigure2;
		int temppf = tempFigure;
		if (tempFigure < tempFinalPoint && tempFigure2 < tempFinalPoint2)
		{
			do {
				temppf++;
				temppf2++;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf > tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No eliph!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure < tempFinalPoint && tempFigure2 > tempFinalPoint2)
		{
			do {
				temppf++;
				temppf2--;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf > tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No eliph!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure > tempFinalPoint && tempFigure2 < tempFinalPoint2)
		{
			do {
				temppf--;
				temppf2++;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf < tempFinalPoint && temppf2 > tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No eliph!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else if (tempFigure > tempFinalPoint && tempFigure2 > tempFinalPoint2)
		{
			do {
				temppf--;
				temppf2--;
				if (map[size - (temppf2)][temppf - 1].getNull() && (map[size - (temppf2)][temppf - 1].getColor() != map[size - (tempFigure2)][tempFigure - 1].getColor()) && (temppf2 == tempFinalPoint2 && temppf == tempFinalPoint))
				{
					if (!matCheck)
					{
						map[size - (temppf2)][temppf - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
				}
				if (map[size - (temppf2)][temppf - 1].getNull())
				{
					if (botMode)
					{
						std::cout << "Impossible move" << std::endl;
						Sleep(1000);
					}
					return false;
					break;
				}
				if (temppf == tempFinalPoint && temppf2 == tempFinalPoint2)
				{
					if (!matCheck)
					{
						map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('e', map[size - (tempFigure2)][tempFigure - 1].getColor());
						map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
						player.changePlayerTurn();
						player.changeColorStep();
					}
					return true;
					break;
				}
				if (temppf < tempFinalPoint && temppf2 < tempFinalPoint2)
				{
					if (botMode)
					{
						std::cout << "No eliph!!" << std::endl;
						Sleep(2000);
					}
					return false;
					break;
				}

			} while (true);
		}
		else return false;
	}
	else return false;
}

bool hStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck)
{
	if (((tempFigure - tempFinalPoint == 1 || tempFigure - tempFinalPoint == -1) && (tempFigure2 - tempFinalPoint2 == 2 || tempFigure2 - tempFinalPoint2 == -2)) || ((tempFigure - tempFinalPoint == 2 || tempFigure - tempFinalPoint == -2) && (tempFigure2 - tempFinalPoint2 == 1 || tempFigure2 - tempFinalPoint2 == -1)))
	{
		if (!matCheck)
		{
			map[size - (tempFinalPoint2)][tempFinalPoint - 1].setValue('h', map[size - (tempFigure2)][tempFigure - 1].getColor());
			map[size - (tempFigure2)][tempFigure - 1].setValue('n', map[size - (tempFinalPoint2)][tempFinalPoint - 1].getColor());
			player.changePlayerTurn();
			player.changeColorStep();
		}
		return true;
	}
	else
	{
		if (botMode)
		{
			std::cout << "Impossible point!!" << std::endl;
			Sleep(1000);
		}
		return false;
	}
}
