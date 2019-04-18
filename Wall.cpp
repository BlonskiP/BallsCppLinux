//
// Created by wilk on 16.04.19.
//

#include "Wall.h"
#include <algorithm>
using namespace std;
 void Wall::colision(Ball &ball) {
    //change ball directions
    ball.dir[0]*=(-1);
    ball.dir[1]*=(-1);
}
 bool Wall::isColliding(Ball &ball) {
    int det =
            (startX*endY)+(startY*ball.x)+(endX*ball.y)
            -(ball.x*endY)-(ball.y*startX)-(endX*startY);
    if(det!=0) return false;
        if((min(startX,endX) <= ball.x)&&(ball.x<=max(startX,endX))&&
                (min(startY,endY) <= ball.y)&&(ball.y<=max(startY,endY)))
     return true;
     else
     return false;

//http://www.algorytm.org/geometria-obliczeniowa/przynaleznosc-punktu-do-odcinka.html



}

Wall::Wall(int startX, int endX, int startY, int endY) {
    this->startX=startX;
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
        refresh();
}
