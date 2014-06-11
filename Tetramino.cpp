#include "Tetramino.h"

Tetramino::Tetramino(TypeTetramino &t)
{
	type = t;
	creerNouveauTetramino();
	genere();
}

void Tetramino::tourneADroite(){
	tetramino tmp;
	for (int i = 0; i < tailleY; i++)
	{
		tmp.push_back(vector<sf::RectangleShape>());
		for (int j = 0; j < tailleX; j++)
			tmp[i].push_back(sf::RectangleShape());
	}

	for (int i = 0; i < tailleX; i++)
	{
		for (int j = 0; j < tailleY; j++)
		{
			tmp[j][i] = _tetramino[(tailleX-1)-i][j];
		}
	}
	swap(tailleX,tailleY);
	_tetramino = tmp;
}

void Tetramino::tourneAGauche(){
	tetramino tmp;
	for (int i = 0; i < tailleY; i++)
	{
		tmp.push_back(vector<sf::RectangleShape>());
		for (int j = 0; j < tailleX; j++)
			tmp[i].push_back(sf::RectangleShape());
	}

	for (int i = 0; i < tailleX; i++)
	{
		for (int j = 0; j < tailleY; j++)
		{
			tmp[j][i] = _tetramino[i][(tailleY - 1) - j];
		}
	}
	swap(tailleX, tailleY);
	_tetramino = tmp;
}

void Tetramino::setNouveauType(TypeTetramino &t){
	type = t;
}

void Tetramino::creerNouveauTetramino(){

	if (type == I)
	{
		tailleX = 1;
		tailleY = 4;
		_color = sf::Color(92, 204, 204);
	}
	else if (type == O)
	{
		tailleX = 2;
		tailleY = 2;
		_color = sf::Color(255, 255, 0);
	}
	else if (type == L || type == J)
	{
		tailleX = 2;
		tailleY = 3;
		if (type == L)
			_color = sf::Color(255, 116, 0);
		else
			_color = sf::Color::Blue;
	}
	else if (type == S || type == Z || type == T)
	{
		tailleX = 3;
		tailleY = 2;
		if (type == S)
			_color = sf::Color::Green;
		else if (type == Z)
			_color = sf::Color::Red;
		else
			_color = sf::Color(113, 9, 170);
	}
	for (int i = 0; i < tailleX; i++)
	{
		_tetramino.push_back(vector<sf::RectangleShape>());
		for (int j = 0; j < tailleY; j++)
		{
			_tetramino[i].push_back(sf::RectangleShape(sf::Vector2f(39.f, 39.f)));
			_tetramino[i][j].setOutlineThickness(1);
		}
	}
}

void Tetramino::genere(){
	switch (type)
	{
	case I:
		_tetramino[0][0].setFillColor(_color);
		_tetramino[0][1].setFillColor(_color);
		_tetramino[0][2].setFillColor(_color);
		_tetramino[0][3].setFillColor(_color);
		break;
	case L:
		_tetramino[0][0].setFillColor(_color);
		_tetramino[0][1].setFillColor(_color);
		_tetramino[0][2].setFillColor(_color);

		_tetramino[1][0].setFillColor(sf::Color::Transparent);
		_tetramino[1][1].setFillColor(sf::Color::Transparent);
		_tetramino[1][2].setFillColor(_color);
		break;
	case J:
		_tetramino[0][0].setFillColor(sf::Color::Transparent);
		_tetramino[0][1].setFillColor(sf::Color::Transparent);
		_tetramino[0][2].setFillColor(_color);

		_tetramino[1][0].setFillColor(_color);
		_tetramino[1][1].setFillColor(_color);
		_tetramino[1][2].setFillColor(_color);
		break;
	case O:
		_tetramino[0][0].setFillColor(_color);
		_tetramino[0][1].setFillColor(_color);

		_tetramino[1][0].setFillColor(_color);
		_tetramino[1][1].setFillColor(_color);
		break;
	case S:
		_tetramino[0][0].setFillColor(sf::Color::Transparent);
		_tetramino[0][1].setFillColor(_color);

		_tetramino[1][0].setFillColor(_color);
		_tetramino[1][1].setFillColor(_color);

		_tetramino[2][0].setFillColor(_color);
		_tetramino[2][1].setFillColor(sf::Color::Transparent);
		break;
	case T:
		_tetramino[0][0].setFillColor(_color);
		_tetramino[0][1].setFillColor(sf::Color::Transparent);

		_tetramino[1][0].setFillColor(_color);
		_tetramino[1][1].setFillColor(_color);

		_tetramino[2][0].setFillColor(_color);
		_tetramino[2][1].setFillColor(sf::Color::Transparent);
		break;
	case Z:
		_tetramino[0][0].setFillColor(_color);
		_tetramino[0][1].setFillColor(sf::Color::Transparent);

		_tetramino[1][0].setFillColor(_color);
		_tetramino[1][1].setFillColor(_color);

		_tetramino[2][0].setFillColor(sf::Color::Transparent);
		_tetramino[2][1].setFillColor(_color);
		break;
	}

	for (int i = 0; i < _tetramino.size(); i++)
	{
		for (int j = 0; j < _tetramino[i].size(); j++)
		{
			if (_tetramino[i][j].getFillColor() != sf::Color::Transparent)
				_tetramino[i][j].setOutlineColor(sf::Color::Black);
			else
				_tetramino[i][j].setOutlineColor(sf::Color::Transparent);
		}
	}
}

void Tetramino::draw(sf::RenderTarget &renderer, int posX, int posY){
	for (int i = 0; i < tailleX; i++)
		for (int j = 0; j < tailleY; j++)
		{
			_tetramino[i][j].setPosition(((posX*40)+i*40)+40, ((posY*40)+j*40)+40);
			renderer.draw(_tetramino[i][j]);
		}
}

int Tetramino::getTailleX(){
	return tailleX;
}

int Tetramino::getTailleY(){
	return tailleY;
}

tetramino Tetramino::getTetramino(){
	return _tetramino;
}