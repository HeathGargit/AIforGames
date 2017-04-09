#pragma once
#include "IBehaviour.h"
#include "Input.h"

class KeyboardController : public IBehaviour
{
public:
	KeyboardController(aie::Input* input);

	void virtual Update(Agent* a_Agent, float deltaTime);

	~KeyboardController();

private:
	aie::Input* input;
};

