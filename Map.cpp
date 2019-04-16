//
// Created by wilk on 24.03.19.
//

#include "Map.h"
#include "Wall.h"

Map::Map(int x, int y) {
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

      auto it = colItemsVector.begin();
      CollidingItem* rightWall = new Wall(0,20,50,50);
      CollidingItem* leftWall = new Wall(0,20,0,0);
      //colItemsVector.insert(it,rightWall);
     // colItemsVector.insert(it,leftWall);
      CollidingItem* upWall = new Wall(0,0,0,30);
      //colItemsVector.insert(it,upWall);
      CollidingItem* downWall = new Wall(30,30,0,30);
      colItemsVector.insert(it,downWall);
}

void Map::collisionCheck(Ball &ball) {
    for(auto colidingItem : colItemsVector)
    {
        if(colidingItem->isColliding(ball))
        {
            colidingItem->colision(ball);
        }
    }
}
