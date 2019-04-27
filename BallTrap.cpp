//
// Created by wilk on 27.04.19.
//

#include "BallTrap.h"

BallTrap::BallTrap(int xLeftUpCorner, int yLeftUpCorner, int wallSize, int capacity) {
    this->xLeftUpCorner=xLeftUpCorner;
    this->yLeftUpCorner=yLeftUpCorner;
    this->wallSize=wallSize;
    this->trapCapacity=capacity;
}

void BallTrap::drawItem() {
    const char wallSymbol='@';
    for(int x=xLeftUpCorner, y=yLeftUpCorner;x<(xLeftUpCorner+wallSize);x++)
    {
        move(x,y);
        addch(wallSymbol);
    }
    for(int x=xLeftUpCorner, y=yLeftUpCorner;y<(yLeftUpCorner+wallSize);y++)
    {
        move(x,y);
        addch(wallSymbol);
    }
    for(int x=xLeftUpCorner+wallSize, y=yLeftUpCorner; y<(yLeftUpCorner+wallSize);y++)
    {
        move(x,y);
        addch(wallSymbol);
    }
    for(int x=xLeftUpCorner, y=yLeftUpCorner+wallSize; x<=xLeftUpCorner+wallSize;x++)
    {
        move(x,y);
        addch(wallSymbol);
    }
    refresh();
}

void BallTrap::colision(Ball &ball) {
    ball.moveForward(ball.dir[0],ball.dir[1]);
    std::unique_lock<std::mutex> lck;
    if(ballQueue.size()<=trapCapacity) {
        ballQueue.push_back(&ball);
        ball.cvBallSleep.wait(lck,[this,&ball]{return queueContains(&ball);}); // wait as long as ball is in queue
    }
    else{
         ballQueue.pop_back();}
    lck.unlock();
}

bool BallTrap::isColliding(Ball &ball) {
    if(ball.x>= xLeftUpCorner && ball.x<=xLeftUpCorner+wallSize)
        if(ball.y<=yLeftUpCorner && ball.y<=yLeftUpCorner+wallSize)
            return true;
    return false;
}

bool BallTrap::queueContains(Ball *ball) {

    for(auto ballInQueue : ballQueue)
    {
        if(ball==ballInQueue)
        {
            return true;
        }
    }
    return false;

}
