/*
 * Texture.h
 *
 *  Created on: Jan 11, 2015
 *      Author: lemeryfertitta
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "lodepng.h"
#include <iostream>

namespace std {

class Texture {
public:
	Texture(string pFilepath);
	~Texture();
	int getID(void);
private:
	int aID;
};

} /* namespace std */

#endif /* TEXTURE_H_ */
