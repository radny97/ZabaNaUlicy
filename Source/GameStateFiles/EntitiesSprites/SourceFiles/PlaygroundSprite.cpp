#include "GameStateFiles/EntitiesSprites/HeaderFiles/PlaygroundSprite.h"

PlaygroundSprite::PlaygroundSprite()
{
	this->texture = new sf::Texture();
	this->SetTextureFromFile("Graphics/grassFullHD.png");
}