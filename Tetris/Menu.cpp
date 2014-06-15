#include "Menu.h"


using namespace std;

Menu::Menu()
_window(sf::VideoMode(800, 960), "Tetris"),
_jouer(10.0,50.0,"Jouer"),
_options(10.0,100.0,"Options"),
_quitter(10.0,150.0,"Quitter"),
_scene(_window)
{
    _etat=NONE;
}

Menu::~Menu()
{

}

void Menu::handleEvent()
{
    _jouer.processEvent();
    _options.processEvent();
    _quitter.processEvent();
    if(_jouer.getState())==ENABLE)
    {
        _etat=RUN;
    }
    if(_options.getState()==ENABLE)
    {
        _etat=OPTIONS;
    }
    if(_quitter.getState()==ENABLE)
    {
        _etat=EXIT;
    }
}

void Menu::update()
{
    _jouer.update();
    _options.update();
    _quitter.update();
    if(_etat==RUN)
    {
        // quitte le menu pour lancer le jeu
    }
    if(_etat==OPTIONS)
    {
        // lance la fenetre des options
    }
    if(_etat==EXIT)
    {
        // quitte le menu et la fenetre
    }

}

void Menu::render(sf::RenderTarget &renderer)
{
    _jouer.render();
    _options.render();
    _quitter.render();
}
