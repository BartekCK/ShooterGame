#include "Button.h"
#include<iostream>

Button::Button(const char* backgroundBitmap)
	: Node(backgroundBitmap)
{

}


Button::~Button()
{
	std::cout << "DESTRUKTOR Z BUTTON" << std::endl;
}

void Button::show()
{
	al_draw_bitmap(this->objectBitmap, this->xPosition, this->yPosition, 0);
}


bool Button::buttonClick(int xClick, int yClick)
{
	if (xClick > xPosition&& xClick < xPosition + bitmapWidth &&
		yClick > yPosition&& yClick < yPosition + bitmapHeight) {
		return true;
	}
	return false;
}