#pragma once
#include <sdl.h>
#include <sdl_ttf.h>
#include <vector>
#include "sdl_functions.hpp"
#include "sorting.hpp"
#include "window.hpp"

namespace Visualizer {

   enum algorithms {
      QUICKSORT,
      BUBBLESORT,
      INSERTIONSORT,
      SELECTIONSORT,
      BOGOSORT,
      MIRACLESORT
   };

   class Application {
   public:
      Application() : m_sorter([this] {
                         run();
                         return !window.shouldClose();
                      }) {}

      Window window;
      void events();
      void run();

   private:
      std::vector<int> m_array = {2, 4, 7, 1, 3, 5, 6};
      Sorter m_sorter;
      SDL_Renderer *m_renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED);
      TTF_Font *m_font = TTF_OpenFont("calibri.ttf", 30);
      int m_currentAlgorithm = QUICKSORT;
      SDL_Event m_event;
   };

} // namespace Visualizer