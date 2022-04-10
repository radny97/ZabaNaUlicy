#pragma once
#include <SFML/Graphics.hpp>
#include "States/State.h"
#include <States/HeaderFiles/StateMachine.h>
#include <GameStateFiles/Logic/HeaderFiles/GameLogic.h>
#include <GameStateFiles/Graphics/HeaderFiles/GameGraphics.h>
#include "States/HeaderFiles/GameOverState.h"

class GameState : public State
{
public:
	GameState(StateMachine* coreState);

	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	StateMachine* stateMachine;
	GameLogic* gameLogic;
	GameGraphics* gameGraphics;
};
