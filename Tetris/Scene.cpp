#include "Scene.h"

Scene::Scene(sf::RenderWindow &w) :
window(w),
_view(w.getDefaultView())
{
	_jeuLance = false;
	//Construire le menu iciv--et-r-tezf-
}

void Scene::lancerJeu()
{
	//Detruire menu ici (delete var)edfsf
	_grille = new Grille();
	_jeuLance = true;
}

void Scene::handleEvent()
{
	if (_jeuLance)
		_grille->handleEvent();
}

void Scene::update()
{
	if (_jeuLance)
		_grille->update();
}

void Scene::draw(){
	if (_jeuLance)
		_grille->render(window);
}