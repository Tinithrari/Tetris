#include "Scene.h"

Scene::Scene(sf::RenderWindow &w) :
window(w),
_view(w.getDefaultView())
{

}

void Scene::handleEvent()
{
	_grille.handleEvent();
}

void Scene::update()
{
	_grille.update();
}

void Scene::draw(){
	_grille.render(window);
}