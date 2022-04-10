#pragma once
#include <SFML/Graphics.hpp>
#include "States/State.h"
#include <States/HeaderFiles/StateMachine.h>
#include <PlayerRecords/HeaderFiles/PlayerRecordsManager.h>
#include <Utilities/HeaderFiles/ConfigVariables.h>
#include "States/HeaderFiles/MenuState.h"

class WallOfFameState : public State
{
public:
	WallOfFameState(StateMachine* coreState);

	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	StateMachine* stateMachine;
	
	PlayerRecordsManager* playerRecordsManager;
	sf::Text* recordRowsArray;  /*!< wska�nik na tekst do wy�wietlenia */


	sf::Sprite* background;  /*!< wska�nik na grafik� do za�adowania */
	sf::Texture* texture;  /*!< wska�nik na tekstur�, kt�ra zostanie u�yta jako t�o */
};
