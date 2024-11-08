#include "Player.h"
#include <raylib.h>

Player::Player(float x, float y, int width, int height) : x(x), y(y), width(width), height(height) {}

void Player::Draw() {
	DrawRectangle(x, y, width, height, BLACK);
}

void Player::Move(int playerSpeed) {

	if (x + width + playerSpeed >= GetScreenWidth()) {
		x = GetScreenWidth() - width;
	}
	else if (x + playerSpeed <= 0) {
		x = 0;
	}
	else {
		x += playerSpeed;
	}

}