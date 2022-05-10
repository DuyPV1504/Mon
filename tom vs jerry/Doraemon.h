#ifndef DORAEMON_H
#define DORAEMON_H

#include "music.h"

#define DORAEMON_WIDTH 200
#define DORAEMON_HEIGHT 200
using namespace std;

const int step = 200;

struct Doraemon{
    int x;
    int y = 400;

    void setpos(int _x, int _y)
    {
        x = _x;
        y = _y;
    };

    void render(SDL_Renderer* renderer, SDL_Texture* doraemonTexture, SDL_Rect &doraemonRect)
    {
    doraemonRect.x = x;
    doraemonRect.y = y;
    doraemonRect.w = DORAEMON_WIDTH;
    doraemonRect.h = DORAEMON_HEIGHT;
    SDL_RenderCopy( renderer, doraemonTexture, NULL, &doraemonRect );
};

    void move(SDL_Event &e)
    {
        if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE: break;
                    case SDLK_LEFT: x = (x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
                        break;
                    case SDLK_RIGHT: x = (x + step) % SCREEN_WIDTH;
                        break;
                    default: break;
                }
            }
};

};

#endif // DORAEMON_H
