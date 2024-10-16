#pragma once
class GameState
{
private:
	int score;
	int lives;
	double width;
	double height;
	double lowerBound;
	double upperBound;
	double speed;
	int lastCapturedSecond;
	public:
		GameState(int score, int lives, double width, double height, double lowerBound, double upperBound, double speed);
		void setScore(int score);
		int getScore();
		void setLives(int lives);
		int getLives();
		void setSpeed(double speed);
		double getSpeed();
		double getWidth();
		double getHeight();
		double getLowerBound();
		double getUpperBound();
		int getLastCapturedSecond();
		void setLastCapturedSecond(int lastCapturedSecond);
		void reset();
};
