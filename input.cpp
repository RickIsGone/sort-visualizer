#include <SDL.h>
#include "class.hpp"
#include "sdl_functions.hpp"

void visualizer::events(TTF_Font *font){

    switch(event.type){  
            case SDL_QUIT:
                quit=1;
                break;
                
            default: 
                break;
    }

    
}