#pragma once
#include <GameStateFiles/EntitiesSprites/HeaderFiles/PauseScreenSprite.h>
#include <Utilities/HeaderFiles/ConfigVariables.h>

class PauseScreenGraphics
{
public:
	PauseScreenGraphics();

	PauseScreenSprite* pauseScreenSprite;
	sf::Text* mainText;
	sf::Text* descriptionText;
};

