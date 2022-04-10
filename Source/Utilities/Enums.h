#pragma once

enum velocity
{
	verySlowVelocity = 1,
	slowVelocity = 3,
	mediumVelocity = 5,
	fastVelocity = 7,
	veryFastVelocity = 9
};

enum class ObjectType
{
	frog,
	car
};

enum class CollisionType
{
	noCollision,
	frogCarCollision,
	carCarColision
};

enum class SubStateOfGame
{
	game,
	pause,
	gameOver,
	nextLevel,
	levelEnding
};

enum class StateOfFrog
{
	normalStanding,
	beforeOrAfterJump,
	jumpForwards,
	jumpBackwards,
	death,
	wait
};