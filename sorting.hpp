#pragma once 
#include <iostream>
#include <sdl.h>
#include <vector>
using std::vector;

bool isSorted(vector<int> &a, int n);
void shuffle(std::vector<int> &a, int n);
int partition(vector<int> &arr, int low, int high);
void quickSort(vector<int> &arr, int low, int high);
void bogoSort(vector<int> &a, int n);
void miracleSort(vector<int> &a, int n);
void stalinSort(vector<int> &a, int& n);
void insertionSort(vector<int> &arr, int n);
void bubbleSort(vector<int> &arr, int n);
void selectionSort(vector<int> &arr, int n);

