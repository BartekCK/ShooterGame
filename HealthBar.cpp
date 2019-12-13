#include "HealthBar.h"
#include <iostream>



HealthBar::HealthBar(const char* backgroundBitmap, int xPosition, int yPosition, int frames) : Node(backgroundBitmap,xPosition,yPosition),frames(frames)
{
}

HealthBar::~HealthBar()
{
	std::cout << "DESTRUKTOR Z HEATHL_BAR" << std::endl;
}

void HealthBar::show()
{
	al_draw_bitmap_region(this->objectBitmap, this->shiftX, 0, this->bitmapWidth / frames, this->bitmapHeight, this->xPosition, this->yPosition, 0);
}

void HealthBar::readHp(Hero* hero)
{
	switch (hero->getHp())
	{
		case 100:
			shiftX = 0;
			break;
		case 90:
			shiftX = 1*(this->bitmapWidth / frames);
			break;
		case 80:
			shiftX = 2 * (this->bitmapWidth / frames);
			break;
		case 70:
			shiftX = 3 * (this->bitmapWidth / frames);
			break;
		case 60:
			shiftX = 4 * (this->bitmapWidth / frames);
			break;
		case 50:
			shiftX = 5 * (this->bitmapWidth / frames);
			break;
		case 40:
			shiftX = 6 * (this->bitmapWidth / frames);
			break;
		case 30:
			shiftX = 7 * (this->bitmapWidth / frames);
			break;
		case 20:
			shiftX = 8 * (this->bitmapWidth / frames);
			break;
		case 10:
			shiftX = 9 * (this->bitmapWidth / frames);
			break;
	}
}
