//
//  Pong.h
//  Pong
//
//  Created by Juliano-Mac on 16/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#ifndef __Pong__Pong__
#define __Pong__Pong__

#include "Entity.h"
#include "PongBar.h"
#include "Ball.h"

#include <SDL2/SDL.h>
#include <vector>

class Pong
{
public:
    static void Init(SDL_Renderer* renderer, int windowHeight, int windowWidth);
    
    static Pong* GetInstance();
    
    std::vector<Entity*> entities;
private:
    static Pong Instance;

    SDL_Renderer* renderer;
    
    int windowHeight;
    int windowWidth;
    
    PongBar* player1;
    
    PongBar* player2;
    
    Ball* ball;
    
    void Init();
    
    void InitPositions();
};
#endif /* defined(__Pong__Pong__) */
