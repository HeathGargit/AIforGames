#include "PatrolState.h"
#include "ChaseState.h"
#include <vector>
#include <glm\ext.hpp>
#include <glm\vec2.hpp>
#include <glm\fwd.hpp>


PatrolState::PatrolState()
{
}


PatrolState::~PatrolState()
{
}

void PatrolState::Update(Agent* agent, StateMachine* sm, float deltaTime)
{
	glm::vec2 velocity = agent->getPosition() - agent->getTarget()->getPosition();
	float distance = glm::length(velocity);
	if (distance < 400.0f)
	{
		agent->SetState(new ChaseState());
		return;
	}
	velocity = agent->getPosition() - m_PatrolNodes.at(m_CurrentNode);
	distance = glm::length(velocity);
	if (distance < 60.0f)
	{
		m_CurrentNode++;
		if (m_CurrentNode > 3)
			m_CurrentNode = 0;
	}
	velocity = m_PatrolNodes.at(m_CurrentNode) - agent->getPosition();
	velocity = glm::normalize(velocity);
	agent->Translate(velocity);
}

void PatrolState::Init(Agent * agent)
{
	m_PatrolNodes.push_back(glm::vec2(100, 620));
	m_PatrolNodes.push_back(glm::vec2(1180, 620));
	m_PatrolNodes.push_back(glm::vec2(1180, 100));
	m_PatrolNodes.push_back(glm::vec2(100, 100));
}

void PatrolState::Exit(Agent * agent)
{
}
