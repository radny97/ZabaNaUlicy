#include "GameStateFiles/EntitiesLogic/HeaderFiles/FrogObject.h"

FrogObject::FrogObject(double x, double y)
{
	this->posX = x - (ConfigVariables::frogImageSizeX / 2);
	this->posY = y - (ConfigVariables::frogImageSizeY / 2);

	this->type = ObjectType::frog;
	this->ID = GenerateID();
	this->collisional = true;
	this->velocity = 0;
	this->stateOfFrog = StateOfFrog::wait;

	this->waitAfterStartFlag = true;
	this->timer.restart();
}

void FrogObject::UpdateObject()
{
	this->elapsedTime = this->timer.getElapsedTime();

	//StatesOfFrog:
	//	normalStanding,
	//	beforeOrAfterJump,
	//	jumpForwards,
	//	jumpBackwards,
	//	death,
	//	wait


	if (this->waitAfterStartFlag == true)
	{
		ChangeStateOfFrogFromWaitToNormalAfterGivenTime(2000);
	}


	
	if (this->activateJumpFlag == true)
	{
		ChangeStateOfFrogFromPreparingToJumpToJumpAfterGivenTime(500);
		ChangeStateOfFrogFromStandingToPreparingToJump();
	}
	if (this->activateJumpFlag == false)
	{
		ChangeStateOfFrogFromAfterJumpToNormalAfterGivenTime(100);
	}

	

	if (this->activateDeathFlag == true)
	{
		ChangeStateOfFrogFromNormalToDeath();
		ChangeStateOfFrogFromDeathToNormalAfterGivenTime(2000);
	}
	

	ChangeStateOfFrogFromJumpToAfterJumpIfFrogReachDestination();

	Move();
}

void FrogObject::SetPositionOnXAxis(double x)
{
	this->posX = x - (ConfigVariables::frogImageSizeX / 2);
}

bool FrogObject::CheckIfCollisionPointIsInBounds(Point point)
{
	if (point.GetcoordinateX() > this->posX
		&& point.GetcoordinateX() < this->posX + ConfigVariables::frogImageSizeX
		&& point.GetcoordinateY() > this->posY + (ConfigVariables::frogImageSizeY / 6)
		&& point.GetcoordinateY() < this->posY + ((5 * ConfigVariables::frogImageSizeY) / 6)
		) {
		return true;
	}
	return false;
}

void FrogObject::Move()
{
	this->posX -= this->velocity;
}

void FrogObject::JumpToDestination(double destination)
{
	this->destinationOfJump = destination;
	this->activateJumpFlag = true;
}

void FrogObject::DeathAndMoveToStart(double XcoordinateOfStart)
{
	this->destinationOfJump = XcoordinateOfStart;
	this->activateDeathFlag = true;
	this->activateJumpFlag = false;
	
}

void FrogObject::DeleteScoreInCurrentLevel(int scoreToDelete)
{
	if (Player::GetInstance().GetLives() != 0)
	{
		Player::GetInstance().SetScore(Player::GetInstance().GetScore() - scoreToDelete);
	}
}

void FrogObject::ChangeStateOfFrogFromWaitToNormalAfterGivenTime(int givenTimeMilisec)
{
	if (this->elapsedTime.asMilliseconds() > givenTimeMilisec && this->stateOfFrog == StateOfFrog::wait)
	{
		this->timer.restart();
		this->waitAfterStartFlag = false;
		this->stateOfFrog = StateOfFrog::normalStanding;
	}
}

void FrogObject::ChangeStateOfFrogFromStandingToPreparingToJump()
{
	if (this->stateOfFrog == StateOfFrog::normalStanding)
	{
		this->timer.restart();
		this->stateOfFrog = StateOfFrog::beforeOrAfterJump;
	}
}

void FrogObject::ChangeStateOfFrogFromPreparingToJumpToJumpAfterGivenTime(int givenTimeMilisec)
{
	if (this->elapsedTime.asMilliseconds() > givenTimeMilisec && this->stateOfFrog == StateOfFrog::beforeOrAfterJump)
	{
		if (this->destinationOfJump < this->posX)
		{
			this->velocity = velocity::fastVelocity;
			this->stateOfFrog = StateOfFrog::jumpForwards;
			this->collisional = false;
		}
		else if (this->destinationOfJump > this->posX)
		{
			this->velocity = -velocity::fastVelocity;
			this->stateOfFrog = StateOfFrog::jumpBackwards;
			this->collisional = false;
		}
	}
}

void FrogObject::ChangeStateOfFrogFromJumpToAfterJumpIfFrogReachDestination()
{
	if ((this->posX < this->destinationOfJump && this->stateOfFrog == StateOfFrog::jumpForwards) || (this->posX > this->destinationOfJump && this->stateOfFrog == StateOfFrog::jumpBackwards))
	{
		if (this->stateOfFrog == StateOfFrog::jumpForwards)
		{
			Player::GetInstance().SetScore(Player::GetInstance().GetScore() + 1);
		}
		if (this->stateOfFrog == StateOfFrog::jumpBackwards)
		{
			Player::GetInstance().SetScore(Player::GetInstance().GetScore() - 1);
		}

		SetPositionOnXAxis(this->destinationOfJump);
		this->velocity = 0;
		this->collisional = true;
		this->stateOfFrog = StateOfFrog::beforeOrAfterJump;
		this->activateJumpFlag = false;
		this->timer.restart();
	}
}

void FrogObject::ChangeStateOfFrogFromAfterJumpToNormalAfterGivenTime(int givenTimeMilisec)
{
	if (this->elapsedTime.asMilliseconds() > 100 && this->stateOfFrog == StateOfFrog::beforeOrAfterJump)
	{
		this->stateOfFrog = StateOfFrog::normalStanding;
	}
}

void FrogObject::ChangeStateOfFrogFromNormalToDeath()
{
	if (this->stateOfFrog == StateOfFrog::normalStanding)
	{
		this->collisional = false;
		this->stateOfFrog = StateOfFrog::death;
		this->timer.restart();
	}
}

void FrogObject::ChangeStateOfFrogFromDeathToNormalAfterGivenTime(int givenTimeMilisec)
{
	if (this->elapsedTime.asMilliseconds() > 2000 && this->stateOfFrog == StateOfFrog::death)
	{
		SetPositionOnXAxis(this->destinationOfJump);
		this->activateDeathFlag = false;
		this->stateOfFrog = StateOfFrog::normalStanding;
		this->collisional = true;
		if (Player::GetInstance().GetLives() != 0)
		{
			Player::GetInstance().SetLives(Player::GetInstance().GetLives() - 1);
		}

	}
}