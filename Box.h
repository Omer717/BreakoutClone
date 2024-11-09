#pragma once
#include "raylib.h"

class Box {
public:
	float x, y, width, height;
	bool isHit;

	Box(float x, float y, float width, float height);
	void draw();
	Rectangle get_rectangle();
};
