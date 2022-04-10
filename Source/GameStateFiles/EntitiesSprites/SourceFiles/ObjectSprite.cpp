#include "GameStateFiles/EntitiesSprites/HeaderFiles/ObjectSprite.h"

void ObjectSprite::SetTextureFromFile(std::string filename)
{
	this->texture->loadFromFile(filename);
	this->setTexture(*this->texture);
}