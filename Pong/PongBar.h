//
//  PongBar.h
//  Pong
//
//  Created by Juliano-Mac on 15/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#ifndef __Pong__PongBar__
#define __Pong__PongBar__

#include "Entity.h"

class PongBar : public Entity
{
public:
    PongBar(char* name);
    
    const int Up = -1;
    const int Down = 1;
    const int Stay = 0;
    
    int actualAction = 1;
    
    float alpha = 0.01;

    float gamma = 0.5;
    
    float speed = 1.0f;
    void Update();

};

#endif /* defined(__Pong__PongBar__) */
