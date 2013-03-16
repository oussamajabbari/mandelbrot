/*
 * FractaleAlgo.cpp
 *
 *  Created on: 15 mars 2013
 *      Author: oussama
 */

#include <iostream>
#include "FractaleAlgo.h"

using namespace std;

/**
 * Constructor
 * @param fractaleImage : the object with pixels tab to be filled.
 */
FractaleAlgo::FractaleAlgo(FractaleImage& fractaleImage) :
        fractaleImage(fractaleImage)
{

}

/**
 * Destructor
 */
FractaleAlgo::~FractaleAlgo() {

}

/**
 * Calculates the pixels of the fractal and fills the image.
 */
void FractaleAlgo::calculate(float minX,
                             float maxX,
                             float minY,
                             float maxY)
{


    float RC, IC, RZ, IZ, R, I, module;

    for (float X = 0; X < 800; X++)
    {
        for (float Y = 0; Y < 600; Y++)
        {
            RC = minX + (maxX - minX)/800 * X;
            IC = minY + (maxY - minY)/600 * Y;

            RZ = 0;
            IZ = 0;

            float a;
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
                fractaleImage.setPixel(X, Y, sf::Color(0, 0, (module*255/4) + (4/(module*255)), 255));
                //fractaleImage.setPixel(X, Y, sf::Color(0, 0, module*255/4, 255));
                //fractaleImage.setPixel(X, Y, sf::Color(0, 0, (4/(module*255)), 255));
            }
            else
                fractaleImage.setPixel(X, Y, sf::Color(a*255/16, 0, 0, 255));

        }
    }

}
