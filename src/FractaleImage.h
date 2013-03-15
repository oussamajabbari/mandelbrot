/*
 * FractaleImage.h
 *
 *  Created on: 24 fevr. 2013
 *      Author: oussama
 */

#ifndef FRACTALEIMAGE_H_
#define FRACTALEIMAGE_H_

#include <stdexcept>

#include <SFML/Graphics.hpp>
#include <stdint.h>

using namespace std;

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
	FractaleImage(sf::Uint32 width,
			      sf::Uint32 height);

	/**
	 * Destructor.
	 * Deallocates pixels tab.
	 */
	virtual ~FractaleImage();

	/**
	 * Sets a pixel of the image.
	 * It checks that the position is coherent with the size,
	 * otherwise it throws an exception.
	 * @param xPos  : X Position
	 * @param yPos  : Y position
	 * @param color : color of the pixel
	 */
	void setPixel(sf::Uint32 xPos,
			      sf::Uint32 yPos,
			      sf::Color color) throw(out_of_range);

	/**
	 * Draws the fractal image to the SFML window.
	 * @param window
	 */
	void Draw(sf::RenderWindow& window);

private:

	/**
	 * Width and height of the image.
	 */
	sf::Uint32 width;
	sf::Uint32 height;

	/**
	 * SFML image and sprite objects.
	 */
	sf::Image image;
	sf::Sprite sprite;

	/**
	 * pixels tab
	 */
	sf::Uint8 * pixels;
};

#endif /* FRACTALEIMAGE_H_ */
