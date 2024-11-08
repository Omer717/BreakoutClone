#include "Game.h"
#include "Player.h"
#include "raylib.h"
#include "Ball.h"

#define PLAYERSPEED 5
#define BALLSPEED 5

Game::Game(std::string tabName, int windowWidth, int windowHeight) :
	_tabName(tabName),
	_windowWidth(windowWidth),
	_windowHeight(windowHeight) {

	InitWindow(_windowWidth, _windowHeight, _tabName.c_str());
    SetTargetFPS(60);

    Player player(_windowWidth / 2 - _windowWidth * 0.1, _windowHeight * 0.9, _windowWidth * 0.20, _windowHeight * 0.05, PLAYERSPEED);
    Ball ball(_windowWidth / 2, _windowHeight / 2, BALLSPEED, BALLSPEED, 10);


    while (!WindowShouldClose())
    { 
        //Update
        player.Move();
        ball.Move();

        // Check for collision

        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, player.getRectangle())) {
            ball.speedY *= -1;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        player.Draw();
        ball.Draw();

        EndDrawing();
    }

    CloseWindow();

}
