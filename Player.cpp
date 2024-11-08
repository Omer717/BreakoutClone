#include "Player.h"
#include <raylib.h>

Player::Player(float x, float y, float width, float height, float speed) : x(x), y(y), width(width), height(height), speed(speed) {}

void Player::Draw() {
	DrawRectangle(x, y, width, height, BLACK);
}

void Player::Move() {

	if (IsKeyDown(KEY_RIGHT)) {

		if (x + width + speed >= GetScreenWidth()) {
			x = GetScreenWidth() - width;
		}
		x += speed;
	}
	if (IsKeyDown(KEY_LEFT)) {
		if(x - speed <= 0) {
			x = 0;
		}

		x -= speed;
	}
}

Rectangle Player::getRectangle() {
	return Rectangle{ x, y, width, height };
}