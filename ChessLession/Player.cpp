#include "Player.h"

Player::Player()
{
	colorCurrentStep = true;
	playerTurn = true;
}
bool Player::getColorCurrentStep()
{
	// White == true  || Black == false
	return (colorCurrentStep) ? true : false;
}
void Player::changeColorStep()
{
	(this->colorCurrentStep) ? this->colorCurrentStep = false : this->colorCurrentStep = true;
}
void Player::changePlayerTurn()
{
	(this->playerTurn) ? this->playerTurn = false : this->playerTurn = true;
}
bool Player::getPlayerTurn()
{
	//player = true, bot = false
	return (playerTurn) ? true : false;
}
void Player::setTrueMate()
{
	this->mate = true;
}
void Player::setFalseMate()
{
	this->mate = false;
}
bool Player::getMate()
{
	return this->mate;
}
void Player::setTrueBlackMate()
{
	this->blackMath = true;
}
void Player::setFalseBlackMate()
{
	this->blackMath = false;
}
bool Player::getBlackMate()
{
	return this->blackMath;
}

void Player::setTrueWhiteMate()
{
	this->whiteMath = true;
}

void Player::setFalseWhiteMate()
{
	this->whiteMath = false;
}

bool Player::getWhiteMate()
{
	return this->whiteMath;
}

Player player;