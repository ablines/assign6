#include "slime.h"
#include <stdlib.h>

#include "../../../functions/AnsiPrint/AnsiPrint.h"

Slime::Slime(Position initialPosition): Enemy(initialPosition, 5, 1, "Slime") {
}

// add your code to implement the Slime class here
Slime::~Slime(){}


Position
Slime::nextPosition(){
    int temp = rand() % 4;
    Position tempPos = position;
    switch(temp){
        case 0:
            tempPos.moveUP();
            break;
        case 1:
            tempPos.moveDown();
            break;
        case 2:
            tempPos.moveLeft();
            break;
        case 3:
            tempPos.moveRight();
            break;
    }
    return tempPos;
}





// render function

void Slime::render() {
    AnsiPrint("==", yellow, green);
}
