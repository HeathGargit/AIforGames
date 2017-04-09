#pragma once
#include "IBehaviour.h"

class Seek : public IBehaviour
{
public:
	Seek(Agent* a_Agent);
	~Seek();

	void virtual Update(Agent* a_Agent, float deltaTime);

protected:
	glm::vec2 *m_targetPos;
	Agent* m_targetAgent;
};

