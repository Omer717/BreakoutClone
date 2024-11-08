#pragma once

class Ball {
public:
	int x, y;
	int speedX, speedY;
	float radius;

	Ball(int x, int y, int speedX, int speedY, float radius);
	void Draw();
	void Move();
};
