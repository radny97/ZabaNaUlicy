#pragma once
#include <cmath>
#include <string>

static class ConfigVariables
{
public:
	static int playerLives;

	static int screenResolutionX;
	static int screenResolutionY;

	static int frogImageSizeX;
	static int frogImageSizeY;

	static int carImageSizeX;
	static int carImageSizeY;

	static int firstLivesIconPosX;
	static int firstLivesIconPosY;
	static int widthOfSpaceBetweenLivesIcon;

	static int scoreTextPosX;
	static int scoreTextPosY;

	static int trackGradeDegrees;
	static double GetTangetOfHeightToWidthTrack();

	static int widthOfTrack;
	static int widthOfSpaceBetweenTracks;

	static int numberOfRowsInWallOfFame;
};

