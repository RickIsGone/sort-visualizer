#include "visualizer.hpp"
#include "sorting.hpp"

namespace Visualizer {

   void Application::run() {
      while (SDL_PollEvent(&m_event)) {
         events();
      }

      if (sdl::button("quicksort", 100, 100, 200, 100, 60, 60, 60, m_renderer, m_font)) m_currentAlgorithm = QUICKSORT;
      if (sdl::button("bubble sort", 100, 210, 200, 100, 60, 60, 60, m_renderer, m_font)) m_currentAlgorithm = BUBBLESORT;
      if (sdl::button("insertion sort", 100, 320, 200, 100, 60, 60, 60, m_renderer, m_font)) m_currentAlgorithm = INSERTIONSORT;
      if (sdl::button("selection sort", 100, 430, 200, 100, 60, 60, 60, m_renderer, m_font)) m_currentAlgorithm = SELECTIONSORT;
      if (sdl::button("bogosort", 100, 540, 200, 100, 60, 60, 60, m_renderer, m_font)) m_currentAlgorithm = BOGOSORT;
      if (sdl::button("miracle sort", 100, 650, 200, 100, 60, 60, 60, m_renderer, m_font)) m_currentAlgorithm = MIRACLESORT;
      if (sdl::button("shuffle", 400, 100, 200, 100, 60, 60, 60, m_renderer, m_font))
         if (!m_sorter.isSorting()) m_sorter.shuffle(m_array, m_array.size());
      if (sdl::button("start", 400, 210, 200, 100, 60, 60, 60, m_renderer, m_font)) {
         if (!m_sorter.isSorting()) {
            m_sorter.beginSorting();
            switch (m_currentAlgorithm) {
               case QUICKSORT:
                  m_sorter.quickSort(m_array, 0, m_array.size() - 1);
                  break;

               case BUBBLESORT:
                  m_sorter.bubbleSort(m_array, m_array.size());
                  break;

               case INSERTIONSORT:
                  m_sorter.insertionSort(m_array, m_array.size());
                  break;

               case SELECTIONSORT:
                  m_sorter.selectionSort(m_array, m_array.size());
                  break;

               case BOGOSORT:
                  m_sorter.bogoSort(m_array, m_array.size());
                  break;

               default:
                  break;
            }
            m_sorter.endSorting();
         }
      }
      if (sdl::button("resize", 400, 320, 200, 100, 60, 60, 60, m_renderer, m_font) && !m_sorter.isSorting()) {
         int size;
         do {
            std::cout << "insert the size of the test (2-230):\n";
            std::cin >> size;
            if (size < 2 || size > 230) std::cout << "the size is " << ((size > 230) ? "too big, " : "too small, ");
         } while (size < 2 || size > 230);

         m_array.clear();
         for (int i = 1; i <= size; ++i) {
            m_array.push_back(i);
         }
      }

      int offsett = 0;
      for (int i : m_array) {
         SDL_Rect num;
         num.w = 700 / m_array.size();
         num.h = i * 650 / m_array.size();
         num.y = 750 - num.h;
         num.x = 700 + offsett;
         offsett += num.w;

         if (m_array[i - 1] == i) SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
         else
            SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);

         SDL_RenderFillRect(m_renderer, &num);
         SDL_SetRenderDrawColor(m_renderer, 30, 30, 30, 255);
         SDL_RenderDrawRect(m_renderer, &num);
      }
      SDL_RenderPresent(m_renderer);
      SDL_RenderClear(m_renderer);
   }

   void Application::events() {
      switch (m_event.type) {
         case SDL_QUIT:
            window.exit();
            break;

         default:
            break;
      }
   }

} // namespace Visualizer