#pragma once
#include <iostream>
#include "MovingElements.h"
#include "ChessPieces.h"
#include "Player.h"
#include "GameLogic.h"
#include "MoveLogic.h"
#define MOVE_LOGIC_H

class Figure;

bool newStep(Figure** map, int size, int tempFigure, int tempFigure2, int tempFinalPoint, int tempFinalPoint2, bool botMode, bool matCheck);
void stepFigure(Figure** map, int size);
void botTurn(Figure** map, int size);