#include <SFML/Graphics.hpp>
#include "Bouton.hpp"
#include <cassert>

class Pause {

public:
	enum Etat{NONE,REPRENDRE,QUITTER};

private:
	//Graphique
	sf::RectangleShape				_background;
	sf::Text						_tPause;
	
	//Logique
	Bouton							_reprendre;
	Bouton							_quitter;
	sf::Font						_font;
	Etat							_etat;
	
public:
	Pause(sf::RenderWindow& w);
	~Pause();
	void processEvent(sf::RenderWindow& w);
	void render(sf::RenderTarget& renderer);
	Etat getEtat();
};