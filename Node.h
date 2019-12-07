#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;


class Node
{
protected:

	ALLEGRO_BITMAP* objectBitmap = NULL;

	int xPosition = 0;
	int yPosition = 0;

	int bitmapWidth = 0;
	int bitmapHeight = 0;
	const char* backgroundBitmap;

public:
	Node(const char* backgroundBitmap);
	~Node();

	int getBitmapWidth();
	int getBitmapHeight();

	void setXposition(int x);
	void setYposition(int y);
	int getXposition();
	int getYposition();
	virtual void show() = 0;
};