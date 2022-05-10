#ifndef GAME_FUNCTION_H
#define GAME_FUNCTION_H

#include "music.h"
#include "Doraemon.h"
#include "Enemy.h"
#include "Text.h"

bool check (SDL_Rect object1Rect, SDL_Rect& DoraemonRect);

bool CheckInside (int &x, int &y, SDL_Rect& Rect);
int Selection(SDL_Event &e, Text Button[]);

#endif // GAME_FUNCTION_H
