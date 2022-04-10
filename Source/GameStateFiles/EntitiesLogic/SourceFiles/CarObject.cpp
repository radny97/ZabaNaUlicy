#include "GameStateFiles/EntitiesLogic/HeaderFiles/CarObject.h"

CarObject::CarObject(int x, int y, bool fromDownToUp)
{
	int randomVelocity = rand() % velocity::mediumVelocity + 3;

	if (fromDownToUp == true)
	{
		this->posX = x - (ConfigVariables::carImageSizeX / 2);
		this->posY = y - (ConfigVariables::carImageSizeY / 2);
	}
	else
	{
		this->posX = x;
		this->posY = y - (ConfigVariables::carImageSizeY);
	}

	this->type = ObjectType::car;
	this->ID = GenerateID();
	this->fromDownToUp = fromDownToUp;
	this->velocity = randomVelocity;

	this->collisional = true;
	UpdateCollisionPoints();
}

void CarObject::UpdateObject()
{
	KeepRoughlyConstantVelocity(velocity::mediumVelocity);
	TemporaryNonCollisionalFlagLogic();

	Move();
}

void CarObject::Move()
{
	if (this->fromDownToUp == false)
	{
		this->posY += (sqrt(this->velocity) * ConfigVariables::GetTangetOfHeightToWidthTrack());
		this->posX -= (sqrt(this->velocity) * 1);
	}
	else
	{
		this->posY -= (sqrt(this->velocity) * ConfigVariables::GetTangetOfHeightToWidthTrack());
		this->posX += (sqrt(this->velocity) * 1);
	}
	UpdateCollisionPoints();
}

void CarObject::KeepRoughlyConstantVelocity(int targetVelocity)
{
	if (this->velocity <= 0)
		this->velocity = 1;

	//if car velocity is more different from target velocity, the bigger is chance to get faster or slower
	this->elapsedTime = this->timer.getElapsedTime();
	if (this->collisional == true && this->elapsedTime.asMilliseconds() > 1000)
	{
		int random = rand() % 30;
		int difference = targetVelocity - this->velocity;
		if (random < pow(difference, 2))
		{
			if (difference < 0)
				this->velocity--;
			else
				this->velocity++;
		}

		this->timer.restart();
	}
}

void CarObject::TemporaryNonCollisionalFlagLogic()
{
	if (this->temporaryNonCollisional == true)
	{
		this->collisional = false;
		this->timerForCollisions.restart();
		this->temporaryNonCollisional = false;
	}

	this->elapsedTimeForCollisions = this->timerForCollisions.getElapsedTime();
	if (this->collisional == false && this->elapsedTimeForCollisions.asMilliseconds() > 50)
	{
		this->collisional = true;
	}
}

bool CarObject::CheckIfCollisionPointIsInBounds(Point point)
{
	//carObject have wider Y bounds because cars cannot touch each other
	if (this->fromDownToUp == true
		&& point.GetcoordinateX() > this->posX
		&& point.GetcoordinateX() < this->posX + ConfigVariables::carImageSizeX
		&& point.GetcoordinateY() > this->posY
		&& point.GetcoordinateY() < this->posY + ConfigVariables::carImageSizeY + (ConfigVariables::carImageSizeY / 2)
		) {
		return true;
	}
	else if (this->fromDownToUp == false
		&& point.GetcoordinateX() > this->posX
		&& point.GetcoordinateX() < this->posX + ConfigVariables::carImageSizeX
		&& point.GetcoordinateY() > this->posY - (ConfigVariables::carImageSizeY / 2)
		&& point.GetcoordinateY() < this->posY + ConfigVariables::carImageSizeY
		) {
		return true;
	}
	return false;
}

void CarObject::UpdateCollisionPoints()
{
	this->frontCollisionPoint = new Point(this->posX + ((3 * ConfigVariables::carImageSizeX) / 4), this->posY);
	this->backCollisionPoint = new Point(this->posX + (ConfigVariables::carImageSizeX / 4), this->posY + ConfigVariables::carImageSizeY);
}