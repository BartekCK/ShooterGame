#include "Heart.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

Heart::Heart(const char* backgroundBitmap):Node(backgroundBitmap)
{
}

Heart::~Heart()
{
	std::cout << "DESTRUKTOR Z HEART" << std::endl;
}

void Heart::show()
{
	if (visible) {
		al_draw_bitmap(this->objectBitmap, this->xPosition, this->yPosition, NULL);
	}

}

void Heart::checkHit(Player *player)
{
	
	if (visible) {
		if (player->getXposition() + (player->getBitmapWidth() / player->frames) >= xPosition &&
			player->getXposition() <= xPosition + bitmapWidth &&
			player->getYposition() + (player->getBitmapHeight() / player->levels) >= yPosition &&
			player->getYposition() <= yPosition + bitmapHeight
			) {
			//Action when players have collision
			player->addHealth();
			visible = false;
		}
	}
}

bool Heart::isVisible()
{
	return visible;
}

void Heart::calculateCoordinates()
{
	if (!visible) {

		srand(time(NULL));
		xPosition = (std::rand() % GetSystemMetrics(SM_CXSCREEN));
		yPosition = (std::rand() % GetSystemMetrics(SM_CYSCREEN));

		if (std::rand() % 10 == 0) {
			visible = true;
			std::cout << "POKAZUJE SIE" << std::endl;
		}
	}
}
