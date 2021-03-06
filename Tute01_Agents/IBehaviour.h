#pragma once

#include "Agent.h"

class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual void Update(Agent *pAgent, float deltaTime) = 0;
};

