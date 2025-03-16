#pragma once
#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

class Horse {
protected:
    bool H = false;
public:
    Horse(bool H) : H(H) {}
    Horse() : H(false) {}
};

class Rook : public Horse {
protected:
    bool R = false;
public:
    Rook(bool R) : R(R) {}
    Rook() : R(false) {}
};

class Pawn : public Rook {
protected:
    bool P = false;
    bool firstStep = false;
public:
    Pawn(bool P) : P(P) {}
    Pawn() : P(false) {}
    void setTrueFirstStep() { firstStep = true; }
    bool getFirstStep() { return firstStep; }
};

class Elephant : public Pawn {
protected:
    bool E = false;
public:
    Elephant(bool E) : E(E) {}
    Elephant() : E(false) {}
};

class King : public Elephant {
protected:
    bool K = false;
public:
    King(bool K) : K(K) {}
    King() : K(false) {}
};

class Quenn : public King {
protected:
    bool Q = false;
public:
    Quenn(bool Q) : Q(Q) {}
    Quenn() : Q(false) {}
};

class Figure : public Quenn {
protected:
    bool whiteColor = false;
    bool whiteKingUnshakable = true;
    bool blackKingUnshakable = true;
public:
    Figure(char s);
    Figure();
    void changeWhiteKing() { whiteKingUnshakable = false; }
    void changeBlackKing() { blackKingUnshakable = false; }
    bool whiteKingUnshakableCheck() { return whiteKingUnshakable; }
    bool blackKingUnshakableCheck() { return blackKingUnshakable; }
    const char* getValue();
    char getCharValue();
    void setValue(char s, char c);
    int getNull();
    char getColor();
};

#endif