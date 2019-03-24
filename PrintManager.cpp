//
// Created by wilk on 24.03.19.
//

#include "PrintManager.h"

PrintManager::PrintManager() {
    initscr();
    noecho();
    map=new Map(20,50);
    balls = new Ball[3]{
        Ball(3,4),
        Ball(5,4),
        Ball(4,5)
    };

    while(true) {
        printMap();
        balls[0].x+=1;
        getch();
    }
    balls[0].x=7;
    printMap();
    getch();
    endwin(); //4
}

void PrintManager::printMap() {
    for(int x=0;x<map->sizeX;x++) {
        for (int y = 0; y < map->sizeY; y++) {
            char mapTile = map->charMap[x][y];
            addch(mapTile);
        }
        printw("\n");
    }
    drawBalls();
    move(0,0);
}

void PrintManager::drawBalls() {
    for(int i=0;i<3;i++)
    {
        int x=balls[i].x;
        int y=balls[i].y;
        move(x,y);
        addch(balls[i].symbol);
    }

}


