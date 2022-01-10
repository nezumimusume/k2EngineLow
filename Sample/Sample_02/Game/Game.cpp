#include "stdafx.h"
#include "Game.h"


void Game::InitSkeleton()
{
	m_skeleton.Init("Assets/modelData/unityChan.tks");
}
void Game::InitModel()
{
	ModelInitData initData;
	//tkmファイルのファイルパスを指定する。
	initData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	//シェーダーファイルのファイルパスを指定する。
	initData.m_fxFilePath = "Assets/shader/model.fx";
	//ノンスキンメッシュ用の頂点シェーダーのエントリーポイントを指定する。
	initData.m_vsEntryPointFunc = "VSMain";
	//スキンメッシュ用の頂点シェーダーのエントリーポイントを指定。
	initData.m_vsSkinEntryPointFunc = "VSSkinMain";
	//スケルトンを指定する。
	initData.m_skeleton = &m_skeleton;
	//モデルの上方向を指定する。
	//3dsMaxではデフォルトZアップになっているが、
	//ユニティちゃんはアニメーションでYアップに変更されている。
	initData.m_modelUpAxis = enModelUpAxisY;

	//作成した初期化データをもとにモデルを初期化する、
	m_model.Init(initData);
}

void Game::InitAnimation()
{
	//アニメーションクリップをロードする。
	m_animationClipArray[enAnimClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClipArray[enAnimClip_Idle].SetLoopFlag(true);
	m_animationClipArray[enAnimClip_Run].Load("Assets/animData/walk.tka");
	m_animationClipArray[enAnimClip_Run].SetLoopFlag(true);
	//アニメーションを初期化。
	m_animation.Init(
		m_skeleton,			//アニメーションを流し込むスケルトン。
		m_animationClipArray,	//アニメーションクリップ。
		enAnimClip_Num		//アニメーションの数。
	);
}

bool Game::Start()
{
	//スケルトンをロード。
	InitSkeleton();
	//モデルを初期化。
	InitModel();
	//アニメーションを初期化。
	InitAnimation();

	return true;
}

void Game::Update()
{
	// アニメーションの切り替え。
	if (g_pad[0]->IsPress(enButtonA)) {
		m_animation.Play(enAnimClip_Idle, 0.2f);
	}
	if (g_pad[0]->IsPress(enButtonB)) {
		m_animation.Play(enAnimClip_Run, 0.2f);
	}
	// 回転
	m_rotation.AddRotationY(g_pad[0]->GetRStickXF() * 0.05f);

	// 平行移動
	m_position.x += g_pad[0]->GetLStickXF();
	m_position.y += g_pad[0]->GetLStickYF();

	//スケルトンを更新。
	m_skeleton.Update(m_model.GetWorldMatrix());

	//アニメーションを進める。
	m_animation.Progress(g_gameTime->GetFrameDeltaTime());

	// ワールド行列を更新。
	m_model.UpdateWorldMatrix(m_position, m_rotation, g_vec3One);
}
void Game::Render(RenderContext& rc)
{
	// ドロー。
	m_model.Draw(rc);
}