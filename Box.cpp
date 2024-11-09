#include "Box.h"
#include "raylib.h"

Box::Box(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {}

void Box::draw() {
	DrawRectangle(x, y, width, height, GRAY);
}