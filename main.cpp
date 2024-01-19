#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include <SDL_main.h>
#include "class.hpp"
#include "sdl_functions.hpp"

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    srand(time(0));

    visualizer app;

    
    
    
    while(!app.quit){

        while (SDL_PollEvent(&app.event)){
            app.events();
        }
        app.draw();
        
    }

    return EXIT_SUCCESS;
}