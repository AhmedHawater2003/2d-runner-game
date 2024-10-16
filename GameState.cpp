#include "GameState.h"

GameState::GameState(int score, int lives, double width, double height, double lowerBound, double upperBound, double speed)
{
	this->score = score;
	this->lives = lives;
	this->width = width;
	this->height = height;
	this->lowerBound = lowerBound;
	this->upperBound = upperBound;
	this->speed = speed;
	this->lastCapturedSecond = 0;
	this->isGameOver = false;
	this->isGameLost = false;
}

void GameState::setScore(int score)
{
	this->score = score;
}

int GameState::getScore()
{
	return score;
}

void GameState::setSpeed(double speed)
{
	this->speed = speed;
}

double GameState::getSpeed()
{
	return speed;
}

void GameState::setLives(int lives)
{
	this->lives = lives;
}

int GameState::getLives()
{
	return lives;
}

double GameState::getWidth()
{
	return width;
}

double GameState::getHeight()
{
	return height;
}

double GameState::getLowerBound()
{
	return lowerBound;
}

double GameState::getUpperBound()
{
	return upperBound;
}

void GameState::reset()
{
	score = 0;
	lives = 3;
}

int GameState::getLastCapturedSecond()
{
	return lastCapturedSecond;
}

void GameState::setLastCapturedSecond(int lastCapturedSecond)
{
	this->lastCapturedSecond = lastCapturedSecond;
}