#include "GameStateFiles/Logic/HeaderFiles/Track.h"

Track::Track(Point begining, Point end, bool directionToUp)
{
	this->beginingOfTrack = begining;
	this->endOfTrack = end;
	this->fromDownToUp = directionToUp;
	timer.restart();
	this->timeAfterWhichCarIsGeneratedInMiliSec = rand() % 1500;
}