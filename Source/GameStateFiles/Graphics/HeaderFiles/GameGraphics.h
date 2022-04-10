#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <list>
#include <GameStateFiles/Logic/HeaderFiles/PlaygroundLogic.h>
#include <GameStateFiles/EntitiesLogic/HeaderFiles/Object.h>
#include <GameStateFiles/EntitiesLogic/HeaderFiles/FrogObject.h>
#include <GameStateFiles/EntitiesLogic/HeaderFiles/CarObject.h>
#include <GameStateFiles/EntitiesSprites/HeaderFiles/LivesSprite.h>
#include <GameStateFiles/EntitiesSprites/HeaderFiles/CarObjectSprite.h>
#include <GameStateFiles/EntitiesSprites/HeaderFiles/FrogObjectSprite.h>
#include <GameStateFiles/Graphics/HeaderFiles/ScoreText.h>
#include <GameStateFiles/Graphics/HeaderFiles/PlaygroundGraphics.h>
#include <GameStateFiles/Graphics/HeaderFiles/PauseScreenGraphics.h>

class GameGraphics
{
public:
	GameGraphics();
	void UpdateSpritesFromLogicObjects(std::unordered_map<int, Object*> allModels);
	void UpdateHud();
	void Render(sf::RenderWindow* window);
	void RenderPauseMenu(sf::RenderWindow* window);
	void SetPlaygroundGraphicsFromPlaygroundLogicObject(PlaygroundLogic* playgroundLogic);
private:
	std::unordered_map<int, ObjectSprite*> allObjectSprites;
	std::unordered_map<int, ObjectSprite*> spritesToDelete;
	std::list<ObjectSprite*> livesIconSprites;
	ScoreText* scoreText;

	PlaygroundGraphics* playgroundGraphics;
	PauseScreenGraphics* pauseScreenGraphics;
	
	void MapLogicObjectsToObjectSprites(std::unordered_map<int, Object*> allModels);
	void MapOneLogicObjectToSprite(Object* source, ObjectSprite* target);
	void DeleteSpritesOfObjectsThatNoLongerExist();
	ObjectSprite* ChooseTypeOfNewObjectStripe(Object* source);
};
