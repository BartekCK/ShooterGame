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

void Heart::calculateCoordinates(int cameraPosition, int screen_width, int screen_height)
{
	if (!visible) {

		srand(time(NULL)*256);


		xPosition = (std::rand() % screen_width)+cameraPosition;
		yPosition = (std::rand() % screen_height);

		if (std::rand() % 10 == 0) {
			visible = true;
		}
	}
	if (cameraPosition > xPosition)
	 visible = false;
}
