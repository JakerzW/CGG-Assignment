
#include <cmath>

#include "CGG_Main.h"



int main(int argc, char *argv[])
{
	// Variables for storing window dimensions
	int windowWidth = 1280;
	int windowHeight = 720;

	// Call CGG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if( !CGG::Init( windowWidth, windowHeight ) )
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGBA, numbers are from 0 to 255
	CGG::SetBackground( 0,0,0 );

	// Preparing a position to draw a pixel
	int pixelX = windowWidth / 2;
	int pixelY = windowHeight / 2;

	// Preparing a colour to draw
	int red = 255;
	int green = 0;
	int blue = 0;

	
	// Draws a single pixel at the specified coordinates in the specified colour!
	CGG::DrawPixel( pixelX, pixelY, red, green, blue );
	
	for (size_t i = 0; i < 100; i++)
	{
		pixelX++;
		pixelY++;
		CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}
	/*int sinx, siny;
	for (int i = 0; i < 360; i++)
	{
		siny = sin(i);
		pixelX = i;
		pixelY = siny;
		CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}*/


	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	return CGG::ShowAndHold();
	
	

	
	
	// Advanced access - comment out the above DrawPixel and CGG::ShowAndHold lines, then uncomment the following:

	/*
	// Variable to keep track of time
	float timer = 0.0f;

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( CGG::ProcessFrame() )
	{
		// Set every pixel to the same colour
		CGG::SetBackground( 0,0,0 );
		
		// Change our pixel's X coordinate according to time
		pixelX = (windowWidth / 2) + (int)(sin(timer) * 100.0f);
		// Update our time variable
		timer += 1.0f / 60.0f;

		// Draw the pixel to the screen
		CGG::DrawPixel( pixelX, pixelY, red, green, blue );

	}
	
	return 0;
	*/
	
}

void menu()
{
	
}

void setBackgroundColour()
{
	//enter case statement for choosing colour (maybe like 5/6 options)
	CGG::SetBackground(0, 0, 0);
}

void setLineColour()
{
	//same as background colour
	int red = 255;
	int green = 0;
	int blue = 0;
}

void prepareToDraw()
{
	int windowWidth = 1280;
	int windowHeight = 720;
	int pixelX = windowWidth / 2;
	int pixelY = windowHeight / 2;
	
}