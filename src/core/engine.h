#pragma once
#include <iostream>

class Window;
class SDL_Renderer;

class Engine
{
public:
	Engine();
	~Engine();

	void init();
	void handle_events();
	void start();
	void update();
	void render();
	void clean();

	bool running = false;
};