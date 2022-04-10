#pragma once
#include <SFML/Graphics.hpp>
#include "States/State.h"

class StateMachine
{
public:
	StateMachine();
	void SetWindow(sf::RenderWindow* window);
	void SetState(State* state);
	void Update();
	void Render();

	~StateMachine();
private:
	sf::RenderWindow* window;
	State* state;
};