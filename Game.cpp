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

    _score = 0;
    _player = std::make_unique<Player>(_windowWidth / 2 - _windowWidth * 0.1, _windowHeight * 0.9, _windowWidth * 0.20, _windowHeight * 0.05, PLAYERSPEED);
    _ball = std::make_unique<Ball>(_windowWidth / 2, _windowHeight / 2, BALLSPEED, BALLSPEED, 10);
}


void Game::start() {
    InitWindow(_windowWidth, _windowHeight, _tabName.c_str());
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //Update
        _player->move();
        _ball->move();

        // Check for collision

        if (CheckCollisionCircleRec(Vector2{ _ball->x, _ball->y }, _ball->radius, _player->get_rectangle())) {
            _ball->speedY *= -1;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        _player->draw();
        _ball->draw();

        EndDrawing();
    }

    CloseWindow();
}