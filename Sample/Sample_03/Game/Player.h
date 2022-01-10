#pragma once
// プレイヤークラス。
class Player : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc);
private:
	
	Model m_model;					// モデル
	Vector3 m_position;				// 座標
	Quaternion m_rotation;			// 回転
	CharacterController m_charaCon;	// キャラコン。
};

