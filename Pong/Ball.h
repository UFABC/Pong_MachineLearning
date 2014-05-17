//
//  Ball.h
//  Pong
//
//  Created by Juliano-Mac on 15/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#ifndef __Pong__Ball__
#define __Pong__Ball__

#include "Entity.h"

class Ball : public Entity
{
public:
    Ball (int screenHeight, int screenWidth);
    
    
    int speed = 2;
    
    //1 for posictive direction and - 1 for negative direction
    //0 for standing still
    int directionX = 0;
    int directionY = 0;
    
    void Update();
    
private:
    int screenHeight;
    int screenWidth;
};
#endif /* defined(__Pong__Ball__) */
