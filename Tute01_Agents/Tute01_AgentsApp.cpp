#include "Tute01_AgentsApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "KeyboardController.h"
#include "Seek.h"
#include "PatrolState.h"

Tute01_AgentsApp::Tute01_AgentsApp() {

}

Tute01_AgentsApp::~Tute01_AgentsApp() {

}

bool Tute01_AgentsApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_Player = new Agent("./textures/player.gif", glm::vec2(100, 100));
	m_Player->AddBehaviour(new KeyboardController(aie::Input::getInstance()));
	m_Player->setMaxSpeed(200.0f);

	m_Enemy = new Agent("./textures/eye.gif", glm::vec2(500, 700));
	m_Enemy->InitSM();
	m_Enemy->setTarget(m_Player);
	m_Enemy->SetState(new PatrolState());
	//m_Enemy->AddBehaviour(new Seek(m_Player));
	m_Enemy->setMaxSpeed(120.0f);


	return true;
}

void Tute01_AgentsApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Tute01_AgentsApp::update(float deltaTime) {

	m_Player->Update(deltaTime);
	m_Enemy->Update(deltaTime);

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Tute01_AgentsApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_Player->Draw(m_2dRenderer);
	m_Enemy->Draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}