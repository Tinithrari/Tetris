#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Bouton.hpp"
using namespace std;



class Menu
{
    public:
		enum Etat { NONE, RUN, EXIT, OPTIONS };
        Menu();
        ~Menu();
        void handleEvent(sf::RenderWindow &w);
        void render(sf::RenderTarget &renderer);
		Etat getEtat();
    private:
        // Graphique
        Bouton                  _jouer;
        Bouton                  _options;
        Bouton                  _quitter;
        // Logique
        Etat                    _etat;

};

#endif // MENU_H
