#pragma once

#include "Agent.h"

class State
{
public:
	State();
	~State();

	virtual void Update(Agent* agent, StateMachine* sm, float deltaTime) = 0;
	virtual void Init(Agent* agent) = 0;
	virtual void Exit(Agent* agent) = 0;
};

