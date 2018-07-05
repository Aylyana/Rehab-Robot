#include "Window.h"
#include <iostream>
Window::Window()
{
}


Window::~Window()
{
	SDL_GL_DeleteContext(openglContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetSwapInterval(0);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	window = SDL_CreateWindow("Memes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	openglContext = SDL_GL_CreateContext(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "glew failed to init" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

}

SDL_Window * Window::getWindow()
{
	return window;
}

int Window::getWidth()
{
	return width;
}

int Window::getHeight()
{
	return height;
}

void Window::updateWindowParams()
{
	SDL_GetWindowSize(window, &width, &height);
}

void Window::draw()
{
	//nite::UserTracker* m_pUserTracker;
	openni::VideoStream v;

	nite::UserTrackerFrameRef userTrackerFrame;
	openni::VideoFrameRef* depthFrame = new openni::VideoStream();
	//nite::Status rc = m_pUserTracker->readFrame(&userTrackerFrame);

	v.readFrame(depthFrame);
	std::cout << depthFrame->getSensorType() << std::endl;
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
}
