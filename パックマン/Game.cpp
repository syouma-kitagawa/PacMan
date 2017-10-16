#include "Game.h"
#include "Player.h"
#include "DirectGraphics.h"
#include "FileLoad.h"

Game::Game()
{
	m_pPlayer = NULL;
	m_pPlayer = new Player();
}
Game::~Game()
{
	delete m_pPlayer;
}
void Game::Update()
{
	m_pPlayer->Update();
}
void Game::Draw()
{
	DirectGraphics::pInstance->StartRender();
	m_pPlayer->Draw();
	DirectGraphics::pInstance->EndRender();
}
void Game::RunGame() 
{
	Update();
	Draw();
}