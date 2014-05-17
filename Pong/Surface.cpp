//
//  Surface.cpp
//  Pong
//
//  Created by Juliano-Mac on 14/05/14.
//  Copyright (c) 2014 AGameEngine. All rights reserved.
//

#include "Surface.h"

Surface::Surface()
{
}

Surface::~Surface()
{
}


void Surface::RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}