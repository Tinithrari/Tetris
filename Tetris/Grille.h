#ifndef GRILLE_H
#define GRILLE_H

#pragma comment(lib, "openal32.lib") 
#pragma comment(lib, "sndfile.lib") 

#include <SFML/Graphics.hpp>
#include "Tetramino.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cassert>
#include <sstream>
#include "Pause.hpp"

#include <SFML/Audio.hpp>

using namespace std;

class Grille{

public:
	enum Genre {ORIGINAL, METAL};
	enum Statement{ NONE, ACTIVATE};
	enum Descente { NORMAL, RAPIDE, INST};
	enum StateGame { PLAYED,PAUSED,OVER };

private:
	//Son
	sf::Music				_music;
	// Graphique
	sf::RectangleShape		_grille;
	tetramino				grille;
	Tetramino				_tetramino;
	Tetramino				_suivant;
	sf::RectangleShape		_cadreScore;
	sf::RectangleShape		_cadreSuivant;
	sf::Text				_textScore;
	Pause*					_pause;
	// Logique
	sf::Vector2f			_position;
	TypeTetramino			_tetraminoSuivant;
	sf::Clock				_clock;
	Statement				_etat;
	Descente				_typeDescente;
	float					_save;
	bool					_attente;
	int						_score;
	sf::Font				_font;
	string					_str;
	StateGame				_stateGame;

public:
	Grille(Genre g);
	~Grille();
	void copyTetramino();
	bool enCollision();
	bool enFusion();
	bool collisionDroite();
	bool collisionGauche();
	void handleEvent(sf::RenderWindow &w);
	void update();
	void eraseLine();
	void nouveauTetramino();
	void descenteRapide();
	void initGrille();
	void descenteNormal();
	void descenteInstantanee();
	void render(sf::RenderTarget &renderer);
	int getScore();
};

#endif