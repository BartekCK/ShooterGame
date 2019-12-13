#include "Ammo.h"
#include <iostream>
#include <allegro5/allegro_primitives.h>

Ammo::Ammo(int xPosition, int yPosition, SHOOT_DIRECTION direction) :xPosition(xPosition), yPosition(yPosition), direction(direction)
{
	this->endXPosition = xPosition;
	this->endYPosition = yPosition;
}

Ammo::~Ammo()
{
	std::cout << "DEKONSTRUKTOR Z AMMO"<<std::endl;
}

void Ammo::show()
{
	al_draw_line(endXPosition, endYPosition, endXPosition + 20, endYPosition, al_map_rgb(25, 60, 120), 10);
	if(this->direction == SHOOT_DIRECTION::RIGHT_SHOOT)
		endXPosition += shotSpeed;
	else
		endXPosition -= shotSpeed;
}

int Ammo::getEndXPosition()
{
	return endXPosition;
}

int Ammo::getEndYPosition()
{
	return endYPosition;
}

SHOOT_DIRECTION Ammo::getDirection()
{
	return this->direction;
}

void Ammo::setXposition(int x)
{
	this->xPosition = x;
}

void Ammo::setYposition(int y)
{
	this->yPosition = y;
}

int Ammo::getXposition()
{
	return xPosition;
}

int Ammo::getYposition()
{
	return yPosition;
}
