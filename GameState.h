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
		bool isGameOver;
		bool isGameLost;
		bool isGameWon;
		int gameDuration;
		double gravity = -800;
		

		GameState(int score, int lives, double width, double height, double lowerBound, double upperBound, double speed, int gameDuration);
		int getScore();
		int getLives();
		double getSpeed();
		double getWidth();
		double getHeight();
		double getLowerBound();
		double getUpperBound();
		int getLastCapturedSecond();
		void setScore(int score);
		void setLives(int lives);
		void setSpeed(double speed);
		void setLastCapturedSecond(int lastCapturedSecond);
		void reset();
};

