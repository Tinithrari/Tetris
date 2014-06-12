#include "Grille.h"

Grille::Grille():
_grille(),
grille(10,vector<sf::RectangleShape>(22,sf::RectangleShape(sf::Vector2f(40.f,40.f)))),
_position(4,0),
_tetramino(_tetraminoSuivant),
_suivant(_tetraminoSuivant),
_cadreScore(sf::Vector2f(260.f,160.f))
{
	srand(time(NULL));
	_tetraminoSuivant = (TypeTetramino)((int)rand() % 7);
	nouveauTetramino();
	initGrille();
	_grille.setSize(sf::Vector2f(400.f,880.f));
	_grille.setPosition(40,40);
	_grille.setFillColor(sf::Color(122,122,122,50));
	_grille.setOutlineColor(sf::Color(71, 71, 71));
	_grille.setOutlineThickness(5);
	_cadreScore.setPosition(490,250);
	_cadreScore.setFillColor(sf::Color(122,122,122,50));
	_cadreScore.setOutlineColor(sf::Color(71, 71, 71));
	_cadreScore.setOutlineThickness(5);
	_clock.restart();
	_save = 0;
	_etat = NONE;
	_score = 0;
	_attente = false;
	_font.loadFromFile("police.ttf");
	_textScore.setFont(_font);
	_textScore.setPosition(265,165);
	_textScore.setColor(sf::Color::White);
	_textScore.setCharacterSize(20);
	_str = "Score : " + _score;
	_textScore.setString(_str);
}

Grille::~Grille()
{

}

void Grille::copyTetramino()
{
	for (int i = 0; i < _tetramino.getTailleX(); i++)
		for (int j = 0; j < _tetramino.getTailleY(); j++)
			if (_tetramino.getTetramino()[i][j].getFillColor() != sf::Color::Transparent)
				grille[_position.x+i][_position.y+j] = _tetramino.getTetramino()[i][j];
};

void Grille::nouveauTetramino(){
	_tetramino.setNouveauType(_tetraminoSuivant);
	_tetramino.creerNouveauTetramino();
	_tetramino.genere();
	_tetraminoSuivant = (TypeTetramino)((int)rand() % 7);
	_position.x = 4;
	_position.y = 0;
}

bool Grille::enCollision()
{
	if (_position.y + _tetramino.getTailleY() == 22)
		return true;
	else
	{
		for (int i = _tetramino.getTailleX(); i > 0; i--)
			for (int j = _tetramino.getTailleY(); j > 0; j--)
				if (_tetramino.getTetramino()[i - 1][j - 1].getFillColor() != sf::Color::Transparent)
					if (grille[_position.x + i - 1][_position.y + j].getFillColor() != sf::Color::Transparent)
						return true;
	}
	return false;
};

void Grille::initGrille(){
	for (int i = 0; i < grille.size(); i++)
		for (int j = 0; j < grille[i].size(); j++)
			grille[i][j].setFillColor(sf::Color::Transparent);
}

bool Grille::collisionDroite(){
	int dec = 0;
	if (_position.x + _tetramino.getTailleX() >= 10)
		return false;
	if (_position.y + _tetramino.getTailleY() == 22)
		dec = 1;
	for (int i = _tetramino.getTailleX(); i > 0; i--)
		for (int j = _tetramino.getTailleY(); j > 0; j--)
			if (_tetramino.getTetramino()[i-1][j-1].getFillColor() != sf::Color::Transparent)
				if (grille[_position.x + i][_position.y + (j - 1)].getFillColor() != sf::Color::Transparent)
					return true;
	return false;
}

bool Grille::collisionGauche(){
	int dec = 0;
	int i;
	if (_position.x <= 0)
		return false;
	if (_position.y + _tetramino.getTailleY() == 22)
		dec = 1;
	for (int i = 0; i < _tetramino.getTailleX(); i++)
		for (int j = _tetramino.getTailleY(); j > 0; j--)
			if (_tetramino.getTetramino()[i][j - 1].getFillColor() != sf::Color::Transparent)
				if (_tetramino.getTetramino()[0][j - 1].getFillColor() != sf::Color::Transparent)
						if (grille[_position.x - 1][(_position.y + (j - 1))].getFillColor() != sf::Color::Transparent && _tetramino.getTetramino()[i][j - 1].getFillColor() != sf::Color::Transparent)
							return true;
	return false;
}

void Grille::handleEvent()
{
	if (sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (_position.x + _tetramino.getTailleX() < 10 && !collisionDroite())
				_position.x++;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !collisionGauche())
		{
			if (_position.x > 0)
				_position.x--;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && _etat == NONE)
		{
			_tetramino.tourneADroite();
			if (_position.y + _tetramino.getTailleY() > 21)
				for (int i = (_position.y + _tetramino.getTailleY())-21; i > 0; i--)
					_position.y--;
			if (_position.x + _tetramino.getTailleY() > 10)
				for (int i = (_position.x + _tetramino.getTailleY()) - 10; i > 0; i--)
					_position.x--;
			if (_position.x + _tetramino.getTailleX() >= 10)
				_position.x--;
			if (collisionDroite())
				_position.x--;
			if (enCollision())
				_position.y--;
			_etat = ACTIVATE;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _etat == NONE)
		{
			if (_position.y + _tetramino.getTailleY() > 21)
				for (int i = (_position.y + _tetramino.getTailleY()) - 21; i > 0; i--)
					_position.y--;
			if (_position.x + _tetramino.getTailleY() > 10)
				for (int i = (_position.x + _tetramino.getTailleY()) - 10; i > 0; i--)
					_position.x--;
			if (_position.x + _tetramino.getTailleX() >= 10)
				_position.x--;
			_tetramino.tourneAGauche();
			if (collisionDroite())
				_position.x--;
			if (enCollision())
				_position.y--;
			_etat = ACTIVATE;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _etat == NONE){
			_typeDescente = RAPIDE;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _etat == NONE){
			_typeDescente = INST;
			_etat = ACTIVATE;
		}
		/*
			Ajout de la pause ici (utiliser un else if)
		*/
		else
		{
			_etat = NONE;
			_typeDescente = NORMAL;
		}
	}
};

void Grille::update()
{
	if (!enCollision())
	{
		switch (_typeDescente)
		{
		case NORMAL:
			descenteNormal();
			break;
		case RAPIDE:
			descenteRapide();
			break;
		case INST:
			descenteInstantanee();
			break;
		}
	}
	if (enCollision() && !_attente && _typeDescente != INST)
	{
		_save = _clock.restart().asSeconds();
		_attente = true;
	}
	else if (_attente)
	{
		_save = _clock.getElapsedTime().asSeconds();
		if (_save > 1)
		{
			copyTetramino();
			eraseLine();
			nouveauTetramino();
			_clock.restart();
			_attente = false;
			_save = 0;
			if (enCollision())
				exit(0);
		}
	}
	else if (_typeDescente == INST)
	{
		copyTetramino();
		eraseLine();
		nouveauTetramino();
		_clock.restart();
		_attente = false;
		_save = 0;
		if (enCollision())
			exit(0);
	}
	_typeDescente = NORMAL;
	_str = "Score : \n" + _score;
};

int Grille::getScore(){
	return _score;
}

void Grille::eraseLine()
{
	int i;
	int j = 0;
	bool ligneNonComplete;
	while (j < 22)
	{
		i = 0;
		ligneNonComplete = false;
		while (i < 10 && !ligneNonComplete)
		{
			if (grille[i][j].getFillColor() == sf::Color::Transparent)
				ligneNonComplete = true;
			i++;
		}
		if (!ligneNonComplete)
		{
			if (j == 0)
			{
				for (int x = 0; x < grille.size(); x++)
					grille[x][j].setFillColor(sf::Color::Transparent);
			}
			else
			{
				for (int y = j; y >= 1; y--)
					for (int x = 0; x < grille.size(); x++)
						grille[x][y] = grille[x][y - 1];
			}
			_score += 100;
		}
		j++;
	}
}

void Grille::descenteNormal(){
	_save += _clock.getElapsedTime().asSeconds();
	_position.y = (int)_save;
	_clock.restart();
}

void Grille::descenteRapide()
{
	_save += _clock.getElapsedTime().asSeconds()*250;
	_position.y = (int)_save;
	_clock.restart();
};

void Grille::descenteInstantanee()
{
	while (!enCollision())
		_position.y++;
};

void Grille::render(sf::RenderTarget &renderer)
{
	renderer.draw(_grille);
	renderer.draw(_cadreScore);
	for (int i = 0; i < grille.size(); i++)
	{
		for (int j = 0; j < grille[i].size(); j++)
		{
			grille[i][j].setPosition(40*i+40,40*j+40);
			renderer.draw(grille[i][j]);
		}
	}
	renderer.draw(_textScore);
	_tetramino.draw(renderer,_position.x,_position.y);
};