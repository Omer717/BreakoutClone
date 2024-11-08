#pragma once

class Player {
public:
	float x, y;
	int width, height;
	
	Player(float x, float y, int width, int height);
	void Draw();
	void Move(int moveSpeed);

private:


};