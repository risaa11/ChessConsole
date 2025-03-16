#pragma once

#ifndef MOVE_LOGIC_H
#define MOVE_LOGIC_H

class Figure;

bool quennStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck);
bool pStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck);
bool kStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck);
bool rStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck);
bool eStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck);
bool hStep(int tempFigure, int tempFinalPoint, Figure** map, int size, int tempFigure2, int tempFinalPoint2, bool botMode, bool matCheck);


#endif