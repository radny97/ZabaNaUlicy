#pragma once
#include <Utilities/HeaderFiles/ConfigVariables.h>
#include <GameStateFiles/Player.h>
#include <GameStateFiles/Logic/HeaderFiles/Track.h>
#include <map>
#include <list>
#include <iostream>

class PlaygroundLogic
{
public:
	PlaygroundLogic();
	void GeneratePlayground(int widthOfWindow, int heightOfWindow, int numberOfTracks);

	std::list<Track> tracks;
	std::map<int, Point> frogStandingPoints;
	int height;
	int width;
private:
	int SetNumberOfTracksBasedOnPlayerPoints(int points);
	std::list<int> GenerateXCoordinatesInTheMiddleHeightOfWindow(int widthOfWindow, int numberOfTracks);
	void AddTrackBasedOnXCoordinate(int xCoordinate, int heightOfWindow, bool fromDownToUp);
};