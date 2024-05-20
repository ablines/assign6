#include "gameobject.h"



// Add your code to implement the GameObject class here.
GameObject::GameObject(Position initialPosition, int maxHealth, int attack, std::string name){
    position = initialPosition;
    this->maxHealth = maxHealth;
    this->attack = attack;
    this->name = name;
}

GameObject::~GameObject(){}

Position GameObject::getPosition(){
    return position;
}

void GameObject::setPosition(Position position){
    this->position = position;
}

int GameObject::getHealth(){
    return health;
}

int GameObject::getMaxHealth(){
    return maxHealth;
}

int GameObject::getAttack(){
    return attack;
}

void GameObject::hurt(int damage){
    health -= damage;
}

std::string GameObject::getName(){
    return name;
}
