/*
 * FractaleWindow.cpp
 *
 *  Created on: Feb 27, 2013
 *      Author: ousjab01
 */

#include "FractaleWindow.h"

/**
 * Constructor
 */
FractaleWindow::FractaleWindow() :
    fractaleImage(width, height),
    app(VideoMode(width, height, 32), "Une belle fractale")
{
}

/**
 * Destructor
 */
FractaleWindow::~FractaleWindow() {
}

/**
 * Main method.
 * Opens window and does main sfml loop.
 */
void FractaleWindow::run() {

    // Main loop
    while (app.IsOpened())
    {
        Event event;
        while (app.GetEvent(event))
        {
            // Close the window
            if (event.Type == Event::Closed)
                app.Close();
        }

        // Get frame rate
        float Framerate = 1.f / app.GetFrameTime();
        //cout << "Framerate : " << Framerate << endl;

        // Clear th screen
        app.Clear();

        // Draw the image
        fractaleImage.Draw(app);

        // Display window content
        app.Display();

    }

}
