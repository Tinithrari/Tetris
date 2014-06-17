#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "openal32.lib") 
#pragma comment(lib, "sndfile.lib")
#pragma comment(lib, "sfml-audio-s.lib")
#pragma comment(lib, "sfml-main.lib")
#endif // SFML_STATIC

#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include "Scene.h"

using namespace std;

class Application {

private:
	// Graphique
	sf::RenderWindow		_window;
	
	//Logique
	Scene					_scene;

public:
	Application();
	void run();
	void processEvent();
	void update();
	void render();
};