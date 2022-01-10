#pragma once
class Game : public IGameObject
{
public:
	
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	Model m_model;					// ƒ‚ƒfƒ‹
	Vector3 m_position;				// À•W
	Quaternion m_rotation;			// ‰ñ“]
	Vector3 m_scale = g_vec3One;	// Šg‘å—¦
};

