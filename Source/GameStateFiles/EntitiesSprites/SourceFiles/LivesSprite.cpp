#include "GameStateFiles/EntitiesSprites/HeaderFiles/LivesSprite.h"

LivesSprite::LivesSprite()
{
	this->texture = new sf::Texture();
	this->SetTextureFromFile("Graphics/heart.png");
}