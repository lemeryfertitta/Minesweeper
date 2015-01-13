/*
 * Cell.h
 *
 *  Created on: Jan 10, 2015
 *      Author: lemeryfertitta
 */

#ifndef CELL_H_
#define CELL_H_

namespace std {

class Cell {
public:
	Cell(void);
	~Cell(void);
	bool uncover(void);
	void toggleFlag(void);
	void toggleMine(void);
	int getNeighbors(void);
	void addNeighbor(void);
	void removeNeighbor(void);
	bool isFlagged(void);
	bool isUncovered(void);
	bool hasMine(void);

private:
	bool aHasMine, aUncovered, aFlagged;
		int aNeighbors;
};


} /* namespace std */

#endif /* CELL_H_ */
