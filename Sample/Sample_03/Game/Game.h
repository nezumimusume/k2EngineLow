#pragma once

// 前方宣言。
class Player;
class Background;

class Game : public IGameObject
{
public:
	~Game();
	bool Start() override;
	void Update() override;
private:
	Player* m_player = nullptr;	// プレイヤー
	Background* m_bg = nullptr; // 背景
};

