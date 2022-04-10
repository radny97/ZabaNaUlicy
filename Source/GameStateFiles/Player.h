#pragma once
#include "GameStateFiles/Player.h"
#include <Utilities/HeaderFiles/ConfigVariables.h>
#include <string>

class Player
{
public:
    static Player& GetInstance();

    int GetLives();
    void SetLives(int lives);

    int GetScore();
    void SetScore(int score);

    std::string GetName();
    void SetName(std::string name);

    void ResetPlayer();

    Player(Player const&) = delete;
    void operator=(Player const&) = delete;
private:
    Player();

    int lives;
    int score;
    std::string name;
};