//
// Created by wilk on 16.04.19.
//

#ifndef THREADBALLS_WALL_H
#define THREADBALLS_WALL_H


#include "CollidingItem.h"

class Wall : public CollidingItem {

public:
    int startX;
    int endX;
    int startY;
    int endY;
    bool isColliding(Ball ball) override;
    void colision(Ball ball) override;
};


#endif //THREADBALLS_WALL_H
