#include "game_function.h"

using namespace std;

bool check (SDL_Rect mouse1Rect, SDL_Rect& doraemonRect)
{
    int left1 = mouse1Rect.x;
    int right1 = mouse1Rect.x + mouse1Rect.w;
    int top1 = mouse1Rect.y;
    int bot1 = mouse1Rect.y + mouse1Rect.h;

    int left2 = doraemonRect.x;
    int right2 = doraemonRect.x + doraemonRect.w;
    int top2 = doraemonRect.y;
    int bot2 = doraemonRect.y + doraemonRect.h;

    if (left2 + 90 < right1 && right2 - 90 > right1 )
    {
        if (top2 < bot1 && bot2 > bot1)
            return true;
        else if (top2 < top1 && bot2 > top1)
            return true;
    }
    if (left2 + 90 < left1 && right2 - 90 > left1)
    {
        if (top2 < bot1 && bot2 > bot1)
            return true;
        else if (top2 < top1 && bot2 > top1)
            return true;
    }
    return false;
}

bool CheckInside (int &x, int &y, SDL_Rect& rect)
{
    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
        return true;
    return false;
}

int Selection(SDL_Event &e, Text Button[])
{
    while (true)
    {
        if (SDL_PollEvent(&e)!=0)
        {
            switch (e.type)
            {
                case SDL_QUIT:
                    return 1;
                case SDL_MOUSEBUTTONDOWN:
                {
                     for (int i = 0; i < 2; i++)
                     {
                         if (CheckInside(e.button.x, e.button.y, Button[i].Rect))
                            return i;
                     }
                }
                break;
                default: break;
            }
        }
    }
}
