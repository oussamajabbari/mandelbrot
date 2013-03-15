/*
 * FractaleWindow.h
 *
 *  Created on: Feb 27, 2013
 *      Author: ousjab01
 */

#ifndef FRACTALEWINDOW_H_
#define FRACTALEWINDOW_H_

#include "FractaleImage.h"

namespace {
    const int width = 800;
    const int height = 600;
}

using namespace sf;

/**
 * Main class for SFML window handling.
 */
class FractaleWindow {
public:

	/**
	 * Constructor
	 */
	FractaleWindow();

	/**
	 * Destructor
	 */
	virtual ~FractaleWindow();

	/**
	 * Main method.
	 * Opens window and does main sfml loop.
	 */
	void run();

private:

	/**
	 * This will contain the fractal image.
	 */
	FractaleImage fractaleImage;

	/**
	 * This is the main SFML rendering window.
	 */
	RenderWindow app;

};

#endif /* FRACTALEWINDOW_H_ */
