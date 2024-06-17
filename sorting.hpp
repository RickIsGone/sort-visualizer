#pragma once

#include <SDL_ttf.h>
#include <vector>

#include "window.hpp"

class Sorter{
private:
    bool m_sorting = false;
    
public:
    Sorter(Window &window) : window{window}{}

    Window& window;
    bool isSorting(){ return m_sorting; }
    void beginSorting() { m_sorting = true; }
    void endSorting() { m_sorting = false; }

    bool isSorted(std::vector<int> &a, int n);
    void shuffle(std::vector<int> &a, int n);
    int partition(std::vector<int> &arr, int low, int high);
    void quickSort(std::vector<int> &arr, int low, int high);
    void bogoSort(std::vector<int> &a, int n);
    void miracleSort(std::vector<int> &a, int n);
    void insertionSort(std::vector<int> &arr, int n);
    void bubbleSort(std::vector<int> &arr, int n);
    void selectionSort(std::vector<int> &arr, int n);
};
