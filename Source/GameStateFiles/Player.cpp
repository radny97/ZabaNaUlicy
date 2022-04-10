#include "GameStateFiles/Player.h"

Player& Player::GetInstance()
{
    static Player instance;
    return instance;
}

int Player::GetLives() 
{ 
    return this->lives;
};
void Player::SetLives(int lives)
{ 
    this->lives = lives; 
};

int Player::GetScore() 
{ 
    return this->score;
};
void Player::SetScore(int score) 
{ 
    this->score = score; 
};

std::string Player::GetName()
{ 
    return this->name; 
};
void Player::SetName(std::string name)
{ 
    this->name = name; 
};

void Player::ResetPlayer() {
    this->lives = ConfigVariables::playerLives;
    this->score = 0;
    this->name = "";
}


Player::Player()
{
    this->lives = ConfigVariables::playerLives;
    this->score = 0;
}