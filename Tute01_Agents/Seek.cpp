#include "Seek.h"

Seek::Seek(Agent * a_Agent)
{
	this->m_targetAgent = a_Agent;
}

Seek::~Seek()
{
}

void Seek::Update(Agent * a_Agent, float deltaTime)
{
	glm::vec2 velocity = m_targetAgent->getPosition() - a_Agent->getPosition();
	if (glm::length(velocity) > 100.0f)
	{
		velocity = glm::normalize(velocity);
	}
	else
	{
		velocity = glm::vec2(0,0);
	}
	a_Agent->Translate(velocity);
}
