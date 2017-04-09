#include "KeyboardController.h"

KeyboardController::KeyboardController(aie::Input * input)
{
	this->input = input;
}

void KeyboardController::Update(Agent* a_Agent, float deltaTime)
{
	glm::vec2 velocity(0, 0);

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		velocity.y += 1;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		velocity.y -= 1;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		velocity.x += 1;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		velocity.x -= 1;
	}

	a_Agent->Translate(velocity);
}

KeyboardController::~KeyboardController()
{
}
