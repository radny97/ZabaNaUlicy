#include "GameStateFiles/EntitiesSprites/HeaderFiles/FrogObjectSprite.h"

FrogObjectSprite::FrogObjectSprite()
{
	this->texture = new sf::Texture();
	this->SetTextureFromFile("Graphics/frogNormalStanding.png");
}

void FrogObjectSprite::SetTextureVersionDependingOnStateOfFrog(StateOfFrog state)
{

	if ((int)state != this->versionOfTexture)
	{
		switch (state)
		{
		case StateOfFrog::normalStanding:
			this->texture->loadFromFile("Graphics/frogNormalStanding.png");
			this->setTexture(*this->texture);
			break;
		case StateOfFrog::wait:
			this->texture->loadFromFile("Graphics/frogNormalStanding.png");
			this->setTexture(*this->texture);
			break;
		case StateOfFrog::jumpForwards:
			this->texture->loadFromFile("Graphics/frogJumpForwards.png");
			this->setTexture(*this->texture);
			break;
		case StateOfFrog::jumpBackwards:
			this->texture->loadFromFile("Graphics/frogJumpBackwards.png");
			this->setTexture(*this->texture);
			break;
		case StateOfFrog::beforeOrAfterJump:
			this->texture->loadFromFile("Graphics/frogBeforeAfterJump.png");
			this->setTexture(*this->texture);
			break;
		case StateOfFrog::death:
			this->texture->loadFromFile("Graphics/frogDeath.png");
			this->setTexture(*this->texture);
			break;
		default:
			break;
		}
	}
	
	this->versionOfTexture = (int)state;
}