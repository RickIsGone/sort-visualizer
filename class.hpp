#pragma once
#include <sdl.h>
#include <sdl_ttf.h>
#include <vector>
#include "sdl_functions.hpp"
#include "sorting.hpp"

// void shuffle(std::vector<int>&a, int n);
enum algorithms{
    QUICKSORT,
    BUBBLESORT,
    INSERTIONSORT,
    SELECTIONSORT,
    BOGOSORT,
    STALINSORT,
    MIRACLESORT
};

class visualizer{

    SDL_Window *window=SDL_CreateWindow("sort visualizer",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1600,900,SDL_WINDOW_ALLOW_HIGHDPI);
    
    std::vector<int>array={1,9,3,4,5,6,8,7,2,10,12,11};
    // std::vector<SDL_Rect>numbers;
    
    public:

    SDL_Event event;
    SDL_Event WindowEvent;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    bool quit=0;

    TTF_Font *font = TTF_OpenFont("calibri.ttf", 30);

    int current_algorithm=QUICKSORT;

    void events();

    void draw(){
        
        int offsett=0;
        if(sdl::button("quicksort",100,100,200,100,60,60,60,renderer)) current_algorithm=QUICKSORT;
        if(sdl::button("bubble sort",100,210,200,100,60,60,60,renderer)) current_algorithm=BUBBLESORT;
        if(sdl::button("insertion sort",100,320,200,100,60,60,60,renderer)) current_algorithm=INSERTIONSORT;
        if(sdl::button("selection sort",100,430,200,100,60,60,60,renderer)) current_algorithm=SELECTIONSORT;
        if(sdl::button("bogosort",100,540,200,100,60,60,60,renderer)) current_algorithm=BOGOSORT;
        // if(sdl::button("stalin sort",100,650,200,100,60,60,60,renderer)) current_algorithm=STALINSORT;
        if(sdl::button("miracle sort",100,650,200,100,60,60,60,renderer)) current_algorithm=MIRACLESORT;

        if(sdl::button("shuffle",400,100,200,100,60,60,60,renderer)) shuffle(array,array.size());
        if(sdl::button("start",400,200,200,100,60,60,60,renderer)){
            switch(current_algorithm){
                case QUICKSORT:
                    quickSort(array, 0, array.size() - 1);
                    break;
                
                case BUBBLESORT:
                    bubbleSort(array,array.size());
                    break;

                case INSERTIONSORT:
                    insertionSort(array,array.size());
                    break;

                case SELECTIONSORT:
                    selectionSort(array,array.size());
                    break;

                case BOGOSORT:
                    bogoSort(array,array.size());
                    break;
                
                case MIRACLESORT:
                    miracleSort(array,array.size());
                    break;

                default:
                    break;
            }
        }

        for(int i:array){
            SDL_Rect num;
            num.w=700/array.size();
            num.h=i*650/array.size();
            num.y=750-num.h;
            num.x=700+offsett;
            offsett+=num.w;

            if(array[i-1]==i) SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); 
            else SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 

            SDL_RenderFillRect(renderer, &num); 
            SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
            SDL_RenderDrawRect(renderer, &num);
        }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

}extern app;


