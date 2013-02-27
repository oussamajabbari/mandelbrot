
#include <stdint.h>
#include <iostream>
#include "FractaleImage.h"
#include "FractaleWindow.h"

using namespace std;

int main()
{
	uint8_t a;
	uint32_t *tab = new uint32_t[100];

	FractaleImage myFractale(800, 600);
	FractaleWindow * mw = new FractaleWindow(10);

	cout << "hello" << endl;

    delete [] tab;

	return 0;
}
