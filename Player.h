#pragma once
#include"Node.h"

class Player :public Node
{
	int hp = 100;
	const int frames;
	const int levels;
	int moveSpeed = 5;

	float shiftX = 0;
	float shiftY = 0;

	void animation();

public:
	Player(const char* backgroundBitmap, const int frames, const int levels);
	~Player();
	virtual void show() override;
	void move();
	
};

