#pragma once
#include "GameStateFiles/EntitiesSprites/HeaderFiles/ObjectSprite.h"

class FrogObjectSprite : public ObjectSprite
{
public:
	FrogObjectSprite();
	void SetTextureVersionDependingOnStateOfFrog(StateOfFrog state) override;
};