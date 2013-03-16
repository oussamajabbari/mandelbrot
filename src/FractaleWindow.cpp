/*
 * FractaleWindow.cpp
 *
 *  Created on: Feb 27, 2013
 *      Author: ousjab01
 */

#include <iostream>
#include "FractaleWindow.h"

using namespace std;

/**
 * Constructor
 */
FractaleWindow::FractaleWindow() :
    app(VideoMode(width, height, 32), "Une belle fractale"),
    fractaleImage(width, height, app),
    fractaleAlgo(fractaleImage)
{
    // Activate vertical synchronization in order to have
    // 60 frame/second
    app.UseVerticalSync(true);
}

/**
 * Destructor
 */
FractaleWindow::~FractaleWindow() {
}

/**
 * Main method.
 * Opens window and does main SFML loop.
 */
void FractaleWindow::run() {

    float minX = -2.4;
    float maxX =  1.2;
    float minY = -1.5;
    float maxY =  1.5;

    // Calculate the pixels
    fractaleAlgo.calculate(minX, maxX, minY, maxY);

    // Clear the screen
    app.Clear(sf::Color::White);

    // Draw the fractal
    fractaleImage.Draw();

    // Main loop
    while (app.IsOpened())
    {
        Event event;
        while (app.GetEvent(event))
        {
            // Close the window
            if (event.Type == Event::Closed)
                app.Close();

            // Mouse clic handle
            if (event.Type == sf::Event::MouseButtonPressed)
            {
                cout << "clic : " << event.MouseButton.X
                                  << " "
                                  << event.MouseButton.Y
                                  << endl;

                minX = -2.4 + event.MouseButton.X * 3.6 / 800 - (maxX - minX)/3;
                maxX = -2.4 + event.MouseButton.X * 3.6 / 800 + (maxX - minX)/3;
                minY = -1.5 + event.MouseButton.Y * 3.0 / 600 - (maxY - minY)/3;
                maxY = -1.5 + event.MouseButton.Y * 3.0 / 600 + (maxY - minY)/3;

                // Calculate, clear and draw
                fractaleAlgo.calculate(minX, maxX, minY, maxY);
                app.Clear(sf::Color::White);
                fractaleImage.Draw();

            }
        }

        // Get frame rate
        float Framerate = 1.f / app.GetFrameTime();
        //cout << "Framerate : " << Framerate << endl;

        // Display window content
        app.Display();

    }

}
