//
//  Entity.h
//  Pong
//
//  Created by Juliano-Mac on 16/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#ifndef __Pong__Entity__
#define __Pong__Entity__

#include <SDL2/SDL.h>
#include "Log.h"

class Entity
{
public:
    int x;
    int y;
    
    int width;
    int height;
    
    SDL_Texture* texture;
    
    void LoadTexture(SDL_Renderer* renderer, char* texturePath);
    
    void SetPosition(int x, int y);
    
    virtual void Update();
};
#endif /* defined(__Pong__Entity__) */
