/*
 * FractaleImage.h
 *
 *  Created on: 24 févr. 2013
 *      Author: oussama
 */

#ifndef FRACTALEIMAGE_H_
#define FRACTALEIMAGE_H_

#include <SFML/Graphics.hpp>
#include <stdint.h>

/**
 * Contains fractal pixels tab and methods
 * for setting pixels.
 */
class FractaleImage {
public:

    /**
     * Constructor
     * Allocates memory for the pixels.
     * @param width of the image
     * @param height of the image
     */
	FractaleImage(uint32_t width,
			      uint32_t height);

	/**
	 * Destructor.
	 * Deallocates pixels tab.
	 */
	virtual ~FractaleImage();

private:

	sf::Image image;
	sf::Sprite sprite;

	/**
	 * pixels tab
	 */
	sf::Uint8 * pixels;
};

#endif /* FRACTALEIMAGE_H_ */
