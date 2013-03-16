/*
 * FractaleAlgo.h
 *
 *  Created on: 15 mars 2013
 *      Author: oussama
 */

#ifndef FRACTALEALGO_H_
#define FRACTALEALGO_H_

#include "FractaleImage.h"

/**
 * This classes calculated the pixels of the fractal.
 */
class FractaleAlgo {
public:

    /**
     * Constructor
     * @param fractaleImage : the object with pixels tab to be filled.
     */
    FractaleAlgo(FractaleImage& fractaleImage);

    /**
     * Destructor
     */
    virtual ~FractaleAlgo();

    /**
     * Calculates the pixels of the fractal and fills the image.
     */
    void calculate(double minX = -2.4,
                   double maxX =  1.2,
                   double minY = -1.5,
                   double maxY =  1.5);

private:

    FractaleImage& fractaleImage;
    static const int NB_ITERATIONS = 255;
};

#endif /* FRACTALEALGO_H_ */
