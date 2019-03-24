//
// Created by wilk on 24.03.19.
//

#include "Ball.h"
using namespace std;
Ball::Ball(int x, int y, Map *map) {
    this->x=x;
    this->y=y;
    this->map=map;
    movThread=thread(&Ball::move,this);
    dir.insert(dir.begin(),3);
    dir.insert(dir.end(),1);

}

void Ball::move() {
   while(true) {
       usleep(10*10000);
       x+=dir[0];
       y+=dir[1];
       if(x<=1 || x>=map->sizeX-2)
           dir[0]*=(-1);
       if(y<=1 || y>=map->sizeY-2)
           dir[1]*=(-1);


   }
}
