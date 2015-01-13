/*
 * Minefield.cpp
 *
 *  Created on: Jan 10, 2015
 *      Author: lemeryfertitta
 */

#include "Minefield.h"
#include <iostream>

namespace std {

int Minefield::getWidth(void){
	return aWidth;
}
int Minefield::getHeight(void){
	return aHeight;
}
bool Minefield::isUncoveredAt(int pX, int pY){
	return aCells.at(pX).at(pY).isUncovered();
}
bool Minefield::isFlaggedAt(int pX, int pY){
	return aCells.at(pX).at(pY).isFlagged();
}
bool Minefield::isMineAt(int pX, int pY){
	return aCells.at(pX).at(pY).hasMine();
}
int Minefield::getNeighborsAt(int pX, int pY){
	return aCells.at(pX).at(pY).getNeighbors();
}
void Minefield::moveMineAt(int pX, int pY){
	if(!isMineAt(pX,pY)){ return; }
	addMine();
	removeMineAt(pX,pY);

}
void Minefield::removeMineAt(int pX, int pY){
	aCells.at(pX).at(pY).toggleMine();
	for(int dy = -1; dy < 2; dy++){
		for(int dx = -1; dx <2; dx++){
			if(dx == 0 && dy == 0){ continue; }
			int xx = dx + pX;
			int yy = dy + pY;
			if((xx < 0) || ((xx) == aWidth) ||
					(yy < 0) || (yy == aHeight)){ continue; }
			aCells.at(xx).at(yy).removeNeighbor();
		}
	}
}
void Minefield::addMine(void){
	srand ( time(NULL) );
	bool mineAdded = false;
	while(!mineAdded){
		int x  = rand() % (aWidth-1);
		int y  = rand() % (aHeight-1);
		if(!aCells.at(x).at(y).hasMine()){
			mineAdded = true;
			aCells.at(x).at(y).toggleMine();
			for(int dy = -1; dy < 2; dy++){
				for(int dx = -1; dx <2; dx++){
					if(dx == 0 && dy == 0){ continue; }
					int xx = dx + x;
					int yy = dy + y;
					if((xx < 0) || ((xx) == aWidth) ||
							(yy < 0) || (yy == aHeight)){ continue; }
					aCells.at(xx).at(yy).addNeighbor();
				}
			}
		}
	}
}
bool Minefield::uncoverAt(int pX, int pY){
	if(aCells.at(pX).at(pY).uncover()){
		return true;
	}
	/* if this cell has no neighbors with mines,
	 	 we uncover all neighboring cells.*/
	if(aCells.at(pX).at(pY).getNeighbors() == 0){
		for(int dy = -1; dy < 2; dy++){
			for(int dx = -1; dx <2; dx++){
				if(dx == 0 && dy == 0){ continue; }
				int xx = dx + pX;
				int yy = dy + pY;
				if((xx < 0) || ((xx) == aWidth) ||
						(yy < 0) || (yy == aHeight)){ continue; }
				if(aCells.at(xx).at(yy).isUncovered()){ continue; }
				uncoverAt(xx,yy);
			}
		}
	}
	return false;
}

Minefield::Minefield(int pWidth, int pHeight, int pNumOfMines)
	: aCells(pWidth, vector<Cell>(pHeight, Cell()))	{
	aWidth = pWidth;
	aHeight = pHeight;
	aNumOfMines = pNumOfMines;
	for(int i = 0; i < aNumOfMines; i++){
		addMine();
	}
}

Minefield::~Minefield() {

}

} /* namespace std */


