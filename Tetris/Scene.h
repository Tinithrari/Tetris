#include "Grille.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Scene{

private:
	//Logique
	Grille*				_grille;
	sf::View			_view;
	sf::RenderWindow	&window;
	bool				_jeuLance;

public:
	Scene(sf::RenderWindow &w);
	void lancerJeu();
	void handleEvent(sf::RenderWindow &w);
	void update();
	void draw();
};