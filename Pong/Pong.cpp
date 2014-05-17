//
//  Pong.cpp
//  Pong
//
//  Created by Juliano-Mac on 16/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "Pong.h"


void Pong::Init(SDL_Renderer* renderer, int windowHeight, int windowWidth)
{
    Pong* pong = Pong::GetInstance();
    
    pong->renderer = renderer;
    pong->windowHeight = windowHeight;
    pong->windowWidth = windowWidth;
    
    pong->Init();

}

void Pong::Init()
{
    player1 = new PongBar("player1");
    player1->LoadTexture(renderer, "/Users/mac/Documents/UFABC/Pong/1.bmp");
    
    player2 = new PongBar("player2");
    player2->LoadTexture(renderer, "/Users/mac/Documents/UFABC/Pong/1.bmp");
    
    ball = new Ball(windowHeight, windowWidth);
    
    ball->LoadTexture(renderer, "/Users/mac/Documents/UFABC/Pong/2.bmp");
    
    InitPositions();

    entities.push_back(ball);
    
    entities.push_back(player1);
    entities.push_back(player2);
}

void Pong::InitPositions()
{
    player1->SetPosition(10, windowHeight / 2);
    player2->SetPosition(windowWidth - player2->width - 10, windowHeight / 2);
    ball->SetPosition(10 + player1->width, (windowHeight / 2) + (player1->height / 2));
}

Pong* Pong::GetInstance() { return &Pong::Instance; }


Pong Pong::Instance;