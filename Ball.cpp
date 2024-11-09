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

	_px = x;
	_py = y;
	x += speedX;
	y += speedY;
}

void Ball::check_collision(Rectangle rect) {

	int left = rect.x;
	int right = rect.x + rect.width;
	int top = rect.y;
	int bottom = rect.y + rect.height;

	if (CheckCollisionCircleRec(Vector2{ x, y }, radius, rect)) {

		if (_px < left) {
			speedX *= -1;
			x = left - radius;
		}
		else if (_px > right) {
			speedX *= -1;
			x = right + radius;
		}
		else if (_py < top) {
			speedY *= -1;
			y = top - radius;
		}
		else if (_py > bottom) {
			speedY *= -1;
			y = bottom + radius;
		}
	}
}