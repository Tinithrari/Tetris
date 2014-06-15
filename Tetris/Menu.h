#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Bouton.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

enum Etat {NONE,RUN,EXIT,OPTIONS};

class Menu
{
    public:
        Menu();
        ~Menu();
        void handleEvent();
        void update();
        void render(sf::RenderTarget &renderer);
    private:
        // Graphique
        Bouton                  _jouer;
        Bouton                  _options;
        Bouton                  _quitter;
        // Logique
        sf::Vector2f			_position2;
        Etat                    _etat;

};

#endif // MENU_H
