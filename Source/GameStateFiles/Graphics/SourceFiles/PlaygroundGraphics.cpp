#include "GameStateFiles/Graphics/HeaderFiles/PlaygroundGraphics.h"

PlaygroundGraphics::PlaygroundGraphics()
{
	this->playgroundSprite = new PlaygroundSprite();
}

void PlaygroundGraphics::SetTrackSprites(Point positionOfTrack)
{
	TrackSprite* track = new TrackSprite();
	track->setPosition(positionOfTrack.GetcoordinateX(), positionOfTrack.GetcoordinateY() - (ConfigVariables::GetTangetOfHeightToWidthTrack()*(ConfigVariables::widthOfTrack / 2)));
	track->setRotation(ConfigVariables::trackGradeDegrees);
	this->trackSprites.push_back(*track);
}