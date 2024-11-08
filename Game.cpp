#include "Game.h"
#include "raylib.h"

Game::Game(std::string tabName, int windowWidth, int windowHeight) :
	_tabName(tabName),
	_windowWidth(windowWidth),
	_windowHeight(windowHeight) {

	InitWindow(_windowWidth, _windowHeight, _tabName.c_str());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        Rectangle r;
        r.x = 190;
        r.y = 190;
        r.width = 50;
        r.height = 50;
        DrawRectangleRec(r, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

}