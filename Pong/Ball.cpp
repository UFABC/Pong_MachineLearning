//
//  Ball.cpp
//  Pong
//
//  Created by Juliano-Mac on 15/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "Ball.h"


Ball::Ball(int screenHeight, int screenWidth)
{
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
}

void Ball::Update()
{
    if (this->directionX == 0 || this->directionY == 0) {
        this->directionY = 1;
        this->directionX = 1;
    }
    
    if (this->y >= (this->screenHeight - this->height)) {
        this->directionY = -1;
    }
    
    if (this->x >= (this->screenWidth - this->width)) {
        this->directionX = -1;
    }
    
    if (this->y <= 0) {
        this->directionY = 1;
    }
    
    if (this->x <= 0) {
        this->directionX = 1;
    }
    
    this->x += directionX * speed;
    this->y += directionY * speed;
}