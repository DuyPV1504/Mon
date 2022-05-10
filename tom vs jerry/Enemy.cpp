#include "Enemy.h"

using namespace std;

void Enemy::setpos(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Enemy::render(SDL_Renderer* renderer, SDL_Texture* enemyTexture, SDL_Rect &eRect)
{
    eRect.x = x;
    eRect.y = y;
    eRect.w = ENEMY_WIDTH;
    eRect.h = ENEMY_HEIGHT;
    SDL_RenderCopy( renderer, enemyTexture, NULL, &eRect);
}

void Enemy::move(int score)
{
     y+=5 + (score/100);
        if(y > SCREEN_HEIGHT)
        {
            int random = rand()%5;
            x = place[random];
            y = 0;
        }
}
