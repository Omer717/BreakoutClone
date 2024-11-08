#pragma once
#include <string>

class Game
{
public:
	Game(std::string tabName, int windowWidth, int windowHeight);

private:
	std::string _tabName;
	int _windowWidth;
	int _windowHeight;
};
