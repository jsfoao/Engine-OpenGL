#pragma once

extern Nata::Application* CreateApplication();

int main(int argc, char** argv)
{
	auto app = CreateApplication();
	app->run();
	delete app;
}