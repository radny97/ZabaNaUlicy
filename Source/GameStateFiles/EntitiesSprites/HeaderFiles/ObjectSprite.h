#pragma once
#include <SFML/Graphics.hpp>
#include "Utilities/Enums.h"

class ObjectSprite : public sf::Sprite
{
public:
	int posX;
	int posY;
	int ID;
	sf::Texture* texture;

	int versionOfTexture;

	ObjectSprite() {};
	void SetTextureFromFile(std::string filename);
	virtual void SetTextureVersionDependingOnStateOfFrog(StateOfFrog state) {};
	
};