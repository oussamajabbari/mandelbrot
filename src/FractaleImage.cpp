/*
 * FractaleImage.cpp
 *
 *  Created on: 24 fevr. 2013
 *      Author: oussama
 */

#include "FractaleImage.h"

/**
 * Constructor
 * Allocates memory for the pixels.
 * @param width of the image
 * @param height of the image
 */
FractaleImage::FractaleImage(uint32_t width,
	      uint32_t height) {

	// Allocate memory for the pixel tab
	pixels = new sf::Uint8[4 * width * height];

}

/**
 * Destructor.
 * Deallocates pixels tab.
 */
FractaleImage::~FractaleImage() {

	// Deallocate memory
	delete [] pixels;

}

