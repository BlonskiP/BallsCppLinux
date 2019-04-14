//
// Created by wilk on 24.03.19.
//

#include <iostream>
#include "Ball.h"
#include "PrintManager.h"

using namespace std;
Ball::Ball(int x, int y, Map *map, int sleepTime) {
    this->x=x;
    this->y=y;
    this->map=map;
    movThread=thread(&Ball::move,this);
    int xdir=0;
    int ydir=0;
    while(xdir==0 && ydir==0){xdir=rand() %3;ydir=rand() %3;}
    dir.insert(dir.begin(),xdir);
    dir.insert(dir.end(),ydir);
    if(rand()%10 /5)
        this->checkDirections();
    this->sleepTime=sleepTime;

}

void Ball::move() {
    mutex cv_m;
    std::mutex mtx;
    std::unique_lock<std::mutex> lck(mtx);
    auto sleeper = chrono::steady_clock::now() + sleepTime*1000ms;
    while (PrintManager::cv_run.wait_for(lck,std::chrono::seconds(sleepTime))==cv_status::no_timeout) {
        //can do stuff here :D
    //    cout<<"Waiting: "<<this->movThread.get_id()<<endl;
    }



   while(PrintManager::run) {
       usleep(10 * 10000);//sleep z thread uzywac
       int xStep = abs(dir[0]);
       int yStep = abs(dir[1]);
       int xStepsDone=0;
       int yStepsDone=0;
       int xForward=0;
       int yForward=0;


           while(xStepsDone<=xStep && yStepsDone<=yStep)
           {
                checkDirections();
                if(dir[0]>0)
                    xForward=1;
                else if(dir[0]<0)
                    xForward=(-1);
                else if(dir[0]==0)
                    xForward=0;

               if(dir[1]>0)
                   yForward=1;
               else if(dir[1]<0)
                   yForward=(-1);
               else if(dir[1]==0)
                   yForward=0;

               moveForward(xForward,yForward);

               xStepsDone++;
               yStepsDone++;


           }
   }
   
}

void Ball::moveForward(int xForward, int yForward) {
    if(xForward>0) x+=1;
    else if (xForward<0) x-=1;

    if(yForward>0) y+=1;
    else if(yForward<0)
        y-=1;
}

void Ball::checkDirections() {
    if(x>=map->sizeX-1 || x<=1)
    {
        dir[0]*=(-1);
    }


    if(y>=map->sizeY-1 || y<=1)
    {
        dir[1]*=(-1);
    }

}


