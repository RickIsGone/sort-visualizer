#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "sdl_functions.hpp"
#include "visualizer.hpp"

MouseState mouseState;

void mouse_update() {
   int mouse_x, mouse_y;
   Uint32 buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
   bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;

   mouseState.x = mouse_x;
   mouseState.y = mouse_y;
   mouseState.leftButton = leftButton;
}


namespace sdl {

   void quick_text(std::string writing, Uint8 r, Uint8 g, Uint8 b, int x, int y, SDL_Renderer *renderer, TTF_Font *font) {
      SDL_Surface *surface = TTF_RenderText_Solid(font, writing.c_str(), {r, g, b});
      SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
      int text_width = surface->w;
      int text_height = surface->h;
      SDL_FreeSurface(surface);

      SDL_Rect dstrect = {x, y, text_width, text_height};

      SDL_RenderCopy(renderer, texture, NULL, &dstrect);
      SDL_DestroyTexture(texture);
   }


   void v_quick_text(std::string writing, int var, Uint8 r, Uint8 g, Uint8 b, int y, SDL_Renderer *renderer, TTF_Font *font) {
      std::string text = writing + std::to_string(var);
      SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), {r, g, b});
      SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
      int text_width = surface->w;
      int text_height = surface->h;
      SDL_FreeSurface(surface);

      SDL_Rect dstrect = {(700 - text_width) / 2, y, text_width, text_height};

      SDL_RenderCopy(renderer, texture, NULL, &dstrect);
      SDL_DestroyTexture(texture);
   }


   bool button(std::string text, int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, SDL_Renderer *renderer, TTF_Font *font) {
      mouse_update();

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_Rect rect2;
      rect2.x = x - 2;
      rect2.y = y - 2;
      rect2.w = width + 4;
      rect2.h = height + 4;

      SDL_RenderFillRect(renderer, &rect2);

      if ((mouseState.x >= x && mouseState.x <= x + width) && (mouseState.y >= y && mouseState.y <= y + height)) {
         if (mouseState.leftButton) {
            SDL_SetRenderDrawColor(renderer, r - 24, g - 24, b - 24, 255);
            return true;
         }
         SDL_SetRenderDrawColor(renderer, r - 16, g - 16, b - 16, 255);
      } else
         SDL_SetRenderDrawColor(renderer, r, g, b, 255);

      SDL_Rect rect;
      rect.x = x;
      rect.y = y;
      rect.w = width;
      rect.h = height;

      SDL_RenderFillRect(renderer, &rect);


      SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), {0, 0, 0});
      SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
      if (!font) {
         std::cout << "font non caricato: ";
         std::cout << SDL_GetError() << "\n";
      }
      int text_width = surface->w;
      int text_height = surface->h;
      SDL_FreeSurface(surface);

      SDL_Rect dstrect = {x + (width - text_width) / 2, y + (height - text_height) / 2, text_width, text_height};

      SDL_RenderCopy(renderer, texture, NULL, &dstrect);
      SDL_DestroyTexture(texture);

      return false;
   }
} // namespace sdl