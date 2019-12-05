#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Engine.h"
#include "Path.h"

using namespace std;

class Scene
{
protected:
	ALLEGRO_BITMAP* background = NULL;
	Engine* engine = Engine::getInstance();

	static int screen_width;
	static int screen_height;
	bool done = false;
public:
	Scene();
	virtual ~Scene();
	virtual void showWindow()=0;
	void setBackground(const char* backgroundBitmap);

private:
	ALLEGRO_BITMAP* load_bitmap_at_size(const char* filename, int w, int h);
};

