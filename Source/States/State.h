#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
	virtual void Initialize(sf::RenderWindow* window) {}
	virtual void Update(sf::RenderWindow* window) {}
	virtual void Render(sf::RenderWindow* window) {}
	virtual void Destroy(sf::RenderWindow* window) {}
};