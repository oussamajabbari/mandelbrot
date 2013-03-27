/*
 * MandelbrotFractaleAlgo.h
 *
 *  Created on: 15 mars 2013
 *      Author: oussama
 */

#ifndef MandelbrotFractaleAlgo_H_
#define MandelbrotFractaleAlgo_H_

#include "FractaleImage.h"
#include "AbstractFractaleAlgo.h"

/**
 * This classes calculated the pixels of the fractal.
 */
class MandelbrotFractaleAlgo : public AbstractFractaleAlgo {
public:

    /**
     * Constructor
     * @param fractaleImage : the object with pixels tab to be filled.
     */
    MandelbrotFractaleAlgo(FractaleImage& fractaleImage);

    /**
     * Destructor
     */
    virtual ~MandelbrotFractaleAlgo();

    /**
     * Calculates the pixels of the fractal and fills the image.
     */
    virtual void calculate(double minX = -2.4,
                           double maxX =  1.2,
                           double minY = -1.5,
                           double maxY =  1.5);

private:

};

#endif /* MandelbrotFractaleAlgo_H_ */
