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
// ball is you (the thread)
// lock mutex. check if queue is full.
// If queue isn't full add yourself to queue, unlock mutex.
// And wait until you're poped
// If queue is full. Pop somebody from queue

void BallTrap::colision(Ball &ball) {
    std::unique_lock<std::mutex> lck;
    
    ball.isTraped=true;
    int x,y;
    if(ball.dir[0]>0)x=1;
    else x=-1;
    if(ball.dir[1]>0)y=1;
    else y=-1;
    ball.moveForward(x,y);

    //////////////////

    ballQueue.push_back(&ball);
    if(ballQueue.size()<trapCapacity)
    {
        cvBallSleep.wait(lck,[this,&ball]{return !queueContains(&ball);});
    } else
    {
        ballQueue.pop_back();
        ball.isTraped= false;
        while(isColliding(ball))
        ball.moveForward(-x,-y);

    }
}
bool BallTrap::isColliding(Ball &ball) {
    if(!ball.isTraped)
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
