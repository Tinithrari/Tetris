#include "MusicSelector.h"

MusicSelector::MusicSelector():
_prev(370,800,"<-"),
_next(670,800,"->"),
_fond(sf::Vector2f(180,100))
{
	_fond.setPosition(sf::Vector2f(480,800));
	_fond.setFillColor(sf::Color(122, 122, 122));

	_font.loadFromFile("res/font/police.ttf");
	_type.setFont(_font);
	_type.setCharacterSize(30);
	_type.setColor(sf::Color::White);
	_type.setPosition(480, 840);
	
	_leType = "Original";
	_prev.setCharacterSize(50);
	_next.setCharacterSize(50);
	_genreMusique = Grille::ORIGINAL;
}

void MusicSelector::processEvent(sf::RenderWindow& w){
	_prev.processEvent(w);
	_next.processEvent(w);
	_prev.update();
	_next.update();
	if (_prev.getState() == Bouton::ENABLE && _pos != 0)
	{
		_genreMusique = Grille::ORIGINAL;
		_leType = "Original";
		_pos--;
	}
	if (_next.getState() == Bouton::ENABLE && _pos != 1)
	{
		_genreMusique = Grille::METAL;
		_leType = "Metal";
		_pos++;
	}
}

Grille::Genre MusicSelector::getGenre(){
	return _genreMusique;
}

void MusicSelector::render(sf::RenderTarget & renderer){
	_type.setString(_leType);
	renderer.draw(_fond);
	renderer.draw(_type);

	_prev.render(renderer);
	_next.render(renderer);
}