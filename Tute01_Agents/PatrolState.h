#pragma once
#include "State.h"
#include <vector>

class PatrolState : public State
{
public:
	PatrolState();
	~PatrolState();

	virtual void Update(Agent* agent, StateMachine* sm, float deltaTime);
	virtual void Init(Agent* agent);
	virtual void Exit(Agent* agent);

protected:
	std::vector<glm::vec2> m_PatrolNodes;
	int m_CurrentNode = 0;
};

