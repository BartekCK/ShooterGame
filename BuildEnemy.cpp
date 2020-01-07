#include "BuildEnemy.h"
#include "Path.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int BuildEnemy::screen_width = GetSystemMetrics(SM_CXSCREEN);
int BuildEnemy::screen_height = GetSystemMetrics(SM_CYSCREEN);


int BuildEnemy::getRandX(Player* player)
{
	return player->getXposition() + screen_width;//X;
}

int BuildEnemy::getRandY()
{
	srand(time(NULL)*256);
	int value = (std::rand() % screen_height);
	std::cout << value << std::endl;
	return value ;
}

Enemy* BuildEnemy::getSmallSoldier(Player* player)
{
	Path path;
	return new Enemy(path.ENEMY_SMALL_SOLDIER, getRandX(player),getRandY(), 6, 2, HP_VALUE::LOW, MOVE_SPEED::FAST, SHOOT_TIME::SLOW, player);
}

Enemy* BuildEnemy::getSoldier(Player* player)
{
	Path path;
	return new Enemy(path.ENEMY_SOLDIER, getRandX(player), getRandY(), 10, 2, HP_VALUE::MIDDLE, MOVE_SPEED::SLOW, SHOOT_TIME::FAST, player);
}

Enemy* BuildEnemy::getGalacticSoldier(Player* player)
{
	Path path;
	return new Enemy(path.ENEMY_GALACTIC_SOLDIER, getRandX(player), getRandY(), 17, 2, HP_VALUE::HARD, MOVE_SPEED::SLOW, SHOOT_TIME::SLOW, player);
}

Enemy* BuildEnemy::getZombie(Player* player)
{
	Path path;
	return new Enemy(path.ENEMY_ZOMBIE, getRandX(player), getRandY(), 19, 2, HP_VALUE::MIDDLE, MOVE_SPEED::MIDDLE, SHOOT_TIME::SLOW, player);
}

Enemy* BuildEnemy::getFastZombie(Player* player)
{
	Path path;
	return new Enemy(path.ENEMY_SMALL_ZOMBIE, getRandX(player), getRandY(), 8, 2, HP_VALUE::LOW, MOVE_SPEED::FAST, SHOOT_TIME::SLOW, player);
}

Enemy* BuildEnemy::getBoss(Player* player)
{
	return nullptr;
}




Enemy* BuildEnemy::getEnemy(Player* player)
{
	srand(time(NULL));
	int randValue = std::rand() % 5;//5 random enemies {0...4}

	switch (randValue)
	{
	case 0:
		return getSmallSoldier(player);
	case 1:
		return getSoldier(player);
	case 2:
		return getGalacticSoldier(player);
	case 3:
		return getZombie(player);
	case 4:
		return getFastZombie(player);
	}


	return NULL;
}

