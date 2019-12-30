#pragma once
#include "Node.h"
#include "Player.h"


class Heart: public Node
{
	bool visible = false;
public:
	Heart(const char* backgroundBitmap);
	~Heart();
	virtual void show() override;
	void checkHit(Player* player);

	bool isVisible();

	void calculateCoordinates(int cameraPosition, int screen_width, int screen_height);
};

