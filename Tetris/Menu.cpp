#include "Menu.hpp"

using namespace std;

Menu::Menu():
_jouer(275, 300, "Jouer"),
_quitter(225, 500, "Quitter")
{
    _etat=NONE;
}

Menu::~Menu()
{

}

Grille::Genre Menu::getGenre(){
	return _musicSelector.getGenre();
}

void Menu::handleEvent(sf::RenderWindow &w)
{
    _jouer.processEvent(w);
    _quitter.processEvent(w);
	_jouer.update();
	_quitter.update();
    if(_jouer.getState()==Bouton::ENABLE)
    {
        _etat=RUN;
    }
	if (_quitter.getState() == Bouton::ENABLE)
    {
        _etat=EXIT;
    }
	_musicSelector.processEvent(w);
}

Menu::Etat Menu::getEtat()
{
	return _etat;
}
void Menu::render(sf::RenderTarget &renderer)
{
	_jouer.render(renderer);
	_quitter.render(renderer);
	_musicSelector.render(renderer);
}
