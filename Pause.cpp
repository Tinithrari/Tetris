#include "Pause.hpp"

Pause::Pause(sf::RenderWindow& w):
_background(w.getSize()),
_reprendre(225,250,"Reprendre"),
_quitter(383,350,"Quitter") 
{
	_background.setFillColor(sf::Color(0,0,0,125));
	_background.setPosition(sf::Vector2f(0,0));
	assert(_font.loadFromFile("police.ttf")==true);
	_tPause.setFont(_font);
	_tPause.setString("Pause");
	_tPause.setColor(sf::Color::White);
	_tPause.setCharacterSize(50);
	_tPause.setPosition(sf::Vector2f(387,150));
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
	if(_reprendre.getState()==Bouton::ACTIVATE)
		_etat=REPRENDRE;
	else if(_quitter.getState()==Bouton::ACTIVATE)
		_etat=QUITTER;
}

Etat Pause::getEtat()
{
	return _etat;
}


void Pause::render(sf::RenderTarget& renderer)
{
	renderer.draw(_background);
	renderer.draw(_tPause);
	_reprendre.render(renderer);
	_quitter.render(renderer);
}