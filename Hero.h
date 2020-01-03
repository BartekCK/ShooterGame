#pragma once
#include"Node.h"
#include"Gun.h"

class Hero:public Node
{
protected:

	Engine* engine = Engine::getInstance();
	Gun* gun = NULL;
	int hp = 100;

	float shiftX = 0;
	float shiftY = 0;
	int moveSpeed = 5;

public:

	const int frames;
	const int levels;

	Hero(const char* backgroundBitmap, const int frames, const int levels);
	Hero(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels);
	virtual ~Hero();

	virtual void show()=0;
	virtual void makeShot(ALLEGRO_EVENT events) = 0;
	virtual void move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight)=0;

	bool checkHit(std::vector<Hero*> heroes);
	bool checkHit(Hero * hero);

	bool checkHp();
	int getHp();

	Gun* getGun();
	
	
};

