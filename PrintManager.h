//
// Created by wilk on 24.03.19.
//

#ifndef THREADBALLS_PRINTMANAGER_H
#define THREADBALLS_PRINTMANAGER_H

#include <ncurses.h>
#include "Map.h"
#include "Ball.h"

class PrintManager {

public:
    PrintManager();
    Map *map;
    Ball *balls;
    void printMap();
    void drawBalls();

};


#endif //THREADBALLS_PRINTMANAGER_H
