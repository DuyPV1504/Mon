#ifndef DORAYAKI_H
#define DORAYAKI_H

#include "music.h"

#define DORAYAKI_WIDTH 80
#define DORAYAKI_HEIGHT 80

const int place2[] = {100,300,500,700,900};

struct Dorayaki{
    int x;
    int y;
    SDL_Rect dRect;

    void setpos(int _x, int _y)
    {
    x = _x;
    y = _y;
};

    void render(SDL_Renderer* renderer, SDL_Texture* dorayakiTexture, SDL_Rect &dRect)
    {
    dRect.x = x;
    dRect.y = y;
    dRect.w = DORAYAKI_WIDTH;
    dRect.h = DORAYAKI_HEIGHT;
    SDL_RenderCopy( renderer, dorayakiTexture, NULL, &dRect);
};

    void act()
    {
        y+=5 ;
        if(y > SCREEN_HEIGHT)
        {
            int random = rand()%5;
            x = place2[random];
            y = 0;
        }
};

};


#endif // DORAYAKI_H
