#include "Board.h"
#include "ChessPieces.h"
#include "Player.h"

Figure** mapCreate(char size)
{

	Figure** newMap = new Figure * [size];
	for (int i = 0; i < size; ++i)
		newMap[i] = new Figure[size];

	return newMap;
}

void printMap(Figure** map, int size)
{
	int scrr = size;
	std::cout << "\n\n\t\t\t    A" << ' ' << "B" << ' ' << "C" << ' ' << "D" << ' ' << "E" << ' ' << "F" << ' ' << "G" << ' ' << "H" << ' ' << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "\t\t\t" << scrr << "   ";
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j].getValue() != 0)
				std::cout << map[i][j].getValue() << ' ';
			else
				std::cout << ' ' << ' ';
		}
		std::cout << "   " << scrr << std::endl;
		scrr--;
	}
	std::cout << "\n\n\t\t\t    A" << ' ' << "B" << ' ' << "C" << ' ' << "D" << ' ' << "E" << ' ' << "F" << ' ' << "G" << ' ' << "H" << ' ' << "           <<<<<<<<<<<<<------------\n" << std::endl;
	(player.getColorCurrentStep()) ? std::cout << "\nWhite player choose\n" << std::endl : std::cout << "\nBlack player choose\n" << std::endl;
}
void firstFillingMap(Figure** array, int size)
{
	const char* emoji = u8"♟";
	for (int i = 0; i < size; ++i)
	{
		array[1][i].setValue('p', 'B');
		array[6][i].setValue('p', 'W');
		array[1][i].setTrueFirstStep();
		array[6][i].setTrueFirstStep();
	}
	array[0][0].setValue('r', 'B');
	array[0][7].setValue('r', 'B');
	array[7][0].setValue('r', 'W');
	array[7][7].setValue('r', 'W');
	array[0][1].setValue('h', 'B');
	array[0][6].setValue('h', 'B');
	array[7][1].setValue('h', 'W');
	array[7][6].setValue('h', 'W');
	array[0][2].setValue('e', 'B');
	array[0][5].setValue('e', 'B');
	array[7][2].setValue('e', 'W');
	array[7][5].setValue('e', 'W');
	array[0][4].setValue('k', 'B');
	array[7][4].setValue('k', 'W');
	array[0][3].setValue('q', 'B');
	array[7][3].setValue('q', 'W');
}