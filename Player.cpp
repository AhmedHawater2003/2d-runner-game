#include "Player.h"
#include <cmath>
#include <glut.h>

Player::Player(std::pair<double, double> position, GameState* gameState)
	: BoundingBox(position, ORIGINAL_PLAYER_WIDTH, ORIGINAL_PLAYER_HEIGHT),
	gameState(gameState), shieldingTime(0), shrinkingTime(0) {
}

void Player::render() {
	// scale down with a factor of 0.6 if shrinking
	scale = shrinkingTime ? 0.6 : 1;

	width = scale * ORIGINAL_PLAYER_WIDTH;
	height = scale * ORIGINAL_PLAYER_HEIGHT;

	const double centerX = position.first + width / 2;
	const double centerY = position.second + height / 2;
	const double radius = std::min(width, height) / 2;  // Approximate ball radius

	glPushMatrix();

	// Ducking alien: flattened disc shape
	if (isDucking) {

		height = height * 0.4; // 40% of original height when ducking or shrinking
		const double flattenedCenterY = position.second + height / 2;

		// 1. Flattened body (using GL_TRIANGLE_FAN for smooth edges)
		if (shieldingTime)
			glColor4f(0.2f, 0.8f, 1.0f, 1.0f);
		else
			glColor3f(0.5f, 0.8f, 0.2f);  // Bright green

		glBegin(GL_TRIANGLE_FAN);
		glVertex2d(centerX, flattenedCenterY); // Center of the flattened alien
		for (int i = 0; i <= 40; ++i) {
			double angle = 2.0 * 3.14 * i / 40;
			double dx = cos(angle) * width / 2;
			double dy = sin(angle) * height / 2;
			glVertex2d(centerX + dx, flattenedCenterY + dy);
		}
		glEnd();

		// 2. Eyes (using GL_TRIANGLES for alien-like appearance)
		glColor3f(0.0f, 0.0f, 0.0f);  // Black
		glBegin(GL_TRIANGLES);
		// Left eye
		glVertex2d(centerX - width * 0.2, flattenedCenterY);
		glVertex2d(centerX - width * 0.1, flattenedCenterY + height * 0.2);
		glVertex2d(centerX - width * 0.1, flattenedCenterY - height * 0.2);
		// Right eye
		glVertex2d(centerX + width * 0.2, flattenedCenterY);
		glVertex2d(centerX + width * 0.1, flattenedCenterY + height * 0.2);
		glVertex2d(centerX + width * 0.1, flattenedCenterY - height * 0.2);
		glEnd();

		// 3. Mouth (using GL_LINE_STRIP)
		glColor3f(0.0f, 0.0f, 0.0f);  // Black
		glBegin(GL_LINE_STRIP);
		glVertex2d(centerX - width * 0.15, flattenedCenterY);
		glVertex2d(centerX, flattenedCenterY - height * 0.1);
		glVertex2d(centerX + width * 0.15, flattenedCenterY);
		glEnd();

		// 4. Antennae in both states (using GL_LINES)
		glColor3f(0.5f, 0.8f, 0.2f);  // Bright green
		glBegin(GL_LINES);
		// Left antenna
		glVertex2d(centerX - radius * 0.5, centerY);
		glVertex2d(centerX - radius * 0.7, centerY + 5);
		// Right antenna
		glVertex2d(centerX + radius * 0.5, centerY);
		glVertex2d(centerX + radius * 0.7, centerY + 5);
		glEnd();

	}

	// Normal alien appearance
	else {

		// 1. Head outline (using GL_TRIANGLE_FAN for smooth edges)
		if (shieldingTime)
			glColor4f(0.2f, 0.8f, 1.0f, 1.0f);
		else
			glColor3f(0.5f, 0.8f, 0.2f);  // Bright green

		height = scale * ORIGINAL_PLAYER_HEIGHT; // Return back the player original height

		glBegin(GL_TRIANGLE_FAN);
		glVertex2d(centerX, centerY); // Center of the Alien
		for (int i = 0; i <= 20; ++i) {
			double angle = 2.0 * 3.14 * i / 20;
			double dx = cos(angle) * radius;
			double dy = sin(angle) * radius;
			glVertex2d(centerX + dx, centerY + dy);
		}
		glEnd();

		// 2. Eyes (using GL_TRIANGLES for more alien-like appearance)
		glColor3f(0.0f, 0.0f, 0.0f);  // Black
		glBegin(GL_TRIANGLES);
		// Left eye
		glVertex2d(position.first + width * 0.25, position.second + height * 0.6);
		glVertex2d(position.first + width * 0.4, position.second + height * 0.7);
		glVertex2d(position.first + width * 0.4, position.second + height * 0.5);
		// Right eye
		glVertex2d(position.first + width * 0.75, position.second + height * 0.6);
		glVertex2d(position.first + width * 0.6, position.second + height * 0.7);
		glVertex2d(position.first + width * 0.6, position.second + height * 0.5);
		glEnd();

		// 3. Mouth (using GL_LINE_STRIP)
		glColor3f(0.0f, 0.0f, 0.0f);  // Black
		glBegin(GL_LINE_STRIP);
		glVertex2d(position.first + width * 0.35, position.second + height * 0.3);
		glVertex2d(position.first + width * 0.5, position.second + height * 0.25);
		glVertex2d(position.first + width * 0.65, position.second + height * 0.3);
		glEnd();

		// 4. Antennae (using GL_LINES)
		glColor3f(0.5f, 0.8f, 0.2f);  // Bright green
		glBegin(GL_LINES);
		// Left antenna
		glVertex2d(centerX - radius * 0.5, centerY + radius);
		glVertex2d(centerX - radius * 0.7, centerY + radius * 1.5);
		// Right antenna
		glVertex2d(centerX + radius * 0.5, centerY + radius);
		glVertex2d(centerX + radius * 0.7, centerY + radius * 1.5);
		glEnd();
	}

	glPopMatrix();
}

void Player::jump() {
	if (position.second == gameState->getLowerBound() && !isDucking) {
		isJumping = true;
		if (shrinkingTime)
			verticalVelocity = JUMP_INITIAL_VELOCITY * 1.1;
		else
			verticalVelocity = JUMP_INITIAL_VELOCITY;
	}
}

void Player::duck()
{
	if (position.second == gameState->getLowerBound() && !shrinkingTime)
		isDucking = true;
}

void Player::unDuck()
{
	if (position.second == gameState->getLowerBound())
		isDucking = false;
}


void Player::applyGravity() {
	const double deltaTime = 1.0 / 60.0;  // Assuming 30 FPS

	if (isJumping) {
		// Update velocity and position using physics formulas
		verticalVelocity += gameState->gravity * deltaTime;
		position.second += verticalVelocity * deltaTime;

		// Check if player has landed
		if (position.second <= gameState->getLowerBound()) {
			position.second = gameState->getLowerBound();
			verticalVelocity = 0;
			isJumping = false;
		}
	}
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