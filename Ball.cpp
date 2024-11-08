#include "Ball.h"
#include "raylib.h"

Ball::Ball(int x, int y, int speedX, int speedY, float radius): x(x), y(y), speedX(speedX), speedY(speedY), radius(radius) {}

void Ball::Draw() {
	DrawCircle(x, y, radius, BLACK);
}

void Ball::Move() {
	x += speedX;
	y += speedY;
}