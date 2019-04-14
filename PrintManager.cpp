//
// Created by wilk on 24.03.19.
//


#include "PrintManager.h"
bool PrintManager::run=true;
std::condition_variable PrintManager::cv_run;
PrintManager::PrintManager(int amount) {
    initscr();
    noecho();
    //set cursor na 0
    map=new Map(20,50);
    int randX;
    int randY;
    escapeThread=std::thread(&PrintManager::escapeListen,this);
    for(int i=0;i<amount;i++)
    {
        randX=rand() % 17 +2;
        randY=rand() % 47 +2;
        //randX=0;
        //randY=0;

    balls.push_back(new Ball(randX,randY,map,i));

    }




    print(100);
}

void PrintManager::printMap() {
    move(0,0);
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
        while(PrintManager::run)
        {
            //dodac sleepa co 40ms
        printMap();
        drawBalls();
        //move(0,0);
        refresh();

        }

        escapeThread.join();


        for(int i=0;i<balls.size();i++) {
            balls[i]->movThread.join();
        }
        erase();
        refresh();
        printw("Threads joined. \n Press any key");
        getch();
        endwin();
    }

void PrintManager::escapeListen() {
    while(run)
    {
        if(getch()=='q')
        {run=false;
         cv_run.notify_all();
        }
    }
}



