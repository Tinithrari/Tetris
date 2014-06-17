#include "Scene.h"

Scene::Scene(sf::RenderWindow &w) :
window(w),
_view(w.getDefaultView()),
_menu(new Menu())
{
	_jeuLance = false;
}

void Scene::lancerJeu()
{
	Grille::Genre tmp = _menu->getGenre();
	delete _menu;
	_grille = new Grille(tmp);
	_jeuLance = true;
}

void Scene::handleEvent(sf::RenderWindow &w)
{
	if (!_jeuLance)
	{
		_menu->handleEvent(w);
		if (_menu->getEtat() == Menu::RUN)
			lancerJeu();
		if (_menu->getEtat() == Menu::EXIT)
		{
			delete _menu;
			exit(0);
		}
	}
		
	if (_jeuLance)
		_grille->handleEvent(w);
}

void Scene::update()
{
	if (_jeuLance)
		_grille->update();
}

void Scene::draw(){
	if (_jeuLance)
		_grille->render(window);
	if (!_jeuLance)
		_menu->render(window);
}