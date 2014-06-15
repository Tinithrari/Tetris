#include "Application.h"

Application::Application() :
_window(sf::VideoMode(800, 960), "Tetris"),
_scene(_window)
{

}

void Application::processEvent()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		_scene.handleEvent(_window);
		if (event.type == sf::Event::Closed)
		{
			_window.close();
		}
	}
}

void Application::update()
{
	_scene.update();
}

void Application::render()
{
	_window.clear();
	_scene.draw();
	_window.display();
}

void Application::run(){
	sf::Clock clock;

	while (_window.isOpen())
	{
		sf::Time tau = clock.restart();
		processEvent();
		update();
		render();
	}
}

int main()
{
	Application app;
	app.run();
}