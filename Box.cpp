#include "Box.h"
#include "raylib.h"

Box::Box(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {
	isHit = false;
}

void Box::draw() {
	DrawRectangle(x, y, width, height, GRAY);
}

Rectangle Box::get_rectangle() {
	return Rectangle{ x, y, width, height };
}