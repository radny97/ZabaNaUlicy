#include "States/HeaderFiles/GameState.h"

GameState::GameState(StateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void GameState::Initialize(sf::RenderWindow* window)
{
	this->gameLogic = new GameLogic();
	this->gameGraphics = new GameGraphics();
	this->gameGraphics->SetPlaygroundGraphicsFromPlaygroundLogicObject(this->gameLogic->GetPlaygroundLogic());
}

void GameState::Update(sf::RenderWindow* window)
{
	switch (this->gameLogic->GetSubStateOfGame())
	{
	case SubStateOfGame::game:
		this->gameLogic->UpdateLogic();
		this->gameLogic->InputControl();
		this->gameGraphics->UpdateHud();
		this->gameGraphics->UpdateSpritesFromLogicObjects(this->gameLogic->GetAllLogicObjects());
		this->gameGraphics->Render(window);
		break;
	case SubStateOfGame::levelEnding:
		this->gameLogic->UpdateLogic();
		this->gameGraphics->UpdateHud();
		this->gameGraphics->UpdateSpritesFromLogicObjects(this->gameLogic->GetAllLogicObjects());
		this->gameGraphics->Render(window);
		break;
	case SubStateOfGame::pause:
		this->gameLogic->InputControl();
		this->gameGraphics->UpdateSpritesFromLogicObjects(this->gameLogic->GetAllLogicObjects());
		this->gameGraphics->Render(window);
		this->gameGraphics->RenderPauseMenu(window);
		break;
	case SubStateOfGame::nextLevel:
		this->gameLogic = new GameLogic();
		this->gameGraphics = new GameGraphics();
		this->gameGraphics->SetPlaygroundGraphicsFromPlaygroundLogicObject(this->gameLogic->GetPlaygroundLogic());
		break;
	case SubStateOfGame::gameOver:
		this->stateMachine->SetState(new GameOverState(this->stateMachine));
		Player::GetInstance().ResetPlayer();
		break;
	default:
		break;
	}

}

void GameState::Destroy(sf::RenderWindow* window)
{
	delete this->gameLogic;
	delete this->gameGraphics;
}