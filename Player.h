#pragma once

class Player {
public:
	float x, y;
	int width, height, speed;
	
	Player(float x, float y, int width, int height, int speed);
	void Draw();
	void Move();

private:


};