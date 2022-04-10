#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <GameStateFiles/EntitiesLogic/HeaderFiles/Object.h>
#include <GameStateFiles/Logic/HeaderFiles/PlaygroundLogic.h>
#include <GameStateFiles/EntitiesLogic/HeaderFiles/FrogObject.h>
#include <GameStateFiles/EntitiesLogic/HeaderFiles/CarObject.h>

class GameLogic
{
public:
	GameLogic();
	void UpdateLogic();
	std::unordered_map<int, Object*> GetAllLogicObjects();
	PlaygroundLogic* GetPlaygroundLogic();
	void InputControl();
	SubStateOfGame GetSubStateOfGame();
	void SetSubStateOfGame(SubStateOfGame subState);
	

private:
	void UpdateObjects();
	void CheckCollisions();
	void GenerateCarsOnTracks();
	void AddCarToDeleteListIfItOutOfPlayground(Object* car);
	bool IsTimeToGenerateCarOnTrack(Track* track);
	void GenerateNewCar(Track track);
	void DeleteUnnecessaryObjects();
	void ChangeVelocityOfCarsAfterCollision(Object* firstObject, Object* secondObject);
	
	CollisionType CheckCollisionBetweenObjects(Object* firstObject, Object* secondObject);
	

	Object* frogObject;
	PlaygroundLogic* playground;

	std::unordered_map<int, Object*> allLogicObjects;
	std::unordered_map<int, Object*> logicObjectsToDelete;

	sf::Clock timer;
	sf::Time elapsedTime;

	bool stopGenerating;
	
	int positionWhereFrogIsStanding;

	int scoreEarnedInThisRound, scoreEarnedInPreviousRound;

	SubStateOfGame subState;

	bool leftKeyPressed, rightKeyPressed, escapeKeyPressed, enterKeyPressed;
};
