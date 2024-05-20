#include <iostream>

#include "controller.h"
#include "../gameobjects/room/roomdata.h"
#include "../functions/position/position.h"
#include "../functions/AnsiPrint/AnsiPrint.h"

Controller::Controller() {
    const int defaultRoomIndex = 0;
    RoomData roomData = ROOM_DATA[defaultRoomIndex];

    // initialize class
    rooms[0] = new Room(roomData);
    rooms[1] = new Room(ROOM_DATA[1]);
    rooms[2] = new Room(ROOM_DATA[2]);

    currentRoomIndex = defaultRoomIndex;
    
    player = new Player(rooms[defaultRoomIndex]->getInitialPosition(), 20, 20, "Player001");

    state = PROCESS_MOVEMENT;
}

// Add your code to implement the Controller class here.
Controller::~Controller(){
    delete rooms[0];
    delete player;
}

RunningState
Controller::run(InputState action){
    Position tempPos = player->getPosition();
    switch (action)
    {
    case ACTION_UP:
        tempPos.moveUP();
        break;
    case ACTION_DOWN:
        tempPos.moveDown();
        break;
    case ACTION_LEFT:
        tempPos.moveLeft();
        break;
    case ACTION_RIGHT:
        tempPos.moveRight();
        break;
    
    default:
        break;
    }


    if(rooms[currentRoomIndex]->walkable(tempPos)){
            player->move(tempPos);
    }else if(0 > tempPos.getX() || tempPos.getX() >= GAME_WINDOW_SIZE_X){
            MoveState movestate;
            Position originPos = player->getPosition();
            movestate = player->move(tempPos);
            if(movestate == LEFTROOM){
                if(currentRoomIndex > 0){
                    currentRoomIndex -= 1;
                }else{
                    player->move(originPos);
                }
            }else if(movestate == RIGHTROOM){
                if(currentRoomIndex < 2){
                    currentRoomIndex += 1;
                }else{
                    player->move(originPos);
                }
            }
    }
    
    for(auto enemy : rooms[currentRoomIndex]->getEnemies()) {
        tempPos = enemy->nextPosition();
        while(! rooms[currentRoomIndex]->walkable(tempPos)) {
            tempPos = enemy->nextPosition();
        }
        enemy->setPosition(tempPos);
    }


    render();
    return PLAY;
}

// render
void Controller::render() {
    switch (state) {
    case PROCESS_MOVEMENT:{
        for (int y = 0; y < GAME_WINDOW_SIZE_Y; y++) {
            for (int x = 0; x < GAME_WINDOW_SIZE_X; x++) {
                if(player->getPosition() == Position(x, y)) {
                    player->render();
                    continue;
                }
                bool flag = false;
                for(auto enemy : rooms[currentRoomIndex]->getEnemies()) {
                    if(enemy->getPosition() == Position(x, y)) {
                        enemy->render();
                        flag = true;
                        continue;
                    }
                }
                if(flag) continue;
                rooms[currentRoomIndex]->render(Position(x, y));
            }
            AnsiPrint("\n", nochange, nochange);
        }
        break;
    }
    
    default:
        break;
    }
    output();
}

void
Controller::roomChange(int roomIndex){
    currentRoomIndex = roomIndex;
    return;
}