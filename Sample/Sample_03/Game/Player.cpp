#include "stdafx.h"
#include "Player.h"


bool Player::Start()
{
	ModelInitData initData;
	// tkmファイルのファイルパスを指定する。
	initData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	// シェーダーファイルのファイルパスを指定する。
	initData.m_fxFilePath = "Assets/shader/model.fx";
	// 作成した初期化データをもとにモデルを初期化する、
	m_model.Init(initData);

	m_charaCon.Init(40.0f, 100.0f, g_vec3Zero);

	m_rotation.SetRotationDegY(180.0f);

	return true;
}
void Player::Update()
{
	Vector3 moveSpeed;
	moveSpeed.x = g_pad[0]->GetLStickXF() * 120.0f;
	moveSpeed.z = g_pad[0]->GetLStickYF() * 120.0f;
	m_charaCon.Execute(moveSpeed, g_gameTime->GetFrameDeltaTime());

	m_model.UpdateWorldMatrix(
		m_charaCon.GetPosition(), 
		m_rotation,
		g_vec3One
	);
}
void Player::Render(RenderContext& rc)
{
	m_model.Draw(rc);
}