#pragma once
#include <SFML/Graphics.hpp>
#include "States/State.h"
#include <States/HeaderFiles/StateMachine.h>
#include "States/HeaderFiles/GameState.h"
#include "States/HeaderFiles/WallOfFameState.h"

class MenuState : public State
{
public:
	MenuState(StateMachine* coreState);

	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	StateMachine* stateMachine;

	sf::Sprite* background;  /*!< wska�nik na grafik� do za�adowania */
	sf::Texture* texture;  /*!< wska�nik na tekstur�, kt�ra zostanie u�yta jako t�o */

	sf::Text* play;  /*!< wska�nik na tekst do wy�wietlenia */
	sf::Text* quit;  /*!< wska�nik na tekst do wy�wietlenia */
	sf::Text* wallOfFame;  /*!< wska�nik na tekst do wy�wietlenia */
	sf::Text* help;  /*!< wska�nik na tekst do wy�wietlenia */

	int selected;
	bool upKey, downKey;
};

