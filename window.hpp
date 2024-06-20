#pragma once

#include <SDL.h>

namespace Visualizer {

   class Window {
   private:
      SDL_Window *m_window = SDL_CreateWindow("Sort visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_ALLOW_HIGHDPI);
      bool m_quit = false;

   public:
      bool shouldClose() { return m_quit; }
      SDL_Window *getWindow() { return m_window; }
      void exit() { m_quit = true; }
   };

} // namespace Visualizer