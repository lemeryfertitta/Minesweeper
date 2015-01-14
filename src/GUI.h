/*
 * GUI.h
 *
 *  Created on: Jan 11, 2015
 *      Author: lemeryfertitta
 */

#ifndef GUI_H_
#define GUI_H_
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Minefield.h"
#include "Texture.h"
#include <tuple>
#include <vector>

namespace std {

class GUI {
private:
	GLFWwindow* aWindow;
	bool aWindowIsDirty;
	Minefield aMinefield;
	double aTileWidth, aTileHeight;
	vector<int> aTextures;
	bool aTilePressed;
	int aWindowWidth, aWindowHeight;
public:
	static const int DEFAULT_WIDTH = 640, DEFAULT_HEIGHT = 480,
					DEFAULT_ROWS = 20, DEFAULT_COLUMNS = 20,
					DEFAULT_MINES = 50;
	void drawTile(int pX, int pY);
	void drawAll(void);
	void loadTextures(void);
	void newGame(void);
	pair<int,int> mouseToCell(void);
	GUI();
	~GUI();
};

} /* namespace std */

#endif /* GUI_H_ */
