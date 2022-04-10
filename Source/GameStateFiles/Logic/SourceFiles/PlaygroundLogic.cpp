#include "GameStateFiles/Logic/HeaderFiles/PlaygroundLogic.h"

PlaygroundLogic::PlaygroundLogic()
{
	this->width = ConfigVariables::screenResolutionX;
	this->height = ConfigVariables::screenResolutionY;

	this->GeneratePlayground(this->width, this->height, Player::GetInstance().GetScore());
}

void PlaygroundLogic::GeneratePlayground(int widthOfWindow, int heightOfWindow, int playerScore)
{
	int numberOfTracks = SetNumberOfTracksBasedOnPlayerPoints(playerScore);
	std::list<int> xCoordinatesInTheMiddleHeightOfWindow = GenerateXCoordinatesInTheMiddleHeightOfWindow(widthOfWindow, numberOfTracks);
	
	int iteratorOfPoint = 0;
	for (auto const& iteratorOfxCoordinate : xCoordinatesInTheMiddleHeightOfWindow)
	{
		// sample -  [side road ; track ; track ; space between tracks ; track ; track ; side road]]
		if (iteratorOfPoint != 0 
			&& iteratorOfPoint != (xCoordinatesInTheMiddleHeightOfWindow.size() - 1)/ 2 
			&& iteratorOfPoint != xCoordinatesInTheMiddleHeightOfWindow.size() - 1)
		{
			if (iteratorOfPoint < (xCoordinatesInTheMiddleHeightOfWindow.size() - 1) / 2)
			{
				AddTrackBasedOnXCoordinate(iteratorOfxCoordinate, heightOfWindow, false);
			}
			else if (iteratorOfPoint > (xCoordinatesInTheMiddleHeightOfWindow.size() - 1)/ 2)
			{
				AddTrackBasedOnXCoordinate(iteratorOfxCoordinate, heightOfWindow, true);
			}
		}

		this->frogStandingPoints.insert(std::make_pair(iteratorOfPoint, Point(iteratorOfxCoordinate, (heightOfWindow / 2))));
		iteratorOfPoint++;
	}
}

void PlaygroundLogic::AddTrackBasedOnXCoordinate(int xCoordinate, int heightOfWindow, bool fromDownToUp)
{
	int xDifferenceFromParameterCoordinate = (heightOfWindow / 2) / ConfigVariables::GetTangetOfHeightToWidthTrack();

	if (fromDownToUp == true)
	{
		Track* newTrack = new Track(Point(xCoordinate - xDifferenceFromParameterCoordinate, heightOfWindow),
			Point(xCoordinate + xDifferenceFromParameterCoordinate, 0),
			fromDownToUp);
		this->tracks.push_back(*newTrack);
	}
	else
	{
		Track* newTrack = new Track(Point(xCoordinate + xDifferenceFromParameterCoordinate, 0),
			Point(xCoordinate - xDifferenceFromParameterCoordinate, heightOfWindow),
			fromDownToUp);
		this->tracks.push_back(*newTrack);
	}
}

int PlaygroundLogic::SetNumberOfTracksBasedOnPlayerPoints(int points)
{
	if (points < 4)
	{
		return 2;
	}
	else if (points < 10)
	{
		return 4;
	}
	else if (points < 18)
	{
		return 6;
	}
	else if (points < 28)
	{
		return 8;
	}
	else
	{
		return 10;
	}
}

std::list<int> PlaygroundLogic::GenerateXCoordinatesInTheMiddleHeightOfWindow(int widthOfWindow, int numberOfTracks)
{
	std::list<int> xCoordinatesOfFrogStandingPoints;
	int widthOfTrack = ConfigVariables::widthOfTrack;
	int widthOfSpaceBetweenTracks = ConfigVariables::widthOfSpaceBetweenTracks;


	int xCoordinateOfMiddleOfPlayground = widthOfWindow / 2;

	//point in the middle of playground, between tracks
	xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground);

	int xCoordinateDifference = (widthOfSpaceBetweenTracks + widthOfTrack) / 2;
	for (int i = 0; i <= (numberOfTracks / 2); i++)
	{

		if (i == (numberOfTracks / 2))
		{
			//points on the side of road
			xCoordinateDifference += (widthOfSpaceBetweenTracks - widthOfTrack) / 2;
			xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground + xCoordinateDifference);
			xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground - xCoordinateDifference);
		}
		else
		{
			//points on tracks
			xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground + xCoordinateDifference);
			xCoordinatesOfFrogStandingPoints.push_back(xCoordinateOfMiddleOfPlayground - xCoordinateDifference);
			
		}	
		xCoordinateDifference += widthOfTrack;
	}

	xCoordinatesOfFrogStandingPoints.sort();
	return xCoordinatesOfFrogStandingPoints;
}