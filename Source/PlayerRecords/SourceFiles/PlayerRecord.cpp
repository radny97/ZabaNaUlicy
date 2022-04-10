#include "PlayerRecords/HeaderFiles/PlayerRecord.h"

PlayerRecord::PlayerRecord(std::string _name, int _points)
{
    this->name = _name;
    this->points = _points;
}

int PlayerRecord::GetPoints()
{
    return points;
}

std::string PlayerRecord::GetName()
{
    return name;
}