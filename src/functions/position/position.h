#ifndef POSITION_H
#define POSITION_H

class Position {
private:
    int positionX;
    int positionY;
public:
    Position(int initialPositionX, int initialPositionY);
    Position();
    ~Position();

    int getX();
    int getY();
    
    // add functions what you need

    bool operator==(const Position &other) const;

    Position& operator=(const Position &other);

    void moveUP(){
        positionY -= 1;
    }
    void moveDown(){
        positionY += 1;
    }
    void moveLeft(){
        positionX -= 1;
    }
    void moveRight(){
        positionX += 1;
    }


};

#endif