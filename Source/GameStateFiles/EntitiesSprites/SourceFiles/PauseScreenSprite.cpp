#include "GameStateFiles/EntitiesSprites/HeaderFiles/PauseScreenSprite.h"

PauseScreenSprite::PauseScreenSprite()
{
	this->texture = new sf::Texture();
	this->SetTextureFromFile("Graphics/pauseScreen.png");
}