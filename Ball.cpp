#include "Ball.h"
#include "raylib.h"

Ball::Ball(float x, float y, int speedX, int speedY, float radius) : x(x), y(y), speedX(speedX), speedY(speedY), radius(radius) {}

void Ball::draw() {
	DrawCircle(x, y, radius, BLACK);
}

void Ball::move() {
	if (x + radius + speedX >= GetScreenWidth() || x - radius <= 0) {
		speedX *= -1;
	}

	if (y - radius <= 0) {
		speedY *= -1;
	}

	x += speedX;
	y += speedY;
}