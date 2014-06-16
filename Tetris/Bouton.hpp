#ifndef BOUTON_H
#define BOUTON_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include <string>

using namespace std;

class Bouton {

public:
	enum Statement {DISABLE, FOCUS, ENABLE};

private:
	//Graphique
	sf::Text				_label;
	sf::RectangleShape		_fond;

	//Logique
	sf::Vector2i			_position;
	sf::Font				_font;
	Statement				_state;
	string					_string;

public:
	Bouton(int posX, int posY, string label);
	~Bouton();
	Statement getState();
	sf::Vector2i getPosition();
	void processEvent(sf::RenderWindow &w);
	void update();
	void render(sf::RenderTarget &renderer);
};

#endif