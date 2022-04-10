#include "Utilities/HeaderFiles/ConfigVariables.h"

int ConfigVariables::playerLives = 3;

int ConfigVariables::screenResolutionX = 1920;
int ConfigVariables::screenResolutionY = 1080;

int ConfigVariables::frogImageSizeX = 75;
int ConfigVariables::frogImageSizeY = 75;

int ConfigVariables::carImageSizeX = 85;
int ConfigVariables::carImageSizeY = 105;

int ConfigVariables::firstLivesIconPosX = 40;
int ConfigVariables::firstLivesIconPosY = 120;
int ConfigVariables::widthOfSpaceBetweenLivesIcon = 90;

int ConfigVariables::scoreTextPosX = 40;
int ConfigVariables::scoreTextPosY = 40;

int ConfigVariables::trackGradeDegrees = 30;
double ConfigVariables::GetTangetOfHeightToWidthTrack()
{
    double radians = (trackGradeDegrees * 3.14) / 180;
    double tangens = tan(radians);
    return 1 / tangens;
}

int ConfigVariables::widthOfTrack = 130;
int ConfigVariables::widthOfSpaceBetweenTracks = 80;

int ConfigVariables::numberOfRowsInWallOfFame = 5;