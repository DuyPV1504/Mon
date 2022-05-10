#include "dorayaki.h"

using namespace std;

void Dorayaki::setpos(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Dorayaki::render(SDL_Renderer* renderer, SDL_Texture* dorayakiTexture, SDL_Rect &dRect)
{
    dRect.x = x;
    dRect.y = y;
    dRect.w = DORAYAKI_WIDTH;
    dRect.h = DORAYAKI_HEIGHT;
    SDL_RenderCopy( renderer, dorayakiTexture, NULL, &dRect);
}

void Dorayaki::act()
{
        y-=5 ;
        if(y < 0)
        {
            int random = rand()%5;
            x = place2[random];
            y = 600;
        }
}
