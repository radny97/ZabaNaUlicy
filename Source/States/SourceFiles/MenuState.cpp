#include "States/HeaderFiles/MenuState.h"

MenuState::MenuState(StateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void MenuState::Initialize(sf::RenderWindow* window)
{
	this->selected = 0;

	sf::Font* font = new sf::Font();
	font = new sf::Font();
	font->loadFromFile("Fonts\\PressStart2P-Regular.ttf");

	this->play = new sf::Text("PLAY", *font, 50U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2 - 100);

	this->wallOfFame = new sf::Text("Wall of Fame", *font, 50U);
	this->wallOfFame->setOrigin(this->wallOfFame->getGlobalBounds().width / 2, this->wallOfFame->getGlobalBounds().height / 2);
	this->wallOfFame->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->quit = new sf::Text("QUIT", *font, 50U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 100);

	this->help = new sf::Text("Press ENTER to select", *font, 15U);
	this->help->setOrigin(this->help->getGlobalBounds().width / 2, this->help->getGlobalBounds().height / 2);
	this->help->setPosition(window->getSize().x / 2, 750);


	this->background = new sf::Sprite();
	this->texture = new sf::Texture();
	this->texture->loadFromFile("Graphics/menuScreen.png");
	this->background->setTexture(*this->texture);
}

void MenuState::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
	{
		this->selected -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
	{
		this->selected += 1;
	}

	if (this->selected > 2)
	{
		this->selected = 0;
	}
	if (this->selected < 0)
	{
		this->selected = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		switch (this->selected)
		{
		case 0:
			this->stateMachine->SetState(new GameState(this->stateMachine));
			break;
		case 1:
			this->stateMachine->SetState(new WallOfFameState(this->stateMachine));
			break;
		case 2:
			window->close();
			break;
		}
	}

	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void MenuState::Render(sf::RenderWindow* window)
{
	this->play->setOutlineThickness(0);
	this->wallOfFame->setOutlineThickness(0);
	this->quit->setOutlineThickness(0);

	switch (this->selected)
	{
	case 0:
		this->play->setOutlineThickness(15);
		break;
	case 1:
		this->wallOfFame->setOutlineThickness(15);
		break;
	case 2:
		this->quit->setOutlineThickness(15);
		break;
	}

	window->draw(*this->background);
	window->draw(*this->play);
	window->draw(*this->quit);
	window->draw(*this->wallOfFame);
	window->draw(*this->help);
}

void MenuState::Destroy(sf::RenderWindow* window)
{
	delete this->play;
	delete this->wallOfFame;
	delete this->quit;
	delete this->help;
	delete this->background;
	delete this->texture;
}