#include <SFML/Graphics.hpp>
#include "Tetramino.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cassert>

using namespace std;

enum Statement{ NONE, ACTIVATE};
enum Descente { NORMAL, RAPIDE, INST};

class Grille{
private:
	// Graphique
	sf::RectangleShape		_grille;
	tetramino				grille;
	Tetramino				_tetramino;
	Tetramino				_suivant;
	sf::RectangleShape		_cadreScore;
	sf::Text				_textScore;
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

public:
	Grille();
	~Grille();
	void copyTetramino();
	bool enCollision();
	bool collisionDroite();
	bool collisionGauche();
	void handleEvent();
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