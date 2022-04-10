#include "GameStateFiles/EntitiesLogic/HeaderFiles/Object.h"

int Object::GenerateID()
{
	uint32_t id = reinterpret_cast<uint32_t>(this);
	return abs((int)id);
}