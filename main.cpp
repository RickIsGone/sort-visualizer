#include <ctime>
#include <SDL_main.h>
#include "visualizer.hpp"
#include "sdl_functions.hpp"

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    srand(time(0));

    Visualizer app;

    TTF_Font* font = TTF_OpenFont("calibri.ttf", 30);
    
    
    while(!app.shouldClose()){
        app.run(font);
    }
    
    return EXIT_SUCCESS;
}