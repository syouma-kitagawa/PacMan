#include "Game.h"
#include "Player.h"
#include "Scene.h"
#include "DirectGraphics.h"
#include "CookieCreate.h"
Game::Game()
{
	m_pPlayer = new Player();
	m_pCookie = new Cookie();
	m_pScene = new Scene();
}
Game::~Game()
{
	delete m_pPlayer;
	delete m_pCookie;
	delete m_pScene;
}
void Game::Update()
{
	m_pPlayer->Update();
}

void Game::Draw()
{
	DirectGraphics::pInstance->StartRender();
	m_pScene->Draw();
	m_pCookie->Draw();
	m_pPlayer->Draw();
	DirectGraphics::pInstance->EndRender();
}
void Game::RunGame() 
{
	Update();
	Draw();
}