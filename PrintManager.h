//
// Created by wilk on 24.03.19.
//

#ifndef THREADBALLS_PRINTMANAGER_H
#define THREADBALLS_PRINTMANAGER_H

#include <ncurses.h>
#include "Map.h"
#include "Ball.h"
#include <unistd.h>
#include <vector>

class PrintManager {

public:
    PrintManager(int amount);
    Map *map;
    std::vector<Ball*> balls;
    int nBalls;
    void printMap();
    void drawBalls();
    void print(int fresh);
};


#endif //THREADBALLS_PRINTMANAGER_H
