#pragma once
#include "Node.h"


class Button :public Node
{

public:
	Button(const char* backgroundBitmap);
	~Button();

	void show()override;

	bool buttonClick(int x, int y);
	const char* getPathBackgroundBitmap();

};
