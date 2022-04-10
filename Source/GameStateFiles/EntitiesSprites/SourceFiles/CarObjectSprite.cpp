#include "GameStateFiles/EntitiesSprites/HeaderFiles/CarObjectSprite.h"

CarObjectSprite::CarObjectSprite(bool fromDownToUp)
{
	int versionOfCarTexture = rand() % 5;
	if (fromDownToUp == true)
	{
		this->texture = new sf::Texture();
		this->SetTextureFromFile("Graphics/carFromBottom" + std::to_string(versionOfCarTexture) + ".png");
	}
	else
	{
		this->texture = new sf::Texture();
		this->SetTextureFromFile("Graphics/carFromTop" + std::to_string(versionOfCarTexture) + ".png");
	}
}