#include "GameStateFiles/Logic/HeaderFiles/GameLogic.h"

GameLogic::GameLogic()
{
	this->subState = SubStateOfGame::game;
	
	this->scoreEarnedInThisRound = 0;
	this->scoreEarnedInPreviousRound = Player::GetInstance().GetScore();

	this->playground = new PlaygroundLogic();

	this->positionWhereFrogIsStanding = this->playground->frogStandingPoints.size() - 1;

	this->frogObject = new FrogObject(
		this->playground->frogStandingPoints.at(this->positionWhereFrogIsStanding).GetcoordinateX(),
		this->playground->frogStandingPoints.at(this->positionWhereFrogIsStanding).GetcoordinateY()
	);

	this->allLogicObjects.insert(std::make_pair(this->frogObject->ID, this->frogObject));
}

void GameLogic::UpdateLogic()
{
	this->scoreEarnedInThisRound = Player::GetInstance().GetScore() - this->scoreEarnedInPreviousRound;

	if (Player::GetInstance().GetLives() == 0 || this->frogObject->posX < this->playground->frogStandingPoints.at(0).GetcoordinateX())
	{
		this->subState = SubStateOfGame::levelEnding;
	}

	if (this->subState == SubStateOfGame::levelEnding && this->allLogicObjects.size() == 1)
	{
		if (Player::GetInstance().GetLives() == 0)
		{
			this->subState = SubStateOfGame::gameOver;
		}
		if (this->positionWhereFrogIsStanding == 0)
		{
			this->subState = SubStateOfGame::nextLevel;
		}
	}

	UpdateObjects();
	CheckCollisions();
	GenerateCarsOnTracks();
	
	DeleteUnnecessaryObjects();
}

std::unordered_map<int, Object*> GameLogic::GetAllLogicObjects()
{
	return this->allLogicObjects;
}

PlaygroundLogic* GameLogic::GetPlaygroundLogic()
{
	return this->playground;
}

CollisionType GameLogic::CheckCollisionBetweenObjects(Object* firstObject, Object* secondObject)
{
	if (firstObject->type == ObjectType::car && firstObject->collisional && !firstObject->temporaryNonCollisional)
	{
		CarObject* car;
		car = dynamic_cast<CarObject*>(firstObject);

		if (secondObject->collisional
			&& (secondObject->CheckIfCollisionPointIsInBounds(*car->frontCollisionPoint)
				|| secondObject->CheckIfCollisionPointIsInBounds(*car->backCollisionPoint)))
		{
			if (secondObject->type == ObjectType::frog)
			{
				return CollisionType::frogCarCollision;
			}
			if (secondObject->type == ObjectType::car && !secondObject->temporaryNonCollisional)
			{
				return CollisionType::carCarColision;
			}
		}
	}
	return CollisionType::noCollision;
}

void GameLogic::InputControl()
{
	FrogObject* frog;
	frog = dynamic_cast<FrogObject*>(this->frogObject);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && frog->stateOfFrog == StateOfFrog::normalStanding && this->subState == SubStateOfGame::game && !this->leftKeyPressed)
	{
		if (this->positionWhereFrogIsStanding > 0)
		{
			this->positionWhereFrogIsStanding--;
			this->frogObject->JumpToDestination(this->playground->frogStandingPoints.at(this->positionWhereFrogIsStanding).GetcoordinateX());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && frog->stateOfFrog == StateOfFrog::normalStanding && this->subState == SubStateOfGame::game && !this->rightKeyPressed)
	{
		if (this->positionWhereFrogIsStanding < this->playground->frogStandingPoints.size() - 1)
		{
			this->positionWhereFrogIsStanding++;
			this->frogObject->JumpToDestination(this->playground->frogStandingPoints.at(this->positionWhereFrogIsStanding).GetcoordinateX());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && this->subState == SubStateOfGame::game && !this->escapeKeyPressed)
	{
		this->subState = SubStateOfGame::pause;
		this->escapeKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && this->subState == SubStateOfGame::pause && !this->enterKeyPressed)
	{
		this->subState = SubStateOfGame::game;
		this->enterKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);

		//preserve from generating cars in all roads after going from pause to game
		for (auto& track : this->playground->tracks)
		{
			if (track.timer.getElapsedTime().asMilliseconds() > 3000)
			{
				track.timeAfterWhichCarIsGeneratedInMiliSec = rand() % 1500 + 300;
				track.timer.restart();
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && this->subState == SubStateOfGame::pause && !this->escapeKeyPressed)
	{
		this->subState = SubStateOfGame::gameOver;
		this->escapeKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
	}

	this->enterKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
	this->escapeKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
	this->leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

void GameLogic::GenerateCarsOnTracks()
{
	if (this->subState == SubStateOfGame::game)
	{
		for (auto& track : this->playground->tracks)
		{
			if (IsTimeToGenerateCarOnTrack(&track))
			{
				GenerateNewCar(track);
			}
		}
	}
}

void GameLogic::CheckCollisions()
{
	for (auto& firstLoopObject : this->allLogicObjects)
	{
		for (auto& secondLoopObject : this->allLogicObjects)
		{

			if (firstLoopObject.second != secondLoopObject.second)
			{
				if (CheckCollisionBetweenObjects(firstLoopObject.second, secondLoopObject.second) == CollisionType::carCarColision)
				{
					ChangeVelocityOfCarsAfterCollision(firstLoopObject.second, secondLoopObject.second);
				}
				if (CheckCollisionBetweenObjects(firstLoopObject.second, secondLoopObject.second) == CollisionType::frogCarCollision)
				{
					this->positionWhereFrogIsStanding = this->playground->frogStandingPoints.size() - 1;
					this->frogObject->DeathAndMoveToStart(this->playground->frogStandingPoints.at(this->positionWhereFrogIsStanding).GetcoordinateX());
					this->frogObject->DeleteScoreInCurrentLevel(this->scoreEarnedInThisRound);
				}
			}

		}

	}
}

void GameLogic::UpdateObjects()
{
	for (auto& iterator : this->allLogicObjects)
	{
		AddCarToDeleteListIfItOutOfPlayground(iterator.second);

		iterator.second->UpdateObject();

		if (this->subState == SubStateOfGame::levelEnding && iterator.second->type == ObjectType::car)
		{
			iterator.second->velocity++;
		}
	}
}

bool GameLogic::IsTimeToGenerateCarOnTrack(Track* track)
{
	track->elapsedTime = track->timer.getElapsedTime();

	if (track->elapsedTime.asMilliseconds() > track->timeAfterWhichCarIsGeneratedInMiliSec)
	{
		track->timer.restart();
		track->timeAfterWhichCarIsGeneratedInMiliSec = rand() % 5000 + 800;
		return true;
	}
	else
		return false;
}

void GameLogic::GenerateNewCar(Track track)
{
	Object* carObject = new CarObject(track.beginingOfTrack.GetcoordinateX(), track.beginingOfTrack.GetcoordinateY(), track.fromDownToUp);
	this->allLogicObjects.insert(std::make_pair(carObject->ID, carObject));
}

void GameLogic::AddCarToDeleteListIfItOutOfPlayground(Object* car)
{
	if (!(car->posY > -(2 * ConfigVariables::carImageSizeY) && car->posY < ConfigVariables::screenResolutionY + (2 * ConfigVariables::carImageSizeY)))
	{
		this->logicObjectsToDelete.insert(std::make_pair(car->ID, car));
	}

}

void GameLogic::DeleteUnnecessaryObjects()
{
	if (!this->logicObjectsToDelete.empty())
	{
		for (auto& iterator : this->logicObjectsToDelete)
		{
			Object* toDelete = this->allLogicObjects.at(iterator.second->ID);
			this->allLogicObjects.erase(iterator.second->ID);
			delete toDelete;
		}
		this->logicObjectsToDelete.clear();
	}
}


SubStateOfGame GameLogic::GetSubStateOfGame()
{
	return this->subState;
}

void GameLogic::SetSubStateOfGame(SubStateOfGame subState)
{
	this->subState = subState;
}

void GameLogic::ChangeVelocityOfCarsAfterCollision(Object* firstObject, Object* secondObject)
{
	if (firstObject->velocity > secondObject->velocity)
	{
		firstObject->velocity = secondObject->velocity - 1;
		if (secondObject->velocity < 3)
			secondObject->velocity++;
	}
	else
	{
		secondObject->velocity = firstObject->velocity - 1;
		if (firstObject->velocity < 3)
			firstObject->velocity++;
	}

	//temporaryNonCollisional flag for preventing collision loop
	//cars after collision are temporary non collisional to allow them to accelerate or decelerate
	firstObject->temporaryNonCollisional = true;
	secondObject->temporaryNonCollisional = true;
}