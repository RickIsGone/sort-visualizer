#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_ttf.h> 
#include <SDL_main.h>
#include "class.hpp"
#include "sdl_functions.hpp"

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    srand(time(0));

    visualizer app;

    TTF_Font* font = TTF_OpenFont("calibri.ttf", 30);
    
    
    while(!app.quit){

        while (SDL_PollEvent(&app.event)){
            app.events();
        }
        app.draw(font);
        
    }
    
    return EXIT_SUCCESS;
}