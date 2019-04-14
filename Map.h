//
// Created by wilk on 24.03.19.
//

#ifndef THREADBALLS_MAP_H
#define THREADBALLS_MAP_H

#include <vector>
#include "CollidingItem.h"



class Map {
public:
    int sizeX;
    int sizeY;
    char** charMap;
    std::vector<CollidingItem> colItemsVector;
    Map(int x, int y);

};


#endif //THREADBALLS_MAP_H
