#pragma once
#include <sdl.h>
#include <sdl_ttf.h>
#include <vector>
#include "sdl_functions.hpp"

enum algorithms{
    QUICKSORT,
    BUBBLESORT,
    INSERTIONSORT,
    SELECTIONSORT,
    BOGOSORT,
    MIRACLESORT
};

class Visualizer{
private:
    SDL_Window *window=SDL_CreateWindow("sort visualizer",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_ALLOW_HIGHDPI);
    
    bool isSorted(std::vector<int> &a, int n);
    void shuffle(std::vector<int> &a, int n);
    int partition(std::vector<int> &arr, int low, int high, TTF_Font* font);
    void quickSort(std::vector<int> &arr, int low, int high, TTF_Font* font);
    void bogoSort(std::vector<int> &a, int n, TTF_Font* font);
    void miracleSort(std::vector<int> &a, int n, TTF_Font* font);
    void insertionSort(std::vector<int> &arr, int n, TTF_Font* font);
    void bubbleSort(std::vector<int> &arr, int n, TTF_Font* font);
    void selectionSort(std::vector<int> &arr, int n, TTF_Font* font);

    std::vector<int> m_array = {2,4,7,1,3,5,6};

    bool m_sorting = false;
    bool m_resizing = false;
    bool m_quit = false;

public:

    SDL_Event event;
    SDL_Event WindowEvent;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int currentAlgorithm = QUICKSORT;

    void events();

    void run(TTF_Font* font);

    bool shouldClose(){ return m_quit;}
    
};