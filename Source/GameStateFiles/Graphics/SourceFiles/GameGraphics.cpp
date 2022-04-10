#include "GameStateFiles/Graphics/HeaderFiles/GameGraphics.h"

GameGraphics::GameGraphics()
{
	for (int i = 0; i < ConfigVariables::playerLives; i++)
	{
		ObjectSprite* live = new LivesSprite();
		live->posY = ConfigVariables::firstLivesIconPosY;
		live->posX = ConfigVariables::firstLivesIconPosX + (i * ConfigVariables::widthOfSpaceBetweenLivesIcon);
		live->setPosition(live->posX, live->posY);
		this->livesIconSprites.push_back(live);
	}
	this->scoreText = new ScoreText();
	this->pauseScreenGraphics = new PauseScreenGraphics();
}

void GameGraphics::SetPlaygroundGraphicsFromPlaygroundLogicObject(PlaygroundLogic* playgroundLogic)
{
	this->playgroundGraphics = new PlaygroundGraphics();

	for (auto const& track : playgroundLogic->tracks)
	{
		if (track.fromDownToUp == true)
		{
			this->playgroundGraphics->SetTrackSprites(track.endOfTrack);
		}
		else
		{
			this->playgroundGraphics->SetTrackSprites(track.beginingOfTrack);
		}
	}
}

void GameGraphics::UpdateSpritesFromLogicObjects(std::unordered_map<int, Object*> allModels)
{
	this->spritesToDelete = this->allObjectSprites;

	MapLogicObjectsToObjectSprites(allModels);

	if (!this->spritesToDelete.empty())
	{
		DeleteSpritesOfObjectsThatNoLongerExist();
	}
}

void GameGraphics::UpdateHud()
{
	this->scoreText->SetScoreTextByValue(Player::GetInstance().GetScore());
	
	if (Player::GetInstance().GetLives() < this->livesIconSprites.size())
	{
		this->livesIconSprites.pop_back();
	}
}

void GameGraphics::MapLogicObjectsToObjectSprites(std::unordered_map<int, Object*> allLogicObjects)
{
	for (auto& iteratorObjects : allLogicObjects)
	{
		bool newObjectSpriteNeedsToBeAdded = true;

		for (auto& iteratorObjectSprites : this->allObjectSprites)
		{
			if (iteratorObjects.second->ID == iteratorObjectSprites.second->ID)
			{
				MapOneLogicObjectToSprite(iteratorObjects.second, iteratorObjectSprites.second);
				newObjectSpriteNeedsToBeAdded = false;

				this->spritesToDelete.erase(iteratorObjects.second->ID);
			}
		}

		if (newObjectSpriteNeedsToBeAdded == true)
		{
			ObjectSprite* objectSprite = ChooseTypeOfNewObjectStripe(iteratorObjects.second);

			MapOneLogicObjectToSprite(iteratorObjects.second, objectSprite);
			this->allObjectSprites.insert(std::make_pair(objectSprite->ID, objectSprite));
		}
	}
}

void GameGraphics::MapOneLogicObjectToSprite(Object* source, ObjectSprite* target)
{
	if (source->type == ObjectType::frog)
	{
		FrogObject* frogSource;
		frogSource = dynamic_cast<FrogObject*>(source);

		target->posX = frogSource->posX;
		target->posY = frogSource->posY;
		target->ID = frogSource->ID;
		target->SetTextureVersionDependingOnStateOfFrog(frogSource->stateOfFrog);
	}
	else if (source->type == ObjectType::car)
	{
		target->posX = source->posX;
		target->posY = source->posY;
		target->ID = source->ID;
	}

	target->setPosition(target->posX, target->posY);
}

ObjectSprite* GameGraphics::ChooseTypeOfNewObjectStripe(Object* source)
{
	if (source->type == ObjectType::frog)
	{
		return new FrogObjectSprite();
	}
	else if (source->type == ObjectType::car)
	{
		CarObject* sourceCar;
		sourceCar = dynamic_cast<CarObject*>(source);

		return new CarObjectSprite(sourceCar->fromDownToUp);
	}
	else return new ObjectSprite();
}

void GameGraphics::DeleteSpritesOfObjectsThatNoLongerExist()
{
	for (auto& iterator : this->spritesToDelete)
	{
		ObjectSprite *toDelete = this->allObjectSprites.at(iterator.second->ID);
		this->allObjectSprites.erase(iterator.second->ID);
		delete toDelete;
	}
	this->spritesToDelete.clear();
}

void GameGraphics::Render(sf::RenderWindow* window)
{
	window->draw(*this->playgroundGraphics->playgroundSprite);
	window->draw(*this->scoreText);
	
	for (auto& iteratorLivesSprites : this->livesIconSprites)
	{
		window->draw(*iteratorLivesSprites);
	}

	for (auto& iteratorTrackSprites : this->playgroundGraphics->trackSprites)
	{
		window->draw(iteratorTrackSprites);
	}

	for (auto& iteratorObjectSprites : this->allObjectSprites)
	{
		window->draw(*iteratorObjectSprites.second);
	}
}

void GameGraphics::RenderPauseMenu(sf::RenderWindow* window)
{
	window->draw(*this->pauseScreenGraphics->pauseScreenSprite);
	window->draw(*this->pauseScreenGraphics->mainText);
	window->draw(*this->pauseScreenGraphics->descriptionText);
}