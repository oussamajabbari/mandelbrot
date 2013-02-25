
#include <stdint.h>
#include <iostream>
#include "FractaleImage.h"

using namespace std;

int main()
{
	uint8_t a;
	uint32_t *tab = new uint32_t[100];

	FractaleImage myFractale = new FractaleImage(800, 600);

	cout << "hello" << endl;

	delete myFractale;
    delete [] tab;

	return 0;
}
