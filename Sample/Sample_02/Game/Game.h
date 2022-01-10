#pragma once
class Game : public IGameObject
{
public:
	
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	// スケルトンを初期化
	void InitSkeleton();
	// モデルを初期化。
	void InitModel();
	// アニメーションを初期化。
	void InitAnimation();
private:
	// アニメーションクリップの番号を表す列挙型。
	enum EnAnimationClip {
		enAnimClip_Idle,	// 0 : 待機アニメーション、
		enAnimClip_Run,		// 1 : 走りアニメーション。
		enAnimClip_Num,		// 2 :アニメーションクリップの数。
	};
	Model m_model;			// モデル
	Skeleton m_skeleton;	// スケルトン
	Animation m_animation;	// アニメーション
	AnimationClip m_animationClipArray[enAnimClip_Num];	// アニメーションクリップ
	Vector3 m_position;		// 座標
	Quaternion m_rotation;	// 回転
};

