#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Engine.h"
#include "Path.h"
#include "Player.h"

using namespace std;

class Scene
{
protected:
	ALLEGRO_BITMAP* background = NULL;
	Engine* engine = Engine::getInstance();

	static int screen_width;
	static int screen_height;
	int backgroundWidth=0;
	int backgroundHeight=0;
	bool done = false;

	float cameraPosition = 0;
	float backgroundXPosition = 0;


	void drawBackground(Player* player);
	void cameraTransform(Player *player);
	void resetCamera();
	

public:
	Scene();
	virtual ~Scene();
	virtual void showWindow()=0;
	void setBackground(const char* backgroundBitmap);
	

private:
	ALLEGRO_BITMAP* load_bitmap_at_size(const char* filename, int w, int h);
	void cameraUpdate(float x, float y, int width, int height);

	
};

