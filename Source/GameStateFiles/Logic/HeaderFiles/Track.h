#pragma once
#include <SFML/Graphics.hpp>
#include <Utilities/HeaderFiles/Point.h>

class Track
{
public:
	Track(Point begining, Point end, bool directionToUp);

	Point beginingOfTrack;
	Point endOfTrack;
	bool fromDownToUp;

	int timeAfterWhichCarIsGeneratedInMiliSec;
	
	sf::Clock timer;
	sf::Time elapsedTime;
};

