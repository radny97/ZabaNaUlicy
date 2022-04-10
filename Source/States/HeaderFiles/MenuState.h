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

	sf::Sprite* background;  /*!< wskaŸnik na grafikê do za³adowania */
	sf::Texture* texture;  /*!< wskaŸnik na teksturê, która zostanie u¿yta jako t³o */

	sf::Text* play;  /*!< wskaŸnik na tekst do wyœwietlenia */
	sf::Text* quit;  /*!< wskaŸnik na tekst do wyœwietlenia */
	sf::Text* wallOfFame;  /*!< wskaŸnik na tekst do wyœwietlenia */
	sf::Text* help;  /*!< wskaŸnik na tekst do wyœwietlenia */

	int selected;
	bool upKey, downKey;
};

