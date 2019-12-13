#include "Node.h"
#include<iostream>
Node::Node(const char* backgroundBitmap) :backgroundBitmap(backgroundBitmap)
{

	xPosition = 10;
	yPosition = 10;

	this->objectBitmap = al_load_bitmap(this->backgroundBitmap);
	if (!objectBitmap)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}

	this->bitmapWidth = al_get_bitmap_width(this->objectBitmap);
	this->bitmapHeight = al_get_bitmap_height(this->objectBitmap);
}

Node::Node(int xPosition, int yPosition):xPosition(xPosition), yPosition(yPosition)
{
}

Node::~Node()
{
	al_destroy_bitmap(this->objectBitmap);
	std::cout << "DESTRUKTOR Z NODE" << std::endl;
}

int Node::getBitmapWidth()
{
	return this->bitmapWidth;
}

int Node::getBitmapHeight()
{
	return this->bitmapHeight;
}

void Node::setXposition(int x)
{
	this->xPosition = x;
}

void Node::setYposition(int y)
{
	this->yPosition = y;
}

int Node::getXposition()
{
	return xPosition;
}

int Node::getYposition()
{
	return yPosition;
}