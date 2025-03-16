#pragma once

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <string>

class Figure;

bool checkAbilityStep(int stepFromX, int stepFromY, Figure** map, bool botMode);
bool checkKingAlive(Figure** map, int size);
bool matCheck(Figure** map, int size, bool botMode);
bool botMateTurn(Figure** map, int size);
std::string searchKing(Figure** map, int size);

#endif