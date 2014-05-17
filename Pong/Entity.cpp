//
//  Entity.cpp
//  Pong
//
//  Created by Juliano-Mac on 16/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "Entity.h"

void Entity::LoadTexture(SDL_Renderer* ren,char* File)
{
    SDL_Surface *bmp = SDL_LoadBMP(File);
    if (bmp == nullptr){
        Log("SDL_LOADBMP error: %s", SDL_GetError());
        return;
    }
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    
    if (tex == nullptr){
        Log("SDL_CreateTextureFromSurface Error");
        return;
    }
    
    texture = tex;
    
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    
    return;
}

void Entity::SetPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Entity::Update()
{
    
}