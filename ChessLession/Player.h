#pragma once

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    bool colorCurrentStep = true;
    bool playerTurn = true;
    bool whiteMath = false;
    bool blackMath = false;
    bool mate = false;
public:
    Player();
    bool getColorCurrentStep();
    void changeColorStep();
    void changePlayerTurn();
    bool getPlayerTurn();
    void setTrueMate();
    void setFalseMate();
    bool getMate();
    void setTrueBlackMate();
    void setFalseBlackMate();
    bool getBlackMate();
    void setTrueWhiteMate();
    void setFalseWhiteMate();
    bool getWhiteMate();
};

extern Player player;

#endif