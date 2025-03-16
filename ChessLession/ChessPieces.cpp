#include "ChessPieces.h"
#include "Player.h"
#include <iostream>

// Реализации методов класса Figure
Figure::Figure(char s)
{
	if (s == 'k')
	{
		this->K = true;
	}
	if (s == 'q')
	{
		this->Q = true;
	}
	if (s == 'h')
	{
		this->H = true;
	}
	if (s == 'p')
	{
		this->P = true;
	}
	if (s == 'r')
	{
		this->R = true;
	}
	if (s == 'e')
	{
		this->E = true;
	}
}

Figure::Figure()
{
	this->K = false;
	this->Q = false;
	this->H = false;
	this->P = false;
	this->R = false;
	this->E = false;
	this->whiteKingUnshakable = true;
	this->blackKingUnshakable = true;
}

const char* Figure::getValue()
{
	if (!this->whiteColor)
	{
		if (E)
			return u8"♗";
		else if (Q)
			return u8"♕";
		else if (H)
			return u8"♘";
		else if (R)
			return u8"♖";
		else if (P)
			return u8"♟";
		else if (K)
			return u8"♔";
		else if (!E && !Q && !H && !R && !P && !K)
			return " ";
	}
	else
	{
		if (E)
			return u8"♝";
		else if (Q)
			return u8"♛";
		else if (H)
			return u8"♞";
		else if (R)
			return u8"♜";
		else if (P)
			return u8"♙";
		else if (K)
			return u8"♚";
		else if (!E && !Q && !H && !R && !P && !K)
			return " ";
	}
}

char Figure::getCharValue()
{
	if (E)
		return 'e';
	else if (Q)
		return 'q';
	else if (H)
		return 'h';
	else if (R)
		return 'r';
	else if (P)
		return 'p';
	else if (K)
		return 'k';
	else if (!E && !Q && !H && !R && !P && !K)
		return 'n';
}

void Figure::setValue(char s, char c)
{
	if (c == 'W' || c == 'w')
	{
		this->K = false;
		this->Q = false;
		this->H = false;
		this->P = false;
		this->R = false;
		this->E = false;
		if (s == 'k')
		{
			this->K = true;
			this->whiteColor = true;
		}
		if (s == 'q')
		{
			this->Q = true;
			this->whiteColor = true;
		}
		if (s == 'h')
		{
			this->H = true;
			this->whiteColor = true;
		}
		if (s == 'p')
		{
			this->P = true;
			this->whiteColor = true;
		}
		if (s == 'r')
		{
			this->R = true;
			this->whiteColor = true;
		}
		if (s == 'e')
		{
			this->E = true;
			this->whiteColor = true;
		}
	}
	else
	{
		this->K = false;
		this->Q = false;
		this->H = false;
		this->P = false;
		this->R = false;
		this->E = false;
		if (s == 'k')
		{
			this->K = true;
			this->whiteColor = false;
		}
		if (s == 'q')
		{
			this->Q = true;
			this->whiteColor = false;
		}
		if (s == 'h')
		{
			this->H = true;
			this->whiteColor = false;
		}
		if (s == 'p')
		{
			this->P = true;
			this->whiteColor = false;
		}
		if (s == 'r')
		{
			this->R = true;
			this->whiteColor = false;
		}
		if (s == 'e')
		{
			this->E = true;
			this->whiteColor = false;
		}
	}
}

int Figure::getNull()
{
	return (this->K == false && this->Q == false && this->H == false && this->P == false && this->R == false && this->E == false) ? 0 : 1;
}

char Figure::getColor()
{
	return (whiteColor) ? 'W' : 'B';
}