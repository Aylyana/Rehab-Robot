#pragma once
#include <iostream>
#include <SDL.h>
#include <GL\glew.h>
#include <OpenNI.h>
#include <NiTE.h>

class Window
{
private:
	int width = 800;
	int height = 600;
	SDL_Window* window;
	SDL_GLContext openglContext;
public:
	Window();
	~Window();

	void init();

	SDL_Window* getWindow();

	int getWidth();
	int getHeight();
	void updateWindowParams();
	void draw();
};