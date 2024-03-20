#include "class.hpp"
using std::vector;

bool visualizer::isSorted(vector<int> &a, int n) {
    while (--n > 0){
        if (a[n] < a[n - 1])
            return false;
    }
    isBeingSorted=0;
    return true;
}

void visualizer::shuffle(std::vector<int> &a, int n) {
    for (int i = 0; i < n; i++){
        std::swap(a[i], a[rand() % n]);
    }
}

int visualizer::partition(vector<int> &arr, int low, int high, TTF_Font* font){   
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        cicle(font);
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void visualizer::quickSort(vector<int> &arr, int low, int high, TTF_Font* font){
    
    if(quit) return;
    if (low < high)
    {
        int pivot = partition(arr, low, high,font);
        quickSort(arr, low, pivot - 1,font);
        quickSort(arr, pivot + 1, high,font);
    }
    
}


void visualizer::bogoSort(vector<int> &a, int n, TTF_Font* font) {
    while (!isSorted(a, n) && !quit) {
        cicle(font);
        shuffle(a,a.size());
    }
}

void visualizer::miracleSort(vector<int> &a, int n, TTF_Font* font) {
    while (!isSorted(a, n) && !quit) {
        cicle(font);
        miracleSort(a, n,font);
    }
}

// void visualizer::stalinSort(vector<int> &a, int& n, TTF_Font* font) {
//     int j = 0;
//     for (int i = 1; i < n; i++) {
//         if (a[j] <= a[i]) {
//             j++;
//             a[j] = a[i];
//         }
//     }
//     n = j + 1;
// }

void visualizer::insertionSort(vector<int> &arr, int n, TTF_Font* font){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {   
            cicle(font);
            if(quit) return;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    isBeingSorted=0;
}

void visualizer::bubbleSort(vector<int> &arr, int n, TTF_Font* font) {
    int i, j;
    for (i = 0; i < n - 1; i++){
        cicle(font);
        for (j = 0; j < n - i - 1; j++){\
            cicle(font);
            if(quit) return;
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
    isBeingSorted=0;
}

void visualizer::selectionSort(vector<int> &arr, int n, TTF_Font* font) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        cicle(font);
        min_idx = i;
        for (j = i + 1; j < n; j++){
            cicle(font);
            if(quit) return;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        std::swap(arr[min_idx], arr[i]);
    }
    isBeingSorted=0;
}