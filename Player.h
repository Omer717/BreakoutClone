#pragma once
#include "raylib.h"

class Player {
public:
	float x, y;
	float width, height, speed;
	
	Player(float x, float y, float width, float height, float speed);
	void Draw();
	void Move();
	Rectangle getRectangle();

private:


};