//
// Created by wilk on 16.04.19.
//

#include "Wall.h"
 void Wall::colision(Ball ball) {
    //change ball directions
    ball.dir[0]*=(-1);
    ball.dir[1]*=(-1);
}
 bool Wall::isColliding(Ball ball) {

     if(ball.x>=startX && ball.x <=endX){
         if(ball.y>=startY && ball.y<=endX){
             return true;}}
     return false;

}