#include "SoundPlayer.h"

SoundPlayer::SoundPlayer() {
	background.openFromFile("sounds/background.ogg");
	gameOver.openFromFile("sounds/game-success.wav");
	gameLost.openFromFile("sounds/game-lost.wav");
	obstacleSound.openFromFile("sounds/obstacle.wav");
	collectableSound.openFromFile("sounds/collectable.wav");
	powerUpSound.openFromFile("sounds/powerup.wav");
}

void SoundPlayer::playBackground() {
	if (background.getStatus() != sf::Sound::Playing)
		background.play();
}

void SoundPlayer::playGameWon() {
	if (background.getStatus() == sf::Sound::Playing)
		background.stop();
	if (gameOver.getStatus() != sf::Sound::Playing)
		gameOver.play();
}

void SoundPlayer::playGameLost() {
	if (background.getStatus() == sf::Sound::Playing)
		background.stop();
	if (gameLost.getStatus() != sf::Sound::Playing)
		gameLost.play();
}

void SoundPlayer::playObstacle() {
	stop();
	if (obstacleSound.getStatus() != sf::Sound::Playing)
		obstacleSound.play();
}

void SoundPlayer::playCollectable() {
	stop();
	if (collectableSound.getStatus() != sf::Sound::Playing)
		collectableSound.play();
}

void SoundPlayer::playPowerUp() {
	stop();
	if (powerUpSound.getStatus() != sf::Sound::Playing)
		powerUpSound.play();
}

void SoundPlayer::stop() {
	if (obstacleSound.getStatus() == sf::Sound::Playing)
		obstacleSound.stop();
	if (collectableSound.getStatus() == sf::Sound::Playing)
		collectableSound.stop();
	if (powerUpSound.getStatus() == sf::Sound::Playing)
		powerUpSound.stop();
}