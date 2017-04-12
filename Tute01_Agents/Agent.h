#pragma once

#include <vector>
#include <glm\ext.hpp>
#include <glm\vec2.hpp>
#include <glm\fwd.hpp>

//forward decs
namespace aie {
	class Texture;
	class Renderer2D;
}
class IBehaviour;
class StateMachine;
class State;

class Agent
{
public:
	//constructors
	Agent(); //does nothing
	Agent(float x, float y); // new agent at x,y but no graphic
	Agent(const char* a_szFilename, glm::vec2& position); //sets graphic and position
	~Agent(); //deconstructor

	//engine functions
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* a_SpriteBatch);

	//state machine functions
	void InitSM(); //TODO: move this to the constructor
	void SetState(State* newState); //set a new state

	//behaviour functions. can be used instead of a state machine.
	void AddBehaviour(IBehaviour* behaviour);

	//gamey stuff
	Agent* getTarget();
	void setTarget(Agent* targetAgent);

	//movement related
	void Translate(glm::vec2 a_velocity); //expects a normalised vector to use in movment calcs in update.
	glm::vec2 getPosition(); //returns the pos of this Agent
	void setMaxSpeed(float a_newSpeed); //sets max speed of the agent.

protected:
	//AI members
	std::vector<IBehaviour*> m_behaviours;
	StateMachine* m_sm = nullptr;
	
	//gamey stuff
	Agent* m_targetAgent = nullptr;

	//movement stuff
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	float m_maxSpeed;

	//sprite for drawin' on the screen
	aie::Texture* m_texture;
};

