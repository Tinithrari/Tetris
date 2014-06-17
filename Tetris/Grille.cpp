#include "Grille.h"

Grille::Grille(Genre g):
_grille(),
grille(10,vector<sf::RectangleShape>(22,sf::RectangleShape(sf::Vector2f(40.f,40.f)))),
_position(4,0),
_tetramino(_tetraminoSuivant),
_suivant(_tetraminoSuivant),
_cadreScore(sf::Vector2f(260.f,160.f)),
_cadreSuivant(sf::Vector2f(260.f,260.f))
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
	
	_cadreScore.setPosition(490,360);
	_cadreScore.setFillColor(sf::Color(122,122,122,50));
	_cadreScore.setOutlineColor(sf::Color(71, 71, 71));
	_cadreScore.setOutlineThickness(5);
	
	_cadreSuivant.setPosition(490,40);	
	_cadreSuivant.setFillColor(sf::Color(122,122,122,50));
	_cadreSuivant.setOutlineColor(sf::Color(71, 71, 71));
	_cadreSuivant.setOutlineThickness(5);
	_clock.restart();
	_save = 0;
	_etat = NONE;
	_score = 0;
	_attente = false;
	_font.loadFromFile("res/font/police.ttf");
	_textScore.setFont(_font);
	_textScore.setPosition(490,429);
	_textScore.setColor(sf::Color::White);
	_textScore.setCharacterSize(22);
	_str = "Score : \n" + _score;
	_textScore.setString(_str);
	_stateGame=PLAYED;

	switch (g)
	{
	case ORIGINAL :
		_music.openFromFile("res/audio/original.ogg");
		break;
	case METAL :
		_music.openFromFile("res/audio/metal.ogg");
		break;
	}

	_music.setVolume(100);
	_music.setLoop(true);
	_music.play();
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
	_suivant.setNouveauType(_tetraminoSuivant);
	_suivant.creerNouveauTetramino();
	_suivant.genere();
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

bool Grille::enFusion(){
	for (int i = 0 ; i < _tetramino.getTailleX(); i++)
		for (int j = 0; j < _tetramino.getTailleY(); j++)
			if ((grille[i+_position.x][j+_position.y].getFillColor() != sf::Color::Transparent) && (_tetramino.getTetramino()[i][j].getFillColor() != sf::Color::Transparent))
				return true;
	return false;
}

void Grille::handleEvent(sf::RenderWindow &w)
{
	if (sf::Event::KeyPressed)
	{
		if (_stateGame == PLAYED)
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
				int iterator = 0;
				while (collisionDroite() || (_position.x + _tetramino.getTailleX() >= 10))
				{
					_position.x--;
					iterator++;
				}
				if (!enFusion())
				{
					if (_position.y + _tetramino.getTailleY() > 21)
					while ((_position.y + _tetramino.getTailleY()) - 21 > 0 || enCollision())
						_position.y--;
					while (enFusion())
						_position.y--;
					if (_position.x + _tetramino.getTailleY() > 10)
						for (int i = (_position.x + _tetramino.getTailleY()) - 10; i > 0; i--)
							_position.x--;
					if (enCollision())
						_position.y--;
					if (_attente)
					{
						_attente = false;
						_save = _position.y;
					}
				}
				else
				{
					_tetramino.tourneAGauche();
					_position.x += iterator;
				}
				_etat = ACTIVATE;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _etat == NONE)
			{
				_tetramino.tourneAGauche();
				int iterator = 0;
				while (collisionDroite() || (_position.x + _tetramino.getTailleX() >= 10))
				{
					_position.x--;
					iterator++;
				}
				if (!enFusion())
				{
					if (_position.y + _tetramino.getTailleY() > 21)
					while ((_position.y + _tetramino.getTailleY()) - 21 > 0)
						_position.y--;
					if (_position.x + _tetramino.getTailleY() > 10)
						for (int i = (_position.x + _tetramino.getTailleY()) - 10; i > 0; i--)
							_position.x--;
					while (enCollision())
						_position.y--;
				}
				else
				{
					_tetramino.tourneADroite();
					_position.x += iterator;
				}
				if (_attente)
				{
					_attente = false;
					_save = _position.y;
				}
				_etat = ACTIVATE;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && _etat == NONE){
				_typeDescente = RAPIDE;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _etat == NONE){
				_typeDescente = INST;
				_etat = ACTIVATE;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && _stateGame == PLAYED && _etat == NONE) {
				_stateGame = PAUSED;
				_etat = ACTIVATE;
				_music.pause();
				_pause = new Pause(w);
			}
			else
			{
				_typeDescente = NORMAL;
			}
		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && _stateGame == PAUSED && _etat == NONE) {
				_stateGame = PLAYED;
				_etat = ACTIVATE;
				_clock.restart();
				_music.play();
				delete _pause;
			}
		}
		if (_stateGame == PAUSED) {
			_pause->processEvent(w);
			if (_pause->getEtat() == Pause::REPRENDRE)
			{
				_stateGame = PLAYED;
				_clock.restart();
				_music.play();
				delete _pause;
			}
			if (_pause->getEtat() == Pause::QUITTER)
			{
				delete _pause;
				exit(0);
			}
		}
	}
};

void Grille::update()
{
	if (_stateGame == PLAYED)
	{
		if (_attente && !enCollision())
		{
			_attente = false;
			_save = _position.y;
		}
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
			_clock.restart().asSeconds();
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
	}
	_etat = NONE;
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
	renderer.draw(_cadreSuivant);
	_suivant.draw(renderer,13,2);
	renderer.draw(_cadreScore);
	for (int i = 0; i < grille.size(); i++)
	{
		for (int j = 0; j < grille[i].size(); j++)
		{
			grille[i][j].setPosition(40*i+40,40*j+40);
			renderer.draw(grille[i][j]);
		}
	}
	stringstream ss;
	ss << _score;
	_str = "Score : " + ss.str();
	_textScore.setString(_str);
	renderer.draw(_textScore);
	_tetramino.draw(renderer,_position.x,_position.y);
	if (_stateGame == PAUSED)
	{
		_pause->render(renderer);
	}
};