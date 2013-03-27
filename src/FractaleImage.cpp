/*
 * FractaleImage.cpp
 *
 *  Created on: 24 fevr. 2013
 *      Author: oussama
 */

#include <iostream>
#include <sstream>
#include "FractaleImage.h"

using namespace std;

/**
 * Constructor
 * Allocates memory for the pixels.
 * @param width of the image
 * @param height of the image
 * @param app : SFML main window reference.
 */
FractaleImage::FractaleImage(sf::Uint32 width,
		                     sf::Uint32 height,
		                     sf::RenderWindow& app,
		                     int b) :
		        width(width),
		        height(height),
		        app(app),
				image(width, height, sf::Color(0, 0, 0)),
				sprite(image),
				b(b)
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

    cout << "Destructeur de FractaleImage" << endl;

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

    ostringstream oss;

	// Check pixel position
	if (xPos >= this->width) {
	    oss << "FractaleImage::setPixel : xPos is out of range : " << xPos;
		throw out_of_range(oss.str());
	}
	else if (yPos >= height) {
	    oss << "FractaleImage::setPixel : yPos is out of range : " << yPos;
		throw out_of_range(oss.str());
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
 */
void FractaleImage::Draw() {

	// Loads pixels tab to SFML Image object.
	image.LoadFromPixels(width, height, pixels);

	// Draw the image
	app.Draw(sprite);
}
