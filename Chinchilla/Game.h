#ifndef GAME_H
#define GAME_H

#include "Window.h" //already includes common

class Game
{
private:
	std::string m_name;
	Window m_mainWindow;
	bool m_isRunning = true;

public:
	Game();
	~Game();

	Game(std::string gameName, int width, int height);

	void Run();
	void Init();
	void Update();
	void Draw();


	//getters and setters
};

#endif