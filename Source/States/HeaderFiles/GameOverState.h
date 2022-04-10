#pragma once
#include <SFML/Graphics.hpp>
#include "States/State.h"
#include <States/HeaderFiles/StateMachine.h>
#include "States/HeaderFiles/MenuState.h"

class GameOverState : public State
{
public:
	GameOverState(StateMachine* coreState);

	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	StateMachine* stateMachine;

	sf::Sprite* background;  /*!< wska�nik na grafik� do za�adowania */
	sf::Texture* texture;  /*!< wska�nik na tekstur�, kt�ra zostanie u�yta jako t�o */
};

