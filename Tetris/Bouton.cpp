#include "Bouton.hpp"

Bouton::Bouton(int posX, int posY, string label):
_position(posX, posY)
{
	_label.setString(label);
	assert(_font.loadFromFile("police.ttf")==true);
	_label.setFont(_font);
	_label.setCharacterSize(50);
	_state = DISABLE;

	_fond.setPosition((sf::Vector2f)_position);
	_fond.setSize(sf::Vector2f(_label.getCharacterSize()*_label.getString().getSize() + 50,_label.getCharacterSize()+50));
	_fond.setFillColor(sf::Color(122, 122, 122));

	_label.setPosition(_fond.getPosition().x + 25, _fond.getPosition.y + 25);
	_label.setColor(sf::Color::White);

}

Bouton::~Bouton(){}

Bouton::Statement Bouton::getState() {
	return _state;
}

sf::Vector2i Bouton::getPosition() {
	return _position;
}

void Bouton::processEvent(sf::RenderWindow &w){
	if (_fond.getLocalBounds().contains(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y))
	{
		_state = FOCUS;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			_state = ENABLE;
	}
}

void Bouton::update(){
	if (_state == FOCUS)
	{
		_fond.setFillColor(sf::Color(142, 142, 142));
	}
	else if (_state == ENABLE)
	{
		_fond.setFillColor(sf::Color(102, 102, 102));
	}
	else
	{
		_fond.setFillColor(sf::Color(122, 122, 122));
	}
}

void Bouton::render(sf::RenderTarget & renderer){
	renderer.draw(_fond);
	renderer.draw(_label);
}