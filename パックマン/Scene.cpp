#include "Scene.h"
#include "BackGround.h"

Scene::Scene()
{
	m_BackGround = new BackGround();
}

Scene::~Scene()
{
	delete m_BackGround;
}

void Scene::Draw()
{
	m_BackGround->Draw();
}