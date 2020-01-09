#include "Zombie.h"
#include <iostream>

Zombie::Zombie(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels, HP_VALUE hpValue, MOVE_SPEED moveSpeed, SHOOT_TIME shootTime, Hero* player)
	:Enemy(backgroundBitmap,xPosition,yPosition,frames,levels,hpValue,moveSpeed,shootTime,player)
{
}

Zombie::~Zombie()
{
	std::cout << "DEKONSTRUKTOR Z ZOMBIE" << std::endl;
}

void Zombie::makeShot(ALLEGRO_EVENT events)
{

}
