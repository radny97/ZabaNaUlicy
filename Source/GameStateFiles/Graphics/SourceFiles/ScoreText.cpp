#include "GameStateFiles/Graphics/HeaderFiles/ScoreText.h"

ScoreText::ScoreText()
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("Fonts\\PressStart2P-Regular.ttf");

	this->setString("Score: 0");
	this->setFont(*font);
	this->setCharacterSize(60);
	this->setPosition(ConfigVariables::scoreTextPosX, ConfigVariables::scoreTextPosY);
}

void ScoreText::SetScoreTextByValue(int value)
{
	this->setString("Score: " + std::to_string(value));
}