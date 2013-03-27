/*
 * JuliaFractaleAlgo.h
 *
 *  Created on: 15 mars 2013
 *      Author: oussama
 */

#ifndef JuliaFractaleAlgo_H_
#define JuliaFractaleAlgo_H_

#include "FractaleImage.h"
#include "AbstractFractaleAlgo.h"

/**
 * This classes calculated the pixels of the fractal.
 */
class JuliaFractaleAlgo : public AbstractFractaleAlgo {
public:

    /**
     * Constructor
     * @param fractaleImage : the object with pixels tab to be filled.
     */
    JuliaFractaleAlgo(FractaleImage& fractaleImage);

    /**
     * Destructor
     */
    virtual ~JuliaFractaleAlgo();

    /**
     * Calculates the pixels of the fractal and fills the image.
     */
    virtual void calculate(double minX = -2.4,
                           double maxX =  1.2,
                           double minY = -1.5,
                           double maxY =  1.5);

private:

};

#endif /* JuliaFractaleAlgo_H_ */
