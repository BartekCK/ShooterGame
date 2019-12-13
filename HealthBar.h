#pragma once
#include "Node.h"
#include "Hero.h"
class HealthBar:public Node
{
	const int frames;
	int shiftX = 0;

public:
	HealthBar(const char* backgroundBitmap,int xPosition, int yPosition, int frames);
	~HealthBar();
	
	virtual void show() override;
	void readHp(Hero* hero);
};

