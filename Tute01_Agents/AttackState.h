#pragma once
#include "State.h"

class AttackState : public State
{
public:
	AttackState();
	~AttackState();

	virtual void Update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void Init(Agent* agent);
	virtual void Exit(Agent* agent);

protected:
	float idleTime;
};

