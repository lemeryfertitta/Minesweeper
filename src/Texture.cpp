/*
 * Texture.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: lemeryfertitta
 */

#include "Texture.h"

namespace std {

int Texture::getID(){
	return aID;
}

Texture::Texture(string pFilepath) {
	  vector<unsigned char> image;
	  unsigned width, height;
	  unsigned error = lodepng::decode(image, width, height, pFilepath);

	  if(error != 0){
	    cout << "error " << error << ": " << lodepng_error_text(error) << endl;
	    exit(1);
	  }
	  unsigned int texture[1];
	  glGenTextures(1, &texture[0]);
	  glBindTexture(GL_TEXTURE_2D, texture[0]);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);


	  aID = texture[0];
}

Texture::~Texture() { }

} /* namespace std */
