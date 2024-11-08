#include "Game.h"
#include "Player.h"
#include "raylib.h"

Game::Game(std::string tabName, int windowWidth, int windowHeight) :
	_tabName(tabName),
	_windowWidth(windowWidth),
	_windowHeight(windowHeight) {

	InitWindow(_windowWidth, _windowHeight, _tabName.c_str());
    SetTargetFPS(60);

    Player player(_windowWidth / 2 - _windowWidth * 0.1, _windowHeight * 0.9, _windowWidth * 0.20, _windowHeight * 0.05);

    while (!WindowShouldClose())
    {
        //Update
        if (IsKeyDown(KEY_RIGHT)) player.Move(2);
        if (IsKeyDown(KEY_LEFT)) player.Move(-2);


        BeginDrawing();
        ClearBackground(RAYWHITE);

        player.Draw();

        EndDrawing();
    }

    CloseWindow();

}
