#include "Agent.h"
#include "IBehaviour.h"
#include <Texture.h>
#include <Renderer2D.h>

Agent::Agent()
{
}

Agent::Agent(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

Agent::Agent(const char * a_szFilename, glm::vec2& position)
{
	m_texture = new aie::Texture(a_szFilename);
	m_position = position;

	m_maxSpeed = 100.0f;
}

Agent::~Agent()
{
}

void Agent::Update(float deltaTime)
{
	m_position += m_velocity * deltaTime * m_maxSpeed;

	for (auto behavior : m_behaviours)
	{
		behavior->Update(this, deltaTime);
	}
}

void Agent::Draw(aie::Renderer2D * a_SpriteBatch)
{
	a_SpriteBatch->drawSprite(m_texture, m_position.x, m_position.y);
}

void Agent::AddBehaviour(IBehaviour* behaviour)
{
	m_behaviours.push_back(behaviour);
}

void Agent::Translate(glm::vec2 a_velocity)
{
	this->m_velocity = a_velocity;
}

glm::vec2 Agent::getPosition()
{
	return m_position;
}

void Agent::setMaxSpeed(float a_newSpeed)
{
	m_maxSpeed = a_newSpeed;
}
