/*
 * AbstractFractaleAlgo.cpp
 *
 *  Created on: 23 mars 2013
 *      Author: oussama
 */

#include "AbstractFractaleAlgo.h"
#include "ColorScale.h"

#include <iostream>

using namespace std;

/**
 * Constructor.
 */
AbstractFractaleAlgo::AbstractFractaleAlgo(FractaleImage& fractaleImage) :
    fractaleImage(fractaleImage)
{
    // Fill color tab with a gradient color
    fillTabWithGradient();
}

/**
 * Destructor.
 */
AbstractFractaleAlgo::~AbstractFractaleAlgo() {
}

/**
 * Fills the tab with gradient color.
 */
void AbstractFractaleAlgo::fillTabWithGradient() {
    ColorScale gradient;

    // Choose colors for the gradient
    gradient.insert(0.0,sf::Color::Black);
    gradient.insert(1.0,sf::Color::Green);
    gradient.insert(2.0,sf::Color::Magenta);
    gradient.insert(3.0,sf::Color::Yellow);

    // Fill a table with this gradient
    gradient.fillTab(colorTab, TAB_SIZE);
}
