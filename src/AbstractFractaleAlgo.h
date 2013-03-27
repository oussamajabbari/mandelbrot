/*
 * AbstractFractaleAlgo.h
 *
 *  Created on: 23 mars 2013
 *      Author: oussama
 */

#ifndef ABSTRACTFRACTALEALGO_H_
#define ABSTRACTFRACTALEALGO_H_

#include "FractaleImage.h"

class AbstractFractaleAlgo {
public:

    /**
     * Constructor.
     */
    AbstractFractaleAlgo(FractaleImage& fractaleImage);

    /**
     * Destructor.
     */
    virtual ~AbstractFractaleAlgo();

    /**
     * Calculates the pixels of the fractal and fills the image.
     */
    virtual void calculate(double minX = -2.4,
                           double maxX =  1.2,
                           double minY = -1.5,
                           double maxY =  1.5) = 0;


protected:

    /**
     * Number of iterations of the algorithm that calculates the fractal.
     */
    static const unsigned int NB_ITERATIONS = 800;

    /**
     * Tab that will contains colors for a gradient.
     */
    static const unsigned int TAB_SIZE = NB_ITERATIONS;
    sf::Color colorTab[TAB_SIZE];
    //sf::Color colorTab[0];

    FractaleImage& fractaleImage;

private:
    /**
     * Fills the tab with gradient color.
     */
    void fillTabWithGradient();

};

#endif /* ABSTRACTFRACTALEALGO_H_ */
