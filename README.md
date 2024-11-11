# Alien Runner 🚀👾

A 2D infinite runner game built with OpenGL and C++, where you control an alien dodging obstacles and collecting items in space! Designed as part of the Computer Graphics coursework, this project demonstrates strong foundational skills in graphics programming, gameplay mechanics, and game design.

## Table of Contents
- [Game Overview](#game-overview)
- [Features](#features)
- [Controls](#controls)
- [Gameplay Elements](#gameplay-elements)
- [Technical Details](#technical-details)
- [Setup & Installation](#setup--installation)
- [Future Improvements](#future-improvements)
- [Contact](#contact)

## Game Overview
Alien Runner is a side-scrolling endless runner where the player is an alien navigating through space, dodging obstacles and collecting items to boost their score. The game features increasing difficulty, a responsive health system, and animated collectibles and power-ups.

![Screenshot of Alien Runner]()

## Features
- **Space Theme**: Immersive alien player model and galactic background.
- **Health, Score & Time**: Track your health visually with a health bar, score points by collecting items, and race against the clock.
- **Responsive Controls**: Jump and duck to avoid obstacles with intuitive keyboard controls.
- **Sound Effects**: Background music and unique sound effects for different actions.
- **Animated Collectibles & Power-Ups**: Engaging animations for objects with varying effects on gameplay.

## Controls
- **Jump**: `Space` or `W` key
- **Duck**: `S` key

## Gameplay Elements
### Obstacles
Obstacles of varying heights appear from the right side of the screen, challenging players to jump or duck. Colliding with an obstacle reduces health.

### Collectibles
Collectibles are placed throughout the course. Each collectible increases the score upon collision and disappears after being collected.

### Power-Ups
Two types of power-ups offer temporary boosts with visual and sound effects, adding a strategic element to the gameplay.

## Technical Details
- **Language**: C++
- **Framework**: OpenGL
- **Graphics**: Custom alien character and items designed with OpenGL primitives.
- **Animations**: Dynamic animations for collectibles and background.
- **Sound**: Custom sound effects for game actions (collect, collide, win, and loss) and continuous background music.
- **Game Logic**: Progressive difficulty scaling with increasing game speed, health depletion on collision, and timed game end.

## Setup & Installation
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/alien-runner.git
   cd alien-runner
   ```
2. **Build the Project**:
   Ensure OpenGL and required libraries are installed, then compile the `.cpp` file:
   ```bash
   g++ -o AlienRunner AlienRunner.cpp -lGL -lGLU -lglut
   ./AlienRunner
   ```
3. **Run the Game**:
   Run the executable to start the game.

## Future Improvements
- **Enhanced Graphics**: Adding textures for more realistic visuals.
- **Multiplayer Mode**: Allow multiple players to compete.
- **Additional Power-Ups**: More variety in gameplay.
