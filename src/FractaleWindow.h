/*
 * FractaleWindow.h
 *
 *  Created on: Feb 27, 2013
 *      Author: ousjab01
 */

#ifndef FRACTALEWINDOW_H_
#define FRACTALEWINDOW_H_

#include "FractaleImage.h"

/*
 *
 */
class FractaleWindow {
public:
	FractaleWindow();
	virtual ~FractaleWindow();

	void run();

private:
	FractaleImage fractaleImage;
};

#endif /* FRACTALEWINDOW_H_ */
