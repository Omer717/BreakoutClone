#pragma once

class Ball {
public:
	float x, y;
	int speedX, speedY;
	float radius;

	Ball(float x, float y, int speedX, int speedY, float radius);
	void Draw();
	void Move();
};
