#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include <SDL_main.h>
#include <SDL_mixer.h>
#include "class.hpp"
#include "sdl_functions.hpp"


int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    srand(time(0));

    visualizer app;
    TTF_Font *font = TTF_OpenFont("calibri.ttf", 30);
    
    if(!font) std::cout <<TTF_GetError() <<"\n";

    while(!app.quit){
        while (SDL_PollEvent(&app.event)){
            app.events(font);
        }
        app.draw(font);
        
    }

    return EXIT_SUCCESS;
}