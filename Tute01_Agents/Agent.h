#pragma once

#include <vector>
#include <glm\ext.hpp>
#include <glm\vec2.hpp>
#include <glm\fwd.hpp>

namespace aie {
	class Texture;
	class Renderer2D;
}

class IBehaviour;

class Agent
{
public:
	Agent();
	Agent(float x, float y);
	Agent(const char* a_szFilename, glm::vec2& position);
	~Agent();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* a_SpriteBatch);

	void AddBehaviour(IBehaviour* behaviour);
	void Translate(glm::vec2 a_velocity);
	glm::vec2 getPosition();
	void setMaxSpeed(float a_newSpeed);

protected:
	std::vector<IBehaviour*> m_behaviours;
	
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	float m_maxSpeed;

	aie::Texture* m_texture;
};

