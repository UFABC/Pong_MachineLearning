//
//  Surface.h
//  Pong
//
//  Created by Juliano-Mac on 14/05/14.
//  Copyright (c) 2014 Juliano Goemes. All rights reserved.
//

#include <SDL2/SDL.h>
#include "Log.h"

#ifndef __Pong__Surface__
#define __Pong__Surface__


class Surface
{
public:
    Surface();
    virtual ~Surface();
    
    void RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
};
#endif /* defined(__Pong__Surface__) */
