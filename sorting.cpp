#include <iostream>
#include <vector>
#include <sdl.h>
#include "class.hpp"
using std::vector;

bool isSorted(vector<int> &a, int n) {
    while (--n > 0){
        if (a[n] < a[n - 1])
            return false;
    }
    return true;
}

void shuffle(std::vector<int> &a, int n) {
    for (int i = 0; i < n; i++){
        std::swap(a[i], a[rand() % n]);
    }
}

int partition(vector<int> &arr, int low, int high){   
    SDL_Delay(1);
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        SDL_Delay(1);
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high){
    SDL_Delay(1);
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

}


void bogoSort(vector<int> &a, int n) {
    while (!isSorted(a, n)) {
        SDL_Delay(1);
        shuffle(a,a.size());
    }
}

void miracleSort(vector<int> &a, int n) {
    while (!isSorted(a, n)) {
        miracleSort(a, n);
    }

}

void stalinSort(vector<int> &a, int& n) {
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (a[j] <= a[i]) {
            j++;
            a[j] = a[i];
        }

    }
    n = j + 1;
}

void insertionSort(vector<int> &arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        SDL_Delay(1);
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {   
            SDL_Delay(1);
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(vector<int> &arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++){
        SDL_Delay(1);
        for (j = 0; j < n - i - 1; j++){
            SDL_Delay(1);
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

void selectionSort(vector<int> &arr, int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        SDL_Delay(1);
        min_idx = i;
        for (j = i + 1; j < n; j++){
            SDL_Delay(1);
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        std::swap(arr[min_idx], arr[i]);
    }
}