#include "stdafx.h"
#include "Game.h"

void Game::Render(RenderContext& rc)
{
	Font font;
	font.Begin(rc);
	font.Draw(L"ÇÕÇÎÅ[ÇÌÅ[ÇÈÇ«", { 0, 0 }, g_vec4White, 0.0f, 1.0f, { 0.0f, 0.0f });
	font.End(rc);
}