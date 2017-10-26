#ifndef WINDOW_H
#define WINDOW_H

#include "Common.h"

class Window
{
private:
	std::shared_ptr<SDL_Window> m_window; //holds pointer to our window
	SDL_GLContext m_context;
	int m_width;
	int m_height;

public:
	Window();
	~Window();

	Window(int w, int h);

	void InitWindow(std::string title);
	void Clear();
	void SwapBuffers();

	//getters and setters
};

#endif