#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Background.h"


Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_bg);
}
bool Game::Start()
{
	m_player = NewGO<Player>(0);
	m_bg = NewGO<Background>(0);

	return true;
}

void Game::Update()
{
}