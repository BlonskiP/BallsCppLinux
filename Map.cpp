//
// Created by wilk on 24.03.19.
//

#include "Map.h"

Map::Map(int x, int y) {
    this->colItemsVector = new std::vector<CollidingItem>();
    sizeX= x;
    sizeY= y;
    charMap=new char*[x];
    for(int i=0;i<x;i++) {
        charMap[i] = new char[y];
    }
    for(int i=0;i<x;i++)
        for(int k=0;k<y;k++)
        {
            if(i==0 || i==x-1)
                charMap[i][k]='-';
            else if(k==0 || k==y-1)
                charMap[i][k]='|';
            else
                charMap[i][k]=' ';
        }
}

void Map::collisionCheck(Ball ball) {
    
}
