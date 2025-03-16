#pragma once

#ifndef BOARD_H
#define BOARD_H

class Figure;

Figure** mapCreate(char size);
void printMap(Figure** map, int size);
void firstFillingMap(Figure** array, int size);

#endif