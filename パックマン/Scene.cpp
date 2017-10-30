#include "Scene.h"
#include "BackGround.h"
#include "Start.h"
Scene::Scene()
{
	m_BackGround = new BackGround();
	m_Start = new Start();
}

Scene::~Scene()
{
	delete m_BackGround;
	delete m_Start;
}

void Scene::Draw()
{
	m_BackGround->Draw();
}

void Scene::StartDraw()
{
	m_Start->Draw();
}