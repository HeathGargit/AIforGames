#pragma once
#include "State.h"

class ChaseState : public State
{
public:
	ChaseState();
	~ChaseState();

	virtual void Update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void Init(Agent* agent);
	virtual void Exit(Agent* agent);

	Agent* m_TargetAgent;
};

