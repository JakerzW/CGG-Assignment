#include <cmath>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <Windows.h>
#include "CGG_Main.h"

//initiating the functions
int menu();
void menuCheck(int optionChosen);
void setLineColour();
void setBackgroundColour();

int prepareToDraw(int shapeNumber);


void drawVerticalLine(int startPointX, int startPointY, bool directionUp, int size);
void drawHorizontalLine(int startPointX, int startPointY, bool directionRight, int size);
void drawSquare(int startPointX, int startPointY, int size);
void drawLine(int startPointX, int startPointY, int size);
void drawAnyLine(int sPointX, int sPointY, int ePointX, int ePointY);
void drawTriangle();
void drawCircle(int startPointX, int startPointY, int size);

//initiating some global variables
int red, green, blue, pixelX, pixelY;
int windowWidth = 640;
int windowHeight = 640;
bool endGame = false;

int main(int argc, char *argv[])
{
	// Variables for storing window dimensions
	int windowWidth = 640;
	int windowHeight = 640;
	int menuChoice;
	// Call CGG::Init to initialise and create your window
	// Tell it what size you want the window to be
	while (!endGame)
		menu();

	return 0;
}

int menu()	//function for the menu, leads to other functions
{
	int menuChoice;
	bool exitProgram = false;
	bool entryValid = false;
	system("CLS");
	//shape ascii lettering
	while (!entryValid)
	{
		std::cout << " ___  _   _    __    ____  ____  ___\n";
		std::cout << "/ __)( )_( )  /__\\  (  _ \\( ___)/ __)\n";
		std::cout << "\\__ \\ ) _ (  /(__)\\  )___/ )__) \\__ \\\n";
		std::cout << "(___/(_) (_)(__)(__)(__)  (____)(___/";
		std::cout << "\n\n\nDraw a:\n";
		std::cout << "1. Line      2. Square\n3. Circle    4. Triangle\n\n5. Instructions\n6. Exit\n\n";
		std::cout << "Enter your number: ";
		std::cin >> menuChoice;
		if ((menuChoice < 7) && (menuChoice > 0))
			entryValid = true;
		else
		{
			system("CLS");
			std::cout << "That option is not valid.";
			system("PAUSE");
		}
	}
	menuCheck(menuChoice);
	return 0;
}

void menuCheck(int optionChosen)	//checks the input for the menu and sends off to other functions depending on the chosen option
{
	char exitFS;
	bool charValid = false;
	switch (optionChosen)
	{
		case 1:	case 2: case 3: case 4:		//calls the function to draw the chosen shape
			prepareToDraw(optionChosen);
			break;
		case 5:		//reads out the instructions
		{
			system("CLS");
			std::cout << "This program shows allows you to chose a shape, \nand then a colour for the shape. \nSome even allow you to choose the size!\n\n";
			system("PAUSE");
		}
			break;
		case 6:		//starts the exit procedure
		{
			while (!charValid)
			{
				system("CLS");
				std::cout << "Are you sure you want to quit? y/n ";
				std::cin >> exitFS;
				if ((exitFS == 'y')||(exitFS == 'n'))	//validation or fail safe
				{
					charValid = true;
					if (exitFS == 'y')
						endGame = true;
				}
				else
				{
					std::cout << "\nThat is not a valid character.";
					Sleep(1000);					
				}
			}
		}
			break;
	}
}

void setBackgroundColour()
{
	//enter case statement for choosing colour (maybe like 5/6 options)
	CGG::SetBackground(0, 0, 0);
}	  //sets the background colour for the window

void setLineColour()	//opens up the choices for the colour of the shape
{
	int colourChoice;
	bool optionValid = false;
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

int setSize()	//opens up choices for the sizes for a few shapes, gives the user the option
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

int prepareToDraw(int shapeNumber)	//initiates the drawing procedure for the shapes
{
	int size = 0;
	windowWidth = 640;
	windowHeight = 640;
	pixelX = windowWidth / 2;
	pixelY = windowHeight / 2;

	setBackgroundColour();
	setLineColour();

	if (shapeNumber < 4)
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
		case 4:
			drawTriangle();
			break;
		deafult:
			CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}
	return CGG::ShowAndHold();
}

void drawHorizontalLine(int startPointX, int startPointY, bool directionRight, int size)	//draws a horizontal line to a user defined size for the square
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

void drawVerticalLine(int startPointX, int startPointY, bool directionUp, int size)		//same as the horizontal line but just vertical
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

void drawLine(int startPointX, int startPointY, int size)	//draws a diagonal line of a user defined size
{
	pixelY = pixelY - (size/2);
	pixelX = pixelX - (size/2);
	for (int i = 0; i < size; i++)
	{
		pixelY++;
		pixelX++;
		CGG::DrawPixel(pixelX, pixelY, red, green, blue);
	}
}

void drawSquare(int startPointX, int startPointY, int size)		//uses the other functions to draw the square
{
	pixelY = pixelY + (size / 2);
	pixelX = pixelX - (size / 2);
	drawHorizontalLine(pixelX, pixelY, true, size);
	drawVerticalLine(pixelX, pixelY, false, size);
	drawHorizontalLine(pixelX, pixelY, false, size);
	drawVerticalLine(pixelX, pixelY, true, size);
}

void drawAnyLine(int sPointX, int sPointY, int ePointX, int ePointY)	//draws a line to two defined points
{
	int dx;
	int dy;
	float xInc, yInc, steps;
	float x = sPointX;
	float y = sPointY;

	dx = ePointX - sPointX;
	dy = ePointY - sPointY;
	
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xInc = dx / (float)steps;
	yInc = dy / (float)steps;

	for (int i = 0; i < steps; i++)
	{
		x += xInc;
		y += yInc;
		CGG::DrawPixel(x, y, red, green, blue);
	}
}

void drawTriangle()		//uses the two point line drawing system to draw the triangle from three coordinates
{
	int w = 400;
	int h = 400;
	int sPx = 120;
	int sPy = 120;
	drawAnyLine(sPx, sPy, sPx + w, sPy + h);
	drawAnyLine(sPx+ w, sPy + h, sPx, sPy + h);
	drawAnyLine(sPx, sPy + h, sPx, sPy);
}	

void drawCircle(int startPointX, int startPointY, int size)		//uses a simple algorithm to draw a circle
{
	int x = size;
	int y = 0;
	int z = 0;

	while (x >= y)
	{
		CGG::DrawPixel(startPointX + x, startPointY + y, red, green, blue);
		CGG::DrawPixel(startPointX + y, startPointY + x, red, green, blue);
		CGG::DrawPixel(startPointX - y, startPointY + x, red, green, blue);
		CGG::DrawPixel(startPointX - x, startPointY + y, red, green, blue);
		CGG::DrawPixel(startPointX - x, startPointY - y, red, green, blue);
		CGG::DrawPixel(startPointX - y, startPointY - x, red, green, blue);
		CGG::DrawPixel(startPointX + y, startPointY - x, red, green, blue);
		CGG::DrawPixel(startPointX + x, startPointY - y, red, green, blue);

		if (z <= 0)
		{
			y += 1;
			z += 2 * y + 1;
		}
		if (z > 0)
		{
			x -= 1;
			z -= 2 * x + 1;
		}
	}
}