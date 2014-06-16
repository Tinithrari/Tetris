#include "Menu.h"


using namespace std;

Menu::Menu():
_jouer(275.0,300.0,"Jouer"),
_options(225.0,450.0,"Options"),
_quitter(225.0,600.0,"Quitter")
{
    _etat=NONE;
}

Menu::~Menu()
{

}

void Menu::handleEvent(sf::RenderWindow &w)
{
    _jouer.processEvent(w);
    _options.processEvent(w);
    _quitter.processEvent(w);
	_jouer.update();
	_options.update();
	_quitter.update();
    if(_jouer.getState()==Bouton::ENABLE)
    {
        _etat=RUN;
    }
	if (_options.getState() == Bouton::ENABLE)
    {
        _etat=OPTIONS;
    }
	if (_quitter.getState() == Bouton::ENABLE)
    {
        _etat=EXIT;
    }
	
}

Menu::Etat Menu::getEtat()
{
	return _etat;
}
void Menu::render(sf::RenderTarget &renderer)
{
	_jouer.render(renderer);
	_options.render(renderer);
	_quitter.render(renderer);
}
