#pragma once
#include <string>

class PlayerRecord
{
public:
    PlayerRecord(std::string _name, int _points);
    int GetPoints();
    std::string GetName();
private:
    std::string name;
    int points;
};