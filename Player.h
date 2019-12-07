#pragma once
#include"Node.h"
#include"Engine.h"

class Player :public Node
{
	Engine* engine = Engine::getInstance();
	int hp = 100;
	const int frames;
	const int levels;
	int moveSpeed = 5;

	float shiftX = 0;
	float shiftY = 0;

	void animation(ALLEGRO_EVENT events);

public:
	Player(const char* backgroundBitmap, const int frames, const int levels);
	~Player();
	virtual void show() override;
	void move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight);
	
};

