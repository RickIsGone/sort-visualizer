#include "visualizer.hpp"
using std::vector;

bool Visualizer::isSorted(vector<int> &a, int n) {
    while (--n > 0){
        if (a[n] < a[n - 1])
            return false;
    }
    m_sorting = false;
    return true;
}

void Visualizer::shuffle(std::vector<int> &a, int n) {
    for (int i = 0; i < n; i++){
        std::swap(a[i], a[rand() % n]);
    }
}

int Visualizer::partition(vector<int> &arr, int low, int high, TTF_Font* font){   
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        run(font);
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void Visualizer::quickSort(vector<int> &arr, int low, int high, TTF_Font* font){
    
    if(m_quit) return;
    if (low < high)
    {
        int pivot = partition(arr, low, high,font);
        quickSort(arr, low, pivot - 1,font);
        quickSort(arr, pivot + 1, high,font);
    }
    
}


void Visualizer::bogoSort(vector<int> &a, int n, TTF_Font* font) {
    while (!isSorted(a, n) && !m_quit) {
        run(font);
        shuffle(a,a.size());
    }
}

void Visualizer::miracleSort(vector<int> &a, int n, TTF_Font* font) {
    while (!isSorted(a, n) && !m_quit) {
        run(font);
        miracleSort(a, n, font);
    }
}

void Visualizer::insertionSort(vector<int> &arr, int n, TTF_Font* font){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {   
            run(font);
            if(m_quit) return;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    m_sorting = false;
}

void Visualizer::bubbleSort(vector<int> &arr, int n, TTF_Font* font) {
    int i, j;
    for (i = 0; i < n - 1; i++){
        run(font);
        for (j = 0; j < n - i - 1; j++){\
            run(font);
            if(m_quit) return;
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
    m_sorting = false;
}

void Visualizer::selectionSort(vector<int> &arr, int n, TTF_Font* font) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++){
            run(font);
            if(m_quit) return;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        std::swap(arr[min_idx], arr[i]);
    }
    m_sorting = false;
}