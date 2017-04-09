#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Agent.h"
#include "IBehaviour.h"
#include "Seek.h"
#include <vector>

class Tute01_AgentsApp : public aie::Application {
public:

	Tute01_AgentsApp();
	virtual ~Tute01_AgentsApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	Agent* m_Player;
	Agent* m_Enemy;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};