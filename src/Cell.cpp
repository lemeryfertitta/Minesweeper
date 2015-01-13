/*
 * Cell.cpp
 *
 *  Created on: Jan 10, 2015
 *      Author: lemeryfertitta
 */

#include "Cell.h"

namespace std {

bool Cell::uncover(void){
	aUncovered = true;
	return aHasMine;
}

void Cell::toggleMine(void){
	aHasMine = !aHasMine;
}

void Cell::toggleFlag(void){
	aFlagged = !aFlagged;
}

int Cell::getNeighbors(void){
	return aNeighbors;
}
void Cell::addNeighbor(void){
	aNeighbors += 1;
}
void Cell::removeNeighbor(void){
	aNeighbors -= 1;
}

bool Cell::isFlagged(void){
	return aFlagged;
}

bool Cell::isUncovered(void){
	return aUncovered;
}

bool Cell::hasMine(void){
	return aHasMine;
}

Cell::Cell(void){
	aHasMine = false;
	aUncovered = false;
	aFlagged = false;
	aNeighbors = 0;
}

Cell::~Cell(void) { }


} /* namespace std */
