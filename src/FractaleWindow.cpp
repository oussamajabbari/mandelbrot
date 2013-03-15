/*
 * FractaleWindow.cpp
 *
 *  Created on: Feb 27, 2013
 *      Author: ousjab01
 */

#include "FractaleWindow.h"

/**
 * Constructor
 */
FractaleWindow::FractaleWindow(int a) :
    fractaleImage(width, height), app(VideoMode(width, height, 32), "Une belle fractale")
{
}

/**
 * Destructor
 */
FractaleWindow::~FractaleWindow() {
}

/**
 * Main method.
 * Opens window and does main sfml loop.
 */
void FractaleWindow::run() {

}
