#include "AttackState.h"
#include "ChaseState.h"



AttackState::AttackState()
{
}


AttackState::~AttackState()
{
}

void AttackState::Update(Agent* agent, StateMachine* sm, float deltaTime)
{
	idleTime += deltaTime;
	if (idleTime >= 3.0f)
	{
		if (glm::length(agent->getTarget()->getPosition() - agent->getPosition()) < 200.0f)
		{
			//attackstuff here
			idleTime = 0.0f;
		}
		else
		{
			agent->SetState(new ChaseState());
		}
	}
}

void AttackState::Init(Agent * agent)
{
	idleTime = 0.0f;
	glm::vec2 velocity = glm::vec2(0, 0);
	agent->Translate(velocity);
}

void AttackState::Exit(Agent * agent)
{
}
