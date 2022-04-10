#include <SFML/Graphics.hpp>
#include <Utilities/HeaderFiles/ConfigVariables.h>
#include <States/HeaderFiles/StateMachine.h>
#include "States/HeaderFiles/MenuState.h"

int main()
{
	srand((unsigned)time(0));

	StateMachine stateMachine;
	sf::RenderWindow window(sf::VideoMode(ConfigVariables::screenResolutionX, ConfigVariables::screenResolutionY), "Zaba na ulicy", sf::Style::Default);

	stateMachine.SetWindow(&window);
	stateMachine.SetState(new MenuState(&stateMachine));

	sf::Clock timer;
	sf::Time elapsedTime;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		elapsedTime = timer.getElapsedTime();

		if (elapsedTime.asMicroseconds() > 16666)
		{
			window.clear();

			stateMachine.Update();
			stateMachine.Render();

			window.display();
			timer.restart();
		}
	}

	return 0;
}