#include <SFML/Graphics.hpp>
#include <string>
#include "Bouton.hpp"
#include "Grille.h"

using namespace std;

class MusicSelector {

private:

	Grille::Genre				_genreMusique;
	sf::Font					_font;
	sf::Text					_type;
	Bouton						_prev;
	Bouton						_next;
	sf::RectangleShape			_fond;
	string						_leType;
	int							_pos = 0;

public:

	MusicSelector();
	void processEvent(sf::RenderWindow &w);
	Grille::Genre getGenre();
	void render(sf::RenderTarget & renderer);

};