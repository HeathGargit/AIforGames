#include "Agent.h"
#include "IBehaviour.h"
#include "StateMachine.h"
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
	
	if (m_sm != nullptr)
	{
		m_sm->Update(this, deltaTime);
	}
	if (m_behaviours.size() > 0)
	{
		for (auto behavior : m_behaviours)
		{
			behavior->Update(this, deltaTime);
		}
	}

	m_position += m_velocity * deltaTime * m_maxSpeed;
}

void Agent::Draw(aie::Renderer2D * a_SpriteBatch)
{
	a_SpriteBatch->drawSprite(m_texture, m_position.x, m_position.y);
}

void Agent::InitSM()
{
	m_sm = new StateMachine();
}

void Agent::SetState(State* newState)
{
	m_sm->ChangeState(this, newState);
}

void Agent::AddBehaviour(IBehaviour* behaviour)
{
	m_behaviours.push_back(behaviour);
}

Agent * Agent::getTarget()
{
	return m_targetAgent;
}

void Agent::setTarget(Agent * targetAgent)
{
	m_targetAgent = targetAgent;
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
