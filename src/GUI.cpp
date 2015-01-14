/*
 * GUI.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: lemeryfertitta
 */

#include "GUI.h"

namespace std {

int cursorXPos, cursorYPos;
bool mouseRelease, mousePress, windowResized, enterPressed;


static void error_callback(int pError, const char* pDescription){
	cerr << pDescription;
}

static void key_callback(GLFWwindow* pWindow,
		int pKey, int pScancode, int pAction, int pMods){
	if (pKey == GLFW_KEY_ESCAPE && pAction == GLFW_PRESS){
		glfwSetWindowShouldClose(pWindow, GL_TRUE);
	}
	else if(pKey == GLFW_KEY_ENTER && pAction == GLFW_PRESS){
		enterPressed = true;
	}
}

static void mouse_button_callback(GLFWwindow* pWindow,
		int pButton, int pAction, int pMods){
	if(pAction == GLFW_RELEASE){
		mouseRelease = true;
	}
	else if(pAction == GLFW_PRESS){
		mousePress = true;
	}
}

static void cursor_pos_callback(GLFWwindow* pWindow,
		double pXPos, double pYPos){
	cursorXPos = pXPos;
	cursorYPos = pYPos;
}
static void window_resize_callback(	GLFWwindow * pWindow, int pWidth, int pHeight){
	windowResized = true;

}
pair<int,int> GUI::mouseToCell(){
	int x = ((double)cursorXPos/aWindowWidth)*aMinefield.getWidth();
	int y = aMinefield.getWidth() - ((double)cursorYPos/aWindowHeight)*aMinefield.getHeight();
	return make_pair(x,y);
}
void GUI::loadTextures(){
	for(int i = 0; i<aTextures.size(); i++){
		if(i < 9){
			stringstream ss;
			ss << "assets/png/tile_uncovered_" << i << ".png";
			Texture t (ss.str());
			aTextures[i] = t.getID();
		}
		else if(i == 9){
			Texture t ("assets/png/tile_covered_up.png");
			aTextures[i] = t.getID();
		}
		else if(i == 10){
			Texture t ("assets/png/tile_covered_down.png");
			aTextures[i] = t.getID();
		}
		else{
			Texture t ("assets/png/mine.png");
			aTextures[i] = t.getID();
		}

	}
}
void GUI::drawTile(int pX, int pY){
	double adjustedX = ((double)pX/aMinefield.getWidth())*(2) - 1;
	double adjustedY = ((double)pY/aMinefield.getHeight())*(2) - 1;

	if(aMinefield.isUncoveredAt(pX,pY)){
		if(aMinefield.isMineAt(pX,pY)){
			glBindTexture(GL_TEXTURE_2D,aTextures[11]);
		}
		else{
			switch(aMinefield.getNeighborsAt(pX,pY)){
			case 0:
				glBindTexture(GL_TEXTURE_2D,aTextures[0]);
				break;
			case 1:
				glBindTexture(GL_TEXTURE_2D,aTextures[1]);
				break;
			case 2:
				glBindTexture(GL_TEXTURE_2D,aTextures[2]);
				break;
			case 3:
				glBindTexture(GL_TEXTURE_2D,aTextures[3]);
				break;
			case 4:
				glBindTexture(GL_TEXTURE_2D,aTextures[4]);
				break;
			case 5:
				glBindTexture(GL_TEXTURE_2D,aTextures[5]);
				break;
			case 6:
				glBindTexture(GL_TEXTURE_2D,aTextures[6]);
				break;
			case 7:
				glBindTexture(GL_TEXTURE_2D,aTextures[7]);
				break;
			case 8:
				glBindTexture(GL_TEXTURE_2D,aTextures[8]);
				break;
			}
		}
	}
	else if(aTilePressed && (make_pair(pX,pY) == mouseToCell())){
		glBindTexture(GL_TEXTURE_2D,aTextures[9]);
	}
	else{
		glBindTexture(GL_TEXTURE_2D,aTextures[10]);
	}
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2d(0.0,1.0);
	glVertex2d(adjustedX,adjustedY);
	glTexCoord2d(1.0,1.0);
	glVertex2d(adjustedX+aTileWidth,adjustedY);
	glTexCoord2d(0.0,0.0);
	glVertex2d(adjustedX,adjustedY+aTileHeight);
	glTexCoord2d(1.0,0.0);
	glVertex2d(adjustedX+aTileWidth,adjustedY+aTileHeight);
	glEnd();
}
void GUI::drawAll(){
	for(int y = 0; y < aMinefield.getHeight(); y++){
		for(int x = 0; x < aMinefield.getWidth(); x++){
			drawTile(x,y);
		}
	}

}

void GUI::newGame(){
	aMinefield = Minefield(DEFAULT_ROWS,DEFAULT_COLUMNS,DEFAULT_MINES);
}

GUI::GUI() : aMinefield(DEFAULT_ROWS,DEFAULT_COLUMNS,DEFAULT_MINES), aTextures(12) {
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	aWindowHeight = DEFAULT_HEIGHT;
	aWindowWidth  = DEFAULT_WIDTH;
	aWindow = glfwCreateWindow(aWindowWidth, aWindowHeight, "Minesweeper", NULL, NULL);
	if (!aWindow)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(aWindow);
	// --- SETUP CALLBACKS ---
	glfwSetKeyCallback(aWindow, key_callback);
	glfwSetMouseButtonCallback(aWindow, mouse_button_callback);
	glfwSetCursorPosCallback(aWindow, cursor_pos_callback);
	glfwSetWindowSizeCallback(aWindow, window_resize_callback);
	// -----------------------
	aTileWidth = (double)2/(aMinefield.getWidth());
	aTileHeight = (double)2/(aMinefield.getHeight());
	aWindowIsDirty = true;
	bool gameOver = false;
	bool firstClick = true;
	glEnable(GL_TEXTURE_2D);
	loadTextures();
	while ((!glfwWindowShouldClose(aWindow))){
		if(aWindowIsDirty){
			glClear(GL_COLOR_BUFFER_BIT);
			drawAll();
			aWindowIsDirty = false;
			glfwSwapBuffers(aWindow);
		}
		glfwPollEvents();
		if(mousePress){
			aTilePressed = true;
			mousePress = false;
			aWindowIsDirty = true;
		}
		else if(mouseRelease){
			pair<int,int> cellCoords = mouseToCell();
			if(firstClick){
				aMinefield.moveMineAt(cellCoords.first,cellCoords.second);
				firstClick = false;
			}
			gameOver = aMinefield.uncoverAt(cellCoords.first,cellCoords.second);
			if(gameOver){ aMinefield.uncoverAll();}
			aWindowIsDirty = true;
			aTilePressed = false;
			mouseRelease = false;
		}
		if(windowResized){
			glfwGetWindowSize(aWindow, &aWindowWidth, &aWindowHeight);
			aWindowIsDirty = true;
			windowResized = false;
		}
		if(enterPressed){
			newGame();
			aWindowIsDirty = true;
			enterPressed = false;
		}
	}
	glfwDestroyWindow(aWindow);
	glfwTerminate();
	exit(EXIT_SUCCESS);

}

GUI::~GUI() { }

} /* namespace std */
