#include "StateMachine.h"


StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
}

void StateMachine::Update(Agent* agent, float deltaTime)
{
	if (m_CurrentState != nullptr)
	{
		m_CurrentState->Update(agent, this, deltaTime);
	}
}

void StateMachine::ChangeState(Agent* agent, State* newState)
{
	if (m_CurrentState == nullptr && newState != nullptr)
	{
		newState->Init(agent);
		m_CurrentState = newState;
		return;
	}
	else if (newState != nullptr)
	{
		m_CurrentState->Exit(agent);
		newState->Init(agent);
		m_PrevState = m_CurrentState;
		m_CurrentState = newState;
	}
}

State* StateMachine::getCurrentState()
{
	return m_CurrentState;
}

State* StateMachine::getPrevState()
{
	return m_PrevState;
}
