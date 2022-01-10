#include "stdafx.h"
#include "Game.h"

bool Game::Start()
{
	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/laser.efk");
	EffectEngine::GetInstance()->ResistEffect(1, u"Assets/effect/laser2.efk");

	

	return true;
}
void Game::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA)) {
		EffectEmitter* laserEffectEmitter = NewGO<EffectEmitter>(0);
		laserEffectEmitter->Init(0);
		laserEffectEmitter->Play();
	}
	if (g_pad[0]->IsTrigger(enButtonB)) {
		EffectEmitter* laserEffectEmitter = NewGO<EffectEmitter>(0);
		laserEffectEmitter->Init(1);
		laserEffectEmitter->Play();
	}
}
void Game::Render(RenderContext& rc)
{

}