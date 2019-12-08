#pragma once
#include"Hero.h"
#include"Engine.h"



enum class CONTROL_SOURCE
{
	ARROW_CONTROL,
	WASD_CONTROL
};


class Player :public Hero
{
	Engine* engine = Engine::getInstance();
	

	CONTROL_SOURCE controlSource;
	void useBorders(float backgroundXPosition, int backgroundWidth, int backgroundHeight);
	void animation(ALLEGRO_EVENT events);
	void chooseShootDirection();
	
public:

	Player(const char* backgroundBitmap, const int frames, const int levels, CONTROL_SOURCE controlSource);
	~Player();
	virtual void show() override;
	void move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight);

	void makeShot(ALLEGRO_EVENT events);
	
	
};

