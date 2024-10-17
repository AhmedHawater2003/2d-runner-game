#pragma once
#include <SFML/Audio.hpp>
class SoundPlayer
{
public:
	SoundPlayer();
	sf::Music background;
	sf::Music gameOver;
	sf::Music gameLost;
	sf::Music obstacleSound;
	sf::Music collectableSound;
	sf::Music powerUpSound;
	void playBackground();
	void playGameWon();
	void playGameLost();
	void playObstacle();
	void playCollectable();
	void playPowerUp();
	void stop();
};

