#include <SFML/Graphics.hpp>
#include "Bouton.hpp"
#include "MusicSelector.h"
#include "Grille.h"

using namespace std;

class Menu {

public:
	enum Etat { NONE, RUN, EXIT};

private:
	// Graphique
	Bouton					_jouer;
	Bouton					_quitter;
	MusicSelector			_musicSelector;
	// Logique
	Etat					_etat;

public:
	Menu();
	~Menu();
	void handleEvent(sf::RenderWindow &w);
	void render(sf::RenderTarget &renderer);
	Grille::Genre getGenre();
	Etat getEtat();
};