#pragma once
#include "raylib.h"

class Player {
public:
	float x, y;
	float width, height, speed;
	
	Player(float x, float y, float width, float height, float speed);
	void draw();
	void move();
	Rectangle get_rectangle();

private:


};