/*
 * FractaleImage.h
 *
 *  Created on: 24 févr. 2013
 *      Author: oussama
 */

#ifndef FRACTALEIMAGE_H_
#define FRACTALEIMAGE_H_

#include <SFML/Graphics.hpp>

class FractaleImage {
public:
	FractaleImage();
	virtual ~FractaleImage();

private:
	sf::Image df;
	sf::Sprite dd;


};

#endif /* FRACTALEIMAGE_H_ */
