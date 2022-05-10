#ifndef UTLIS_H
#define UTLIS_H


#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "music.h"

using namespace std;


void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
#endif // UTLIS_H
