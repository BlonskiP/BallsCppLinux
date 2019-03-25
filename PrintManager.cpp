//
// Created by wilk on 24.03.19.
//


#include "PrintManager.h"

PrintManager::PrintManager(int amount) {
    initscr();
    noecho();
    map=new Map(20,50);
    int randX;
    int randY;
    for(int i=0;i<amount;i++)
    {
        randX=rand() % 17 +2;
        randY=rand() % 47 +2;
    balls.push_back(new Ball(randX,randY,map,i));

    }



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
    for(int i=0;i<balls.size();i++)
    {
        int x=balls[i]->x;
        int y=balls[i]->y;
        move(x,y);
        addch(balls[i]->symbol);
    }

}
    void PrintManager::print(int fresh) {
        while(true)
        {
        printMap();
        drawBalls();
        move(0,0);
        refresh();
        }
    }



