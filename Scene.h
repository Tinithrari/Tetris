#include "Grille.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Scene{

private:
	//Logique
	Grille				_grille;
	sf::View			_view;
	sf::RenderWindow	&window;

public:
	Scene(sf::RenderWindow &w);
	void handleEvent();
	void update();
	void draw();
};