/*
 * FractaleImage.cpp
 *
 *  Created on: 24 fevr. 2013
 *      Author: oussama
 */

#include <iostream>
#include "FractaleImage.h"

using namespace std;

/**
 * Constructor
 * Allocates memory for the pixels.
 * @param width of the image
 * @param height of the image
 */
FractaleImage::FractaleImage(sf::Uint32 width,
		                     sf::Uint32 height) :
		        width(width),
		        height(height),
				image(width, height, sf::Color(0, 0, 0)),
				sprite(image)
{

	// Allocate memory for the pixel tab
	try	{
		pixels = new sf::Uint8[4 * width * height];
	}
	catch( const std::bad_alloc & )	{
		cerr << "FractaleImage constructor : failed to allocate pixel tab memory." << endl;
		throw;
	}
}

/**
 * Destructor.
 * Deallocates pixels tab.
 */
FractaleImage::~FractaleImage() {

	// Deallocate memory
	delete [] pixels;
}

/**
 * Sets a pixel of the image.
 * It checks that the position is coherent with the size,
 * otherwise it throws an exception.
 * @param xPos  : X Position
 * @param yPos  : Y position
 * @param color : color of the pixel
 */
void FractaleImage::setPixel(sf::Uint32 xPos, sf::Uint32 yPos,
		sf::Color color) throw(out_of_range) {

	// Check pixel position
	if (xPos >= width) {
		throw out_of_range("FractaleImage::setPixel : xPos is out of range : " + xPos);
	}
	else if (yPos >= height) {
		throw out_of_range("FractaleImage::setPixel : yPos is out of range : " + yPos);
	}
	else {
		pixels[4 * (yPos * width + xPos)]     = color.r;   // R
		pixels[4 * (yPos * width + xPos) + 1] = color.g;   // G
		pixels[4 * (yPos * width + xPos) + 2] = color.b;   // B
		pixels[4 * (yPos * width + xPos) + 3] = color.a;   // A
	}
}

/**
 * Draws the fractal image to the SFML window.
 * @param window
 */
void FractaleImage::Draw(sf::RenderWindow& window) {

	// Loads pixels tab to SFML Image object.
	image.LoadFromPixels(width, height, pixels);

	// Draw the image
	window.Draw(sprite);
}
