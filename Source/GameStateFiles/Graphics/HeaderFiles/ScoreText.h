#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <Utilities/HeaderFiles/ConfigVariables.h>

class ScoreText : public sf::Text
{
public:
	ScoreText();
	void SetScoreTextByValue(int value);
};

