#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

Game::Game(std::string name, int width, int height)
{
	m_name = name;
	m_mainWindow = Window(width, height);
}

void Game::Run()
{
	while (m_isRunning)
	{
		Update();
		Draw();
	}
}

void Game::Init()
{
	m_mainWindow.InitWindow(m_name);
}

void Game::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_isRunning = false;
			break;
		}
	}
}

void Game::Draw()
{
	m_mainWindow.Clear();

	//go through the active scene and draw stuff

	m_mainWindow.SwapBuffers();
}
