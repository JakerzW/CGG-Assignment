
#include <cmath>
#include <iostream>
#include <iomanip>
#include "CGG_Main.h"

int menu();

void setLineColour();
void setBackgroundColour();

int prepareToDraw(int shapeNumber);

void drawVerticalLine(int startPointX, int startPointY, bool directionUp, int size);
void drawHorizontalLine(int startPointX, int startPointY, bool directionRight, int size);
void drawSquare(int startPointX, int startPointY, int size);
void drawLine(int startPointX, int startPointY, int size );
void drawTriangle(int startPointX, int startPointY, int size);
void drawCircle(int startPointX, int startPointY, int size);

int red, green, blue, pixelX, pixelY;
int windowWidth = 640;
int windowHeight = 640;

int main(int argc, char *argv[])
{
	// Variables for storing window dimensions
	int windowWidth = 640;
	int windowHeight = 640;
	int menuChoice;
	// Call CGG::Init to initialise and create your window
	// Tell it what size you want the window to be
	
	menu();
}

int menu()
{
	int menuChoice;
	system("CLS");
	//shape ascii lettering
	std::cout << " ___  _   _    __    ____  ____  ___\n";
	std::cout << "/ __)( )_( )  /__\\  (  _ \\( ___)/ __)\n";
	std::cout << "\\__ \\ ) _ (  /(__)\\  )___/ )__) \\__ \\\n";
	std::cout << "(___/(_) (_)(__)(__)(__)  (____)(___/";
	std::cout << "\n\n\nDraw a:\n";
	std::cout << "1. Line      2. Square\n3. Circle    4. Triangle\n\n";
	std::cout << "Enter your number: ";
	std::cin >> menuChoice;
	
	prepareToDraw(menuChoice);

	return 0;
}

void setBackgroundColour()
{
	//enter case statement for choosing colour (maybe like 5/6 options)
	CGG::SetBackground(0, 0, 0);
}

void setLineColour()
{
	int colourChoice;
	bool optionValid = false;
	//same as background colour
	while (!optionValid)
	{
		system("CLS");
		std::cout << "1. Red        2. Blue.\n3. Green      4. Yellow\n5. Purple     6. Turquoise\n7. White\n\n";
		std::cout << "Choose a colour: ";
		std::cin >> colourChoice;
		if ((colourChoice > 0) && (colourChoice < 8))
			optionValid = true;
		else
		{
			std::cout << "That is not a valid input, try again.";
			system("PAUSE");
		}
	}

	switch (colourChoice)
	{
		case 1:
		{
			red = 255;
			green = 0;
			blue = 0;
		}
			break;
		case 2:
		{
			red = 0;
			green = 0;
			blue = 255;
		}
			break;
		case 3:
		{
			red = 0;
			green = 255;
			blue = 0;
		}
			break;
		case 4:
		{
			red = 255;
			green = 255;
			blue = 0;
		}
			break;
		case 5:
		{
			red = 255;
			green = 0;
			blue = 255;
		}
			break;
		case 6:
		{
			red = 0;
			green = 255;
			blue = 255;
		}
			break;
		case 7:
		{
			red = 255;
			green = 255;
			blue = 255;
		}
			break;
		default:
		{
			red = 255;
			green = 255;
			blue = 255;
		}
	}
	
}

int setSize()
{
	int returnValue, sizeValue;
	bool optionValid = false;
	while (!optionValid)
	{
		system("CLS");
		std::cout << "Sizes:\n1. Tiny     2. Small\n3. Big      4. Massive\n";
		std::cout << "Choose a size: ";
		std::cin >> sizeValue;
		if ((sizeValue < 5) || (sizeValue > 0))
			optionValid = true;
		else
		{
			std::cout << "That option is not valid.";
			system("PAUSE");
		}
	}

	switch (sizeValue)
	{
		case 1:
			returnValue = 10;
			break;
		case 2: 
			returnValue = 50;
			break;
		case 3:
			returnValue = 200;
			break;
		case 4:
			returnValue = 500;
			break;
		default: 
			returnValue = 100;
	}

	return returnValue;	
}

int prepareToDraw(int shapeNumber)
{
	int size = 0;
	windowWidth = 640;
	windowHeight = 640;
	pixelX = windowWidth / 2;
	pixelY = windowHeight / 2;

	setBackgroundColour();
	setLineColour();
	size = setSize();

	if (!CGG::Init(windowWidth, windowHeight))
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}
	
	
	switch (shapeNumber)
	{
		case 1:
			drawLine(pixelX, pixelY, size);
			break;
		case 2:
			drawSquare(pixelX, pixelY, size);
			break;
		case 3:
			drawCircle(pixelX, pixelY, size);
			break;
		deafult:
			CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}
	return CGG::ShowAndHold();
}

void drawHorizontalLine(int startPointX, int startPointY, bool directionRight, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!directionRight)
			pixelX--;
		else
			pixelX++;
		CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}
}

void drawVerticalLine(int startPointX, int startPointY, bool directionUp, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!directionUp)
			pixelY--;
		else 
			pixelY++;
		CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}
}

void drawDiagonalLine(int startPointX, int startPointY, bool directionLeft, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!directionLeft)
			pixelX++;
		else
			pixelX--;
		pixelY++;
		CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}
}

void drawLine(int startPointX, int startPointY, int size)
{
	pixelY = pixelY + (size/2);
	pixelX = pixelX - (size/2);
	for (int i = 0; i < size; i++)
	{
		pixelY++;
		pixelX++;
		CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}
}

void drawSquare(int startPointX, int startPointY, int size)
{
	pixelY = pixelY + (size / 2);
	pixelX = pixelX - (size / 2);
	drawHorizontalLine(pixelX, pixelY, true, size);
	drawVerticalLine(pixelX, pixelY, false, size);
	drawHorizontalLine(pixelX, pixelY, false, size);
	drawVerticalLine(pixelX, pixelY, true, size);
}

void drawTriangle(int startPointX, int startPointY, int size)
{

}

void drawCircle(int startPointX, int startPointY, int size)
{
	int x = size;
	int y = 0;
	int z = 0;

	while (x >= y)
	{
		CGG::DrawPixel((pixelX + x), (pixelY + y), red, green, blue);
		CGG::DrawPixel((pixelX + y), (pixelY + x), red, green, blue);
		CGG::DrawPixel((pixelX - y), (pixelY + x), red, green, blue);
		CGG::DrawPixel((pixelX - x), (pixelY + y), red, green, blue);
		CGG::DrawPixel((pixelX - x), (pixelY - y), red, green, blue);
		CGG::DrawPixel((pixelX - y), (pixelY - x), red, green, blue);
		CGG::DrawPixel((pixelX + y), (pixelY - x), red, green, blue);
		CGG::DrawPixel((pixelX + x), (pixelY - y), red, green, blue);

		if (z <= 0)
		{
			y += 1;
			z += 2 * y + 1;
		}
		if (z > 0)
		{
			y -= 1;
			z -= 2 * x + 1;
		}
	}
	//return CGG::ShowAndHold();
}

/*int drawSineWave(int startPointX, int startPointY, int size)
{

}




// Sets every pixel to the same colour
// parameters are RGBA, numbers are from 0 to 255
/*CGG::SetBackground( 0,0,0 );

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
//return CGG::ShowAndHold();*/





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