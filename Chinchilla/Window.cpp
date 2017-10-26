#include "Window.h"



Window::Window()
{
	//create a new window with standard values
	m_window = nullptr;
	m_width = 800;
	m_height = 600;
}


Window::~Window()
{
	//don't need to delete m_window because of the use of smart pointers
}

Window::Window(int w, int h)
{
	//custom constructor to specify values, this will likely be the default
	m_window = nullptr;
	m_width = w;
	m_height = h;
}

void Window::InitWindow(std::string title)
{
	//boilerplate got from the GL Base project

	//init SDL2
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	m_window = std::shared_ptr<SDL_Window>(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL));
	m_context = SDL_GL_CreateContext(m_window.get());

	//init glew
	glewExperimental = GL_TRUE;
	GLenum error = glewInit();
	if (m_window == nullptr)
		std::cout << "Could not create window!" << std::endl;
	if (m_context == nullptr)
		std::cout << "Could not create GL context!" << std::endl;
	if (error != GLEW_OK)
		std::cout << "Could not initialise GLEW!" << std::endl;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Window::Clear()
{
	//clear with a solid color
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::SwapBuffers()
{
	//just swap the back buffer with the screen
	SDL_GL_SwapWindow(m_window.get());
}
