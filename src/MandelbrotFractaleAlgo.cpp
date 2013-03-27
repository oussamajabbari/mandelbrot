/*
 * MandelbrotFractaleAlgo.cpp
 *
 *  Created on: 15 mars 2013
 *      Author: oussama
 */

#include <iostream>
#include <stdio.h>
#include "MandelbrotFractaleAlgo.h"

using namespace std;

/**
 * Constructor
 * @param fractaleImage : the object with pixels tab to be filled.
 */
MandelbrotFractaleAlgo::MandelbrotFractaleAlgo(FractaleImage& fractaleImage) :
        AbstractFractaleAlgo(fractaleImage)
{
}

/**
 * Destructor
 */
MandelbrotFractaleAlgo::~MandelbrotFractaleAlgo() {

}

/**
 * Calculates the pixels of the fractal and fills the image.
 */
void MandelbrotFractaleAlgo::calculate(double minX,
                             double maxX,
                             double minY,
                             double maxY)
{

    double RC, IC, RZ, IZ, R, I, module;

    for (double X = 0; X < 800; X++)
    {
        for (double Y = 0; Y < 600; Y++)
        {
            RC = minX + (maxX - minX)/800 * X;
            IC = minY + (maxY - minY)/600 * Y;

            RZ = 0;
            IZ = 0;

            uint32_t a;
            for (a = 0; a < NB_ITERATIONS; a++)
            {
                R = RZ;
                I = IZ;

                RZ = R*R - I*I + RC;
                IZ = 2* R*I + IC;

                module = RZ*RZ + IZ*IZ;
                if (module >= 4) {
                    break;
                }
            }

            if (a == NB_ITERATIONS) {
                fractaleImage.setPixel(X, Y, sf::Color(0, (module*255/4) + (4/(module*255)), 0, 255));
            }
            else {
                fractaleImage.setPixel(X, Y, colorTab[a]);
            }

        }
    }

}
