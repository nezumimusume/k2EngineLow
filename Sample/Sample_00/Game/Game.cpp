#include "stdafx.h"
#include "Game.h"


bool Game::Start()
{
	// モデルを初期化するための情報を設定。
	ModelInitData initData;
	//tkmファイルのファイルパスを指定する。
	initData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	//シェーダーファイルのファイルパスを指定する。
	initData.m_fxFilePath = "Assets/shader/model.fx";

	//作成した初期化データをもとにモデルを初期化する、
	m_model.Init(initData);
	return true;
}
void Game::Update()
{
	
}
void Game::Render(RenderContext& rc)
{
	m_model.Draw(rc);
}