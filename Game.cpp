#include "Game.h"
#include "Player.h"
#include "raylib.h"
#include "Ball.h"
#include "Box.h"
#include <iostream>
#include <format>

#define PLAYERSPEED 7
#define BALLSPEED 5
#define BOX_SIZE 40

Game::Game(std::string tabName, int windowWidth, int windowHeight) :
    _tabName(tabName),
    _windowWidth(windowWidth),
    _windowHeight(windowHeight) {

    _score = 0;
    _player = std::make_unique<Player>(_windowWidth / 2 - _windowWidth * 0.1, _windowHeight * 0.9, _windowWidth * 0.20, _windowHeight * 0.05, PLAYERSPEED);
    _ball = std::make_unique<Ball>(_windowWidth / 2, _windowHeight / 2, 0, 0, 10);

    int boxXIndex = 20;
    int boxYIndex = 45;
    _boxes.resize(3);
    for (int i = 0; i < 3; i++) {
        _boxes[i].resize(17);
        for (int j = 0; j < 17; j++) {
            _boxes[i][j] = std::make_unique<Box>(boxXIndex, boxYIndex, BOX_SIZE, BOX_SIZE);
            boxXIndex += BOX_SIZE + 5;
        }
        boxYIndex += BOX_SIZE + 10;
        boxXIndex = 20;
    }
}


void Game::start() {
    InitWindow(_windowWidth, _windowHeight, _tabName.c_str());
    SetTargetFPS(60);

    bool gameStarted = false;

    while (!WindowShouldClose() && !is_won())
    { 

        // Start game when pressing space
        if (!gameStarted && IsKeyPressed(KEY_SPACE)) {
            gameStarted = true;
            _ball->speedX = BALLSPEED;
            _ball->speedY = BALLSPEED;
        }


        //Update
        _player->move();
        _ball->move();

        // Check for collision
        _ball->check_collision(_player->get_rectangle());

        for (int i = 0; i < _boxes.size(); i++) {
            for (int j = 0; j < _boxes[i].size(); j++) {
                if (_ball->check_collision(_boxes[i][j]->get_rectangle())) {
                    _score += 1;
                    std::vector<std::unique_ptr<Box>>::iterator it = _boxes[i].begin();
                    std::advance(it, j);
                    _boxes[i].erase(it);
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!gameStarted) {
            draw_start_game();
        }

        draw_score();
        _player->draw();
        _ball->draw();

        for (int i = 0; i < _boxes.size(); i++) {
            for (int j = 0; j < _boxes[i].size(); j++) {
                _boxes[i][j]->draw();
            }
        }

        EndDrawing();
    }

    CloseWindow();
}

void Game::draw_score() {
    DrawText(std::format("Score: {}", _score).c_str(), 5, 5, 26, BLACK);
}

bool Game::is_won() {
    for (int i = 0; i < _boxes.size(); i++) {
        if (!_boxes[i].empty()) {
            return false;
        }
    }

    return true;
}

void Game::draw_start_game() {
    std::string str = "Press SPACE to start playing!";
    int fontSize = 26;

    int textWidth = MeasureText(str.c_str(), fontSize);
    DrawText(str.c_str(), _windowWidth / 2 - textWidth / 2, _windowHeight / 2 - 45, 26, BLACK);
}