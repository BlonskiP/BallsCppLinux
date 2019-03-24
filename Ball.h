//
// Created by wilk on 24.03.19.
//

#ifndef THREADBALLS_BALL_H
#define THREADBALLS_BALL_H
#include <unistd.h>
#include <thread>

class Ball {
public:
    Ball(int x, int y);
    int x;
    int y;
    char symbol='o';
    std::thread *movThread;
private:
    void move();
};


#endif //THREADBALLS_BALL_H
