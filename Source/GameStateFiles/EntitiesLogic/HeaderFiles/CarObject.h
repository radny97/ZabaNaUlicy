#pragma once
#include "GameStateFiles/EntitiesLogic/HeaderFiles/Object.h"

class CarObject : public Object
{
public:
	CarObject(int x, int y, bool fromDownToUp);

	bool CheckIfCollisionPointIsInBounds(Point point) override;
	void UpdateObject() override;
	void Move() override;

	bool fromDownToUp;

	Point* frontCollisionPoint; //middle of front bumper of car
	Point* backCollisionPoint; //middle of back bumper of car

private:
	void TemporaryNonCollisionalFlagLogic();
	void KeepRoughlyConstantVelocity(int velocity);
	void UpdateCollisionPoints();

	sf::Clock timerForCollisions;
	sf::Time elapsedTimeForCollisions;
};