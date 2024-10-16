#include "Player.h"
#include <glut.h>

Player::Player(std::pair<double, double> position, GameState* gameState)
	: BoundingBox(position, ORIGINAL_PLAYER_WIDTH, ORIGINAL_PLAYER_HEIGHT),
	gameState(gameState), shieldingTime(0), shrinkingTime(0) {
}

void Player::render() {

    // scale down with a factor of 2 if shrinking
    double scale = shrinkingTime ? 0.5 : 1;


    glPushMatrix();
    glTranslated(position.first, position.second, 0);
    glScaled(scale, scale, scale);
    glTranslated(-position.first, -position.second, 0);
    // Body
    if(shieldingTime)
        glColor3f(1.0f, 0.0f, 1.0f);
    else if (shrinkingTime)
		glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.2f, 0.6f, 1.0f);  // Light blue
    glBegin(GL_QUADS);
    glVertex2d(position.first, position.second);
    glVertex2d(position.first + width, position.second);
    glVertex2d(position.first + width, position.second + height);
    glVertex2d(position.first, position.second + height);
    glEnd();

    // Eyes
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_TRIANGLES);
    // Left eye
    glVertex2d(position.first + width * 0.3, position.second + height * 0.7);
    glVertex2d(position.first + width * 0.4, position.second + height * 0.8);
    glVertex2d(position.first + width * 0.2, position.second + height * 0.8);
    // Right eye
    glVertex2d(position.first + width * 0.7, position.second + height * 0.7);
    glVertex2d(position.first + width * 0.8, position.second + height * 0.8);
    glVertex2d(position.first + width * 0.6, position.second + height * 0.8);
    glEnd();

    // Mouth
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glBegin(GL_LINE_STRIP);
    glVertex2d(position.first + width * 0.3, position.second + height * 0.3);
    glVertex2d(position.first + width * 0.5, position.second + height * 0.2);
    glVertex2d(position.first + width * 0.7, position.second + height * 0.3);
    glEnd();

    // Antenna
    glColor3f(0.0f, 1.0f, 0.0f);  // Green
    glBegin(GL_LINES);
    glVertex2d(position.first + width * 0.5, position.second + height);
    glVertex2d(position.first + width * 0.5, position.second + height * 1.2);
    glEnd();
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2d(position.first + width * 0.5, position.second + height * 1.2);
    glEnd();
    glPopMatrix();
}

bool Player::isDucking()
{
	return height == ORIGINAL_PLAYER_HEIGHT /2;
}

void Player::jump()
{
	const double JUMP_HEIGHT = 200;
	if (position.second == gameState->getLowerBound() && !isDucking())
		position.second += JUMP_HEIGHT;
}

void Player::duck()
{
	if (position.second == gameState->getLowerBound())
		height = ORIGINAL_PLAYER_HEIGHT / 2;
}

void Player::unDuck()
{
	if (position.second == gameState->getLowerBound())
		height = ORIGINAL_PLAYER_HEIGHT;
}

void Player::applyGravity()
{
	const double MAX_GRAVITY = 10;   // Maximum gravity strength
	const double MIN_GRAVITY = 2; // Minimum gravity strength when at jump height

	// Calculate the player's height from the lower bound
	double distanceFromGround = position.second - gameState->getLowerBound();

	// Inversely proportional gravity (the closer to the ground, the stronger the gravity)
	// As distance decreases, gravity increases
	// MIN_GRAVITY + (MAX_GRAVITY - MIN_GRAVITY) x factor linearly interpolates between the two gravity strengths
	double gravityStrength = MIN_GRAVITY + (MAX_GRAVITY - MIN_GRAVITY) * (1 - distanceFromGround / 200.0);

	// Apply gravity, ensuring the player doesn't fall below the lower bound
	position.second = std::max(gameState->getLowerBound(), position.second - gravityStrength);
}

void Player::setShieldingTime(int time) {
    shieldingTime = time;
}

void Player::setShrinkingTime(int time) {
	shrinkingTime = time;
}

int Player::getShieldingTime() {
    return shieldingTime;
}

int Player::getShrinkingTime() {
    return shrinkingTime;
}

void Player::decreasePowerUpTime() {
    if (shieldingTime > 0) {
		shieldingTime--;
	}
    if (shrinkingTime > 0) {
		shrinkingTime--;
	}
}