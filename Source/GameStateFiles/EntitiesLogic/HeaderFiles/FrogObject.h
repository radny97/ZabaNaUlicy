#pragma once
#include "GameStateFiles/EntitiesLogic/HeaderFiles/Object.h"

class FrogObject : public Object
{
public:
	FrogObject(double x, double y);

	bool CheckIfCollisionPointIsInBounds(Point point) override;
	void UpdateObject() override;
	void Move() override;
	void JumpToDestination(double destination) override;
	void DeathAndMoveToStart(double XcoordinateOfStart) override;
	void DeleteScoreInCurrentLevel(int scoreToDelete) override;

	void SetPositionOnXAxis(double x);

	StateOfFrog stateOfFrog;
private:

	bool activateJumpFlag;
	bool activateDeathFlag;
	double destinationOfJump;
	bool waitAfterStartFlag;

	void ChangeStateOfFrogFromWaitToNormalAfterGivenTime(int givenTimeMilisec);
	void ChangeStateOfFrogFromStandingToPreparingToJump();
	void ChangeStateOfFrogFromPreparingToJumpToJumpAfterGivenTime(int givenTimeMilisec);
	void ChangeStateOfFrogFromJumpToAfterJumpIfFrogReachDestination();
	void ChangeStateOfFrogFromAfterJumpToNormalAfterGivenTime(int givenTimeMilisec);
	void ChangeStateOfFrogFromNormalToDeath();
	void ChangeStateOfFrogFromDeathToNormalAfterGivenTime(int givenTimeMilisec);
};