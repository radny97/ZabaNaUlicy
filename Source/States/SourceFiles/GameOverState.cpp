#include "States/HeaderFiles/GameOverState.h"

GameOverState::GameOverState(StateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void GameOverState::Initialize(sf::RenderWindow* window)
{
	sf::Font* font = new sf::Font();
	font = new sf::Font();
	font->loadFromFile("Fonts\\PressStart2P-Regular.ttf");

	this->background = new sf::Sprite();
	this->texture = new sf::Texture();
	this->texture->loadFromFile("Graphics/gameOverScreen.png");
	this->background->setTexture(*this->texture);
}

void GameOverState::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		this->stateMachine->SetState(new MenuState(this->stateMachine));
	}
}

void GameOverState::Render(sf::RenderWindow* window)
{
	window->draw(*this->background);
}

void GameOverState::Destroy(sf::RenderWindow* window)
{
	delete this->background;
	delete this->texture;
}

