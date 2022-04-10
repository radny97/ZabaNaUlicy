#include "GameStateFiles/EntitiesSprites/HeaderFiles/TrackSprite.h"

TrackSprite::TrackSprite()
{
	this->texture = new sf::Texture();
	this->SetTextureFromFile("Graphics/road.png");
}