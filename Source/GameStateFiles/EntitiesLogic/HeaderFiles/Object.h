#pragma once
#include "Utilities/HeaderFiles/ConfigVariables.h"
#include "Utilities/HeaderFiles/Point.h"
#include "Utilities/Enums.h"
#include <GameStateFiles/Player.h>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>

class Object
{
public:
	Object() {};

	double posX;
	double posY;
	ObjectType type;
	int ID;

	virtual void UpdateObject() {};
	virtual void JumpToDestination(double destination) {};
	virtual void DeathAndMoveToStart(double XcoordinateOfStart) {};
	virtual void Move() {};
	virtual bool CheckIfCollisionPointIsInBounds(Point point) { return true; };
	virtual void DeleteScoreInCurrentLevel(int scoreToDelete) {};

	sf::Clock timer;
	sf::Time elapsedTime;

	bool collisional;
	bool temporaryNonCollisional;
	int velocity;

protected:
	int GenerateID();
};