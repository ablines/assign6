#include "player.h"
#include "../../controller/enviroment.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

using namespace PlayerState;
using namespace GameState;

// Add your code to implement the Player class here.
Player::Player(Position initialPosition, int maxHealth, int attack, std::string name)
    : GameObject(initialPosition, maxHealth, attack, name){}

Player::~Player(){}

//todo
MoveState Player::move(Position position){
    if(position.getX() >= GAME_WINDOW_SIZE_X){
        Position tempPos(0, position.getY());
        this->position = tempPos;
        return RIGHTROOM;
    }else if(position.getX() < 0){
        Position tempPos(GAME_WINDOW_SIZE_X - 1, position.getY());
        this->position = tempPos;
        return LEFTROOM;
    }
    this->position = position;
    return MOVE;
    
}




// render
void Player::render() {
    AnsiPrint("PL", green, blue);
}

