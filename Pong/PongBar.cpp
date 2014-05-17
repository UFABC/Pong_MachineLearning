//
//  PongBar.cpp
//  Pong
//
//  Created by Juliano-Mac on 15/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "PongBar.h"

PongBar::PongBar(char* name)
{
    
}

void PongBar::Update(){
    this->y += actualAction * speed;
}