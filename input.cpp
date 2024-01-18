#include <SDL.h>
#include "class.hpp"
#include "sdl_functions.hpp"

void visualizer::events(){

    switch(event.type){  
            case SDL_QUIT:
                quit=1;
                break;
                
            default: 
                break;
    }

}