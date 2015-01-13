/*
 * Minefield.h
 *
 *  Created on: Jan 10, 2015
 *      Author: lemeryfertitta
 */

#ifndef MINEFIELD_H_
#define MINEFIELD_H_

#include "Cell.h"

#include <vector>
#include <utility>
#include <cstdlib>

namespace std {

class Minefield {
public:
	Minefield(int pWidth, int pHeight, int pNumOfMines);
	~Minefield(void);
	int getWidth(void);
	int getHeight(void);
	bool isFlaggedAt(int pX, int pY);
	bool isUncoveredAt(int pX, int pY);
	bool isMineAt(int pX, int pY);
	int getNeighborsAt(int pX, int pY);
	bool uncoverAt(int pX, int pY);
	void moveMineAt(int pX, int pY);
private:
	vector < vector<Cell> > aCells;
	int aWidth, aHeight, aNumOfMines;
	void addMine(void);
	void removeMineAt(int pX, int pY);
};

} /* namespace std */

#endif /* MINEFIELD_H_ */
