#include "ChaseState.h"
#include "AttackState.h"
#include "PatrolState.h"


ChaseState::ChaseState()
{
}


ChaseState::~ChaseState()
{
}

void ChaseState::Update(Agent* agent, StateMachine* sm, float deltaTime)
{
	glm::vec2 velocity = m_TargetAgent->getPosition() - agent->getPosition();
	float distance = glm::length(velocity);
	if (distance > 100.0f && distance < 400.0f)
	{
		velocity = glm::normalize(velocity);
	}
	else if (distance <= 100.0f)
	{
		agent->SetState(new AttackState());
		return;
	}
	else
	{
		agent->SetState(new PatrolState());
		return;
	}
	agent->Translate(velocity);
}

void ChaseState::Init(Agent* agent)
{
	if (agent->getTarget() != nullptr)
	{
		m_TargetAgent = agent->getTarget();
	}
}

void ChaseState::Exit(Agent * agent)
{

}
