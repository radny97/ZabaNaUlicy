#include "States/HeaderFiles/WallOfFameState.h"

WallOfFameState::WallOfFameState(StateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void WallOfFameState::Initialize(sf::RenderWindow* window)
{
	sf::Font* font = new sf::Font();
	font = new sf::Font();
	font->loadFromFile("Fonts\\PressStart2P-Regular.ttf");

	this->background = new sf::Sprite();
	this->texture = new sf::Texture();
	this->texture->loadFromFile("Graphics/wallOfFameScreen.png");
	this->background->setTexture(*this->texture);

	this->playerRecordsManager = new PlayerRecordsManager();

	this->recordRowsArray = new sf::Text[this->playerRecordsManager->GetAllPlayerRecords().size()];

	int counter = 0;
	for (auto &playerRecord : this->playerRecordsManager->GetAllPlayerRecords()) {
		this->recordRowsArray[counter] = sf::Text(std::to_string(playerRecord.GetPoints()) + " - " + playerRecord.GetName(), *font, 50U);
		this->recordRowsArray[counter].setOrigin(0, 0);
		this->recordRowsArray[counter].setPosition(150, 300 + ((600 * counter) / ConfigVariables::numberOfRowsInWallOfFame));
		counter += 1;
	}
}

void WallOfFameState::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->stateMachine->SetState(new MenuState(this->stateMachine));
	}
}

void WallOfFameState::Render(sf::RenderWindow* window)
{
	window->draw(*this->background);
	for (int i = 0; i < ConfigVariables::numberOfRowsInWallOfFame; i++)
	{
		window->draw(this->recordRowsArray[i]);
	}
}

void WallOfFameState::Destroy(sf::RenderWindow* window)
{
	delete this->background;
	delete this->texture;
	delete[] this->recordRowsArray;
}
