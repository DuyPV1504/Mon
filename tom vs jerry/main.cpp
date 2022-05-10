#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>

#include "music.h"
#include "Utils.h"
#include "Text.h"
#include "Doraemon.h"
#include "Enemy.h"
#include "dorayaki.h"
#include "game_function.h"
using namespace std;

Doraemon doraemon;
Doraemon deadmon;
Enemy enemy[MAX];
Dorayaki dorayaki[BIG];
Text text;
Text Button[2];
Text FinalScore;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

SDL_Texture* deadTexture = NULL;
SDL_Texture* menu = NULL;
SDL_Texture* background = NULL;
SDL_Texture* dorayakiTexture = NULL;
SDL_Texture* doraemonTexture = NULL;
SDL_Texture* enemyTexture = NULL;
SDL_Texture* ButtonTexture[2];

SDL_Rect doraemonRect;

Mix_Music *Music = NULL;
Mix_Chunk *Die = NULL;

TTF_Font* fontText = NULL;
TTF_Font* fontButton = NULL;

void open();
void close();

int main (int argc, char*argv[])
{

    initSDL(window, renderer);
    open();
    Mix_PlayMusic( Music, -1 );

    SDL_Event e;
    int score = 0;
    bool QuitGame = false;
    for (int i = 0; i < MAX; i++)
    {
        enemy[i].setpos(place[rand()%5], - 200 * i);
    }
    SDL_RenderCopy(renderer, menu, nullptr, nullptr);
    Button[0].content = "Play Game";
    Button[0].Color = {255,0,0};
    Button[1].content = "Quit Game";
    Button[1].Color = {255,0,0};
    for (int i = 0; i < 2; i++)
    {
        ButtonTexture[i] = Button[i].loadFromRenderedText(fontButton, renderer);
        Button[i].setpos(0, 250 + 100 * i);
        Button[i].render(renderer, ButtonTexture[i], Button[i].Rect);
    }
    SDL_RenderPresent(renderer);
    if (Selection(e, Button) == 1)
        QuitGame = 1;
        while (!QuitGame)
    {
        int score = 0;
        bool GameOver = false;
        doraemon.setpos(0,400);
        doraemon.render(renderer, doraemonTexture, doraemonRect);
        for(int i=0;i<MAX;i++)
        {
            for(int j=0;j<BIG;j++)
            {
                enemy[i].setpos(place[rand()%5], - 200 * i);
                dorayaki[j].setpos(place2[rand()%5],0);
                enemy[i].render(renderer, enemyTexture, enemy[i].eRect);
                dorayaki[j].render(renderer, dorayakiTexture, dorayaki[j].dRect);
            }
        }

    while(!GameOver)
    {
        for(int i = 0; i < MAX; i++)
        {
            enemy[i].move(score);
            if(check(enemy[i].eRect,doraemonRect))
            {
                GameOver = true;
            }
        }

        for(int j = 0; j < BIG; j++)
        {
            dorayaki[j].act();
            if(check(dorayaki[j].dRect,doraemonRect))
            {
                score++;
                dorayaki[j].setpos(place2[rand()%5],0);
            }
        }
        text.content = "Score: " + to_string(score);
        SDL_Texture* textTexture = text.loadFromRenderedText(fontText, renderer);
        text.setpos(0,10);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, nullptr, nullptr);
        if (!GameOver)
        {
            doraemon.render(renderer, doraemonTexture, doraemonRect);
        }
        else
        {
            deadmon.setpos(doraemon.x, doraemon.y);
            deadmon.render(renderer, deadTexture, doraemonRect);
        }

        for(int i = 0; i < MAX; i++)
        {
            enemy[i].render(renderer, enemyTexture, enemy[i].eRect);
            text.render(renderer, textTexture, text.Rect);
        }
        for(int j =0; j < BIG; j++)
        {
            dorayaki[j].render(renderer, dorayakiTexture, dorayaki[j].dRect);
            text.render(renderer, textTexture, text.Rect);
        }
        SDL_RenderPresent(renderer);

        if (SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        PauseGame(e);
        PauseMusic(e);
        doraemon.move(e);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture( textTexture );
        textTexture = nullptr;
    }

    Mix_PlayChannel( -1, Die, 0 );
    waitUntilKeyPressed();
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    FinalScore.content = "Your score is: " + to_string(score);
    SDL_Texture* scoreTexture = FinalScore.loadFromRenderedText(fontText, renderer);
    FinalScore.setpos(0,10);
    FinalScore.render(renderer, scoreTexture, FinalScore.Rect);
    for (int i = 0; i < 2; i++)
    {
        ButtonTexture[i] = Button[i].loadFromRenderedText(fontButton, renderer);
        Button[i].setpos(0, 250 + 100 * i);
        Button[i].render(renderer, ButtonTexture[i], Button[i].Rect);
    }
    SDL_RenderPresent(renderer);
    if (Selection(e, Button) == 1)
        QuitGame = 1;
    SDL_DestroyTexture( scoreTexture );
    scoreTexture = nullptr;
    }
    close();
    return 0;
}

void open()
{
    deadTexture = loadTexture("dead.png", renderer);
    menu = loadTexture("menu.png", renderer);
    background = loadTexture("background.png", renderer);
    doraemonTexture = loadTexture("mon.png", renderer);
    dorayakiTexture = loadTexture("dorayaki.png", renderer);
    enemyTexture = loadTexture("mouse.png", renderer);
    fontText = TTF_OpenFont( "OpenSans_Regular.ttf", 24 );
    fontButton = TTF_OpenFont( "SuperMario256.ttf", 36);
    Music = Mix_LoadMUS( "KandoTheme.wav" );
	Die = Mix_LoadWAV( "doraemonsms.wav" );
}

void close()
{
    SDL_DestroyTexture( menu );
    menu = nullptr;
    SDL_DestroyTexture( deadTexture );
    deadTexture = nullptr;
    SDL_DestroyTexture( background );
    background = nullptr;
    SDL_DestroyTexture( doraemonTexture );
    doraemonTexture = nullptr;
    SDL_DestroyTexture( dorayakiTexture );
    dorayakiTexture = nullptr;
    SDL_DestroyTexture( enemyTexture );
    enemyTexture = nullptr;
    Mix_FreeChunk( Die );
    Die = nullptr;
    Mix_FreeMusic( Music );
    Music = nullptr;
    quitSDL(window, renderer);
	fontText = nullptr;
	TTF_CloseFont( fontText );
}

