#pragma once
#include <string>

class Game
{
public:
	Game(std::string tabName, int windowWidth, int windowHeight);
	//void InitPlayer(int x, int y, int playerWidth, int playerHeight);

private:
	std::string _tabName;
	int _windowWidth;
	int _windowHeight;
};
