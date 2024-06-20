#include "visualizer.hpp"
#include "sorting.hpp"

namespace Visualizer {

   bool Sorter::isSorted(std::vector<int> &a, int n) {
      while (--n > 0) {
         if (a[n] < a[n - 1])
            return false;
      }
      return true;
   }

   void Sorter::shuffle(std::vector<int> &a, int n) {
      for (int i = 0; i < n; ++i) {
         std::swap(a[i], a[rand() % n]);
      }
   }

   int Sorter::partition(std::vector<int> &arr, int low, int high) {
      int pivot = arr[high];
      int i = (low - 1);

      for (int j = low; j <= high - 1; j++) {
         if (!stepCallback()) return -1;
         if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
         }
      }
      std::swap(arr[i + 1], arr[high]);
      return (i + 1);
   }

   void Sorter::quickSort(std::vector<int> &arr, int low, int high) {
      if (low < high) {
         int pivot = partition(arr, low, high);
         if (pivot == -1) return;
         quickSort(arr, low, pivot - 1);
         quickSort(arr, pivot + 1, high);
      }
   }

   void Sorter::bogoSort(std::vector<int> &a, int n) {
      while (!isSorted(a, n)) {
         if (!stepCallback()) return;
         shuffle(a, a.size());
      }
   }

   void Sorter::miracleSort(std::vector<int> &a, int n) {
      while (!isSorted(a, n)) {
         if (!stepCallback()) return;
         miracleSort(a, n);
      }
   }

   void Sorter::insertionSort(std::vector<int> &arr, int n) {
      int i, key, j;
      for (i = 1; i < n; ++i) {
         key = arr[i];
         j = i - 1;

         while (j >= 0 && arr[j] > key) {
            if (!stepCallback()) return;
            arr[j + 1] = arr[j];
            j = j - 1;
         }
         arr[j + 1] = key;
      }
   }

   void Sorter::bubbleSort(std::vector<int> &arr, int n) {
      int i, j;
      for (i = 0; i < n - 1; ++i) {
         for (j = 0; j < n - i - 1; j++) {
            if (!stepCallback()) return;
            if (arr[j] > arr[j + 1])
               std::swap(arr[j], arr[j + 1]);
         }
      }
   }

   void Sorter::selectionSort(std::vector<int> &arr, int n) {
      int i, j, min_idx;

      for (i = 0; i < n - 1; ++i) {
         min_idx = i;
         for (j = i + 1; j < n; j++) {
            if (!stepCallback()) return;
            if (arr[j] < arr[min_idx])
               min_idx = j;
         }
         std::swap(arr[min_idx], arr[i]);
      }
   }

} // namespace Visualizer
