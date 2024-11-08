#pragma once
#include <string>
#include "Player.h"
#include "Ball.h"
#include <iostream>

class Game
{
public:
	Game(std::string tabName, int windowWidth, int windowHeight);
	void start();
private:
	std::string _tabName;
	int _windowWidth;
	int _windowHeight;

	std::unique_ptr<Player> _player;
	std::unique_ptr<Ball> _ball;

	int _score;
};
