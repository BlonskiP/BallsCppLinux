//
// Created by wilk on 16.04.19.
//

#include "Wall.h"
 void Wall::colision(Ball &ball) {
    //change ball directions
    ball.dir[0]*=(-1);
    ball.dir[1]*=(-1);
}
 bool Wall::isColliding(Ball &ball) {

     if(ball.x>=startX && ball.x <=endX){
         if(ball.y>=startY && ball.y<=endX){
             return true;}}
     return false;

}

Wall::Wall(int startX, int endX, int startY, int endY) {
    this->startY=startX;
    this->endX=endX;
    this->startY=startY;
    this->endY=endY;
}

void Wall::drawItem() {
    const char wallSymbol='=';
    for(int xPos=startX, yPos=startY;xPos<endX || yPos<endY;   )
    {
        move(xPos,yPos);
        addch(wallSymbol);
        if(xPos<endX){xPos++;};
        if(yPos<endY){yPos++;};

    }
        move(0,0);

}
