#include "position.h"
#include "../../controller/enviroment.h"

// Add your code to implement the Position class here.
Position::Position(){
    positionX = 0;
    positionY = 0;
}

Position::Position(int initialPositionX, int initialPositionY){
    positionX = initialPositionX;
    positionY = initialPositionY;
}

Position::~Position(){}

int Position::getX(){
    return positionX;
}

int Position::getY(){
    return positionY;
}

bool Position::operator==(const Position &other) const{
    if(other.positionX == positionX && other.positionY == positionY)
        return true;
    return false;
}

Position& Position::operator=(const Position &other){
    positionX = other.positionX;
    positionY = other.positionY;
    return *this;
}