//
// Created by wilk on 24.03.19.
//


#include "PrintManager.h"

PrintManager::PrintManager() {
    initscr();
    noecho();
    map=new Map(20,50);
    balls = new Ball[9]{
        Ball(1,1, map),
        Ball(13,23, map),
        Ball(14,7, map),
        Ball(7,5, map),
        Ball(17,9, map),
        Ball(7,10, map),
        Ball(5,1, map),
        Ball(2,3, map),
        Ball(2,34, map)
    };

    print(100);
}

void PrintManager::printMap() {
    for(int x=0;x<map->sizeX;x++) {
        for (int y = 0; y < map->sizeY; y++) {
            char mapTile = map->charMap[x][y];
            addch(mapTile);
        }
        printw("\n");
    }
    move(0,0);
}

void PrintManager::drawBalls() {
    for(int i=0;i<9;i++)
    {
        int x=balls[i].x;
        int y=balls[i].y;
        move(x,y);
        addch(balls[i].symbol);
    }

}
    void PrintManager::print(int fresh) {
        while(true)
        {
        usleep(fresh*1000);
        printMap();
        drawBalls();
        move(0,0);
        refresh();
        }
    }



