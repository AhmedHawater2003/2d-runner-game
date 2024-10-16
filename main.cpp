#include <Windows.h>
#include <glut.h>
#include "GameManager.h"

GameManager* gameManger;
const double GAME_WIDTH = 1000;
const double GAME_HEIGHT = 800;

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	gameManger->renderGame();
	glFlush();
}

void Timer(int value) {
	gameManger->onTimer();
	glutPostRedisplay(); 
	glutTimerFunc(10, Timer, 0);
}	

void Keyboard(unsigned char key, int x, int y) {
	gameManger->handleKeyboardDown(key);
	glutPostRedisplay();
}

void KeyboardUp(unsigned char key, int x, int y) {
	gameManger->handleKeyboardUp(key);
	glutPostRedisplay();
}





void main(int argc, char** argv) {
	gameManger = new GameManager(GAME_HEIGHT, GAME_WIDTH);

	glutInit(&argc, argv);

	glutInitWindowSize(GAME_WIDTH, GAME_HEIGHT);
	glutInitWindowPosition(0, 0);


	glutCreateWindow("Runner Game");
	glutDisplayFunc(Display);
	glutTimerFunc(10, Timer, 0);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyboardUp);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(7/255.0, 14/255.0, 23/255.0, 1.0f);
	gluOrtho2D(0, GAME_WIDTH, 0, GAME_HEIGHT);

	glutMainLoop();
}