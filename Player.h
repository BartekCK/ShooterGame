#pragma once
#include"Node.h"
#include"Engine.h"
#include"Gun.h"


enum class CONTROL_SOURCE
{
	ARROW_CONTROL,
	WASD_CONTROL
};


class Player :public Node
{
	Engine* engine = Engine::getInstance();
	Gun* gun = NULL;
	int hp = 100;
	const int frames;
	const int levels;
	CONTROL_SOURCE controlSource;

	float shiftX = 0;
	float shiftY = 0;
	int moveSpeed = 5;

	void useBorders(float backgroundXPosition, int backgroundWidth, int backgroundHeight);
	void animation(ALLEGRO_EVENT events);
	
public:

	Player(const char* backgroundBitmap, const int frames, const int levels, CONTROL_SOURCE controlSource);
	~Player();
	virtual void show() override;
	void move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight);

	void makeShot();
	Gun* getGun();
	
	
};

