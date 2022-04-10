#pragma once
#include <list>
#include <GameStateFiles/EntitiesSprites/HeaderFiles/TrackSprite.h>
#include <GameStateFiles/EntitiesSprites/HeaderFiles/PlaygroundSprite.h>
#include <Utilities/HeaderFiles/Point.h>
#include <Utilities/HeaderFiles/ConfigVariables.h>

class PlaygroundGraphics
{
public:
	PlaygroundGraphics();
	void SetTrackSprites(Point positionOfTrack);

	std::list<TrackSprite> trackSprites;
	PlaygroundSprite* playgroundSprite;
};

