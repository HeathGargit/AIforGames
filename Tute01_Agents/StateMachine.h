#pragma once

#include "Agent.h"
#include "State.h"

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(Agent* agent, float deltaTime);
	void ChangeState(Agent* agent, State* newState);
	State* getCurrentState();
	State* getPrevState();

	State* m_CurrentState = nullptr;
	State* m_PrevState = nullptr;
};

