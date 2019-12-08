#pragma once
#include"Node.h"
#include"Gun.h"

class Hero:public Node
{
protected:

	Gun* gun = NULL;
	int hp = 100;

	const int frames;
	const int levels;

	float shiftX = 0;
	float shiftY = 0;
	int moveSpeed = 5;

public:
	Hero(const char* backgroundBitmap, const int frames, const int levels);
	virtual ~Hero();

	virtual void show()=0;
	virtual void makeShot(ALLEGRO_EVENT events) = 0;
	virtual void move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight)=0;

	bool checkHit(std::vector<Hero*> heroes);
	Gun* getGun();

};

