#include "Bouton.hpp"

Bouton::Bouton(int posX, int posY, string label):
_position(posX, posY)
{
	_string = label;
	_label.setString(_string);
	_font.loadFromFile("police.ttf");
	_label.setFont(_font);
	_label.setCharacterSize(50);
	_state = DISABLE;

	_fond.setPosition((sf::Vector2f)_position);
	_fond.setSize(sf::Vector2f((_label.getCharacterSize()*_label.getString().getSize()),_label.getCharacterSize()+50));
	_fond.setFillColor(sf::Color(122, 122, 122));

	_label.setPosition(_fond.getPosition().x + 25, _fond.getPosition().y + 25);
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
	if (_fond.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(w))))
	{
		_state = FOCUS;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			_state = ENABLE;
	}
	else
		_state = DISABLE;
}

void Bouton::update(){
	if (_state == FOCUS)
	{
		_fond.setFillColor(sf::Color(162, 162, 162));
	}
	else if (_state == ENABLE)
	{
		_fond.setFillColor(sf::Color(82, 82, 82));
	}
	else
	{
		_fond.setFillColor(sf::Color(122, 122, 122));
	}
}

void Bouton::render(sf::RenderTarget & renderer){
	renderer.draw(_fond);
	_label.setString(_string);
	renderer.draw(_label);
}