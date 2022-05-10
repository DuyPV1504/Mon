#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>

#define MAX 5
#define BIG 5
using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Mon vs Jerry";

SDL_Texture* loadTexture( string path, SDL_Renderer* renderer );
void OpenAudio ();
void PauseGame (SDL_Event &e);
void PauseMusic (SDL_Event &e);


#endif // MUSIC_H
