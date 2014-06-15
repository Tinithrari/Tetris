#include "Pause.hpp"

Pause::Pause(sf::RenderWindow& w):
_background(sf::Vector2f(w.getSize())),
_reprendre(225,250,"Reprendre"),
_quitter(275,400,"Quitter") 
{
	_background.setFillColor(sf::Color(0,0,0,125));
	_background.setPosition(sf::Vector2f(0,0));
	_font.loadFromFile("police.ttf");
	_tPause.setFont(_font);
	_tPause.setColor(sf::Color::White);
	_tPause.setCharacterSize(50);
	_tPause.setPosition(sf::Vector2f(325,150));
	_etat=NONE;
}

Pause::~Pause()
{
}

void Pause::processEvent(sf::RenderWindow& w)
{
	_reprendre.processEvent(w);
	_quitter.processEvent(w);
	_reprendre.update();
	_quitter.update();
	if(_reprendre.getState()==Bouton::ENABLE)
		_etat=REPRENDRE;
	else if(_quitter.getState()==Bouton::ENABLE)
		_etat=QUITTER;
}

Pause::Etat Pause::getEtat()
{
	return _etat;
}


void Pause::render(sf::RenderTarget& renderer)
{
	renderer.draw(_background);
	_reprendre.render(renderer);
	_quitter.render(renderer);
	_tPause.setString("Pause");
	renderer.draw(_tPause);
}