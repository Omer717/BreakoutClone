#pragma once
#include "raylib.h"

class Ball {
public:
	float x, y;
	int speedX, speedY;
	float radius;

	Ball(float x, float y, int speedX, int speedY, float radius);
	void draw();
	void move();
	bool check_collision(Rectangle rect);
	bool is_out_of_bounds();

private:
	float _px, _py;
};
