#include <ctime>
#include <SDL_main.h>
#include "visualizer.hpp"
#include "sdl_functions.hpp"

int main(int argc, char *argv[]) {
   SDL_Init(SDL_INIT_EVERYTHING);
   TTF_Init();
   srand(time(0));

   Visualizer::Application app{};

   while (!app.window.shouldClose()) {
      app.run();
   }

   return EXIT_SUCCESS;
}