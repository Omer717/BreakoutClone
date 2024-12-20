#pragma once
#include <string>
#include "Player.h"
#include "Ball.h"
#include "Box.h"
#include <iostream>
#include <vector>

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
	std::vector<std::vector<std::unique_ptr<Box>>> _boxes;

	int _health;
	int _score;

	void init_game();
	void draw_score();
	void draw_health();
	void draw_alert(std::string alert);

	bool is_won();
};
