#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>
#include <ctime>
#include "music.h"

#define ENEMY_WIDTH 80
#define ENEMY_HEIGHT 80

const int place[] = {100,300,500,700,900};

struct Enemy{
    int x;
    int y;
    SDL_Rect eRect;

    void setpos(int _x, int _y)
    {
    x = _x;
    y = _y;
};

    void render(SDL_Renderer* renderer, SDL_Texture* enemyTexture, SDL_Rect &eRect)
    {
    eRect.x = x;
    eRect.y = y;
    eRect.w = ENEMY_WIDTH;
    eRect.h = ENEMY_HEIGHT;
    SDL_RenderCopy( renderer, enemyTexture, NULL, &eRect);
};

    void move(int score)
    {
     y+=1 + (score/50);
        if(y > SCREEN_HEIGHT)
        {
            int random = rand()%4;
            x = place[random];
            y = 0;
        }
};

};

#endif // ENEMY_H
