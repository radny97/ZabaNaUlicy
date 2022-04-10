#include "States/HeaderFiles/StateMachine.h"

StateMachine::StateMachine()
{
	this->state = NULL;
}
void StateMachine::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}
void StateMachine::SetState(State* state)
{
	if (this->state != NULL)
	{
		this->state->Destroy(this->window);
	}

	this->state = state;
	if (this->state != NULL)
	{
		this->state->Initialize(this->window);
	}
}
void StateMachine::Update()
{
	if (this->state != NULL)
	{
		this->state->Update(this->window);
	}
}
void StateMachine::Render()
{
	if (this->state != NULL)
	{
		this->state->Render(this->window);
	}
}
StateMachine::~StateMachine()
{
	if (this->state != NULL)
	{
		this->state->Destroy(this->window);
	}
}