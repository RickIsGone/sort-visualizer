#pragma once
#include <iostream>
#include <SDL_ttf.h>

struct MouseState {
   int x, y;
   bool leftButton;
} extern mouseState;


namespace sdl {


   /**
    * creates a text in the middle of the sceen at the height given
    * @param writing the text to display
    * @param r,g,b the rgb values of the text
    * @param x,y the screen coordinates to place the text
    * @param renderer the renderer
    */
   void quick_text(std::string writing, Uint8 r, Uint8 g, Uint8 b, int x, int y, SDL_Renderer *renderer, TTF_Font *font);


   /**
    * creates a blinking text in the middle of the screen at the height given that displays the text and then the variable
    * @param writing the text to display
    * @param var the variable to display
    * @param r,g,b the rgb values of the text
    * @param y the height to place the text in screen coordinates
    * @param renderer the renderer
    */
   void v_quick_text(std::string writing, int var, Uint8 r, Uint8 g, Uint8 b, int y, SDL_Renderer *renderer, TTF_Font *font);

   /**
    * creates a button
    * @param writing the text to display
    * @param x,y the screen coordinates of the top left corner of the button
    * @param width,height the witdth and height of the button
    * @param r,g,b the rgb values of the button
    * @param renderer the renderer
    * @return true if the button is pressed, false if not
    */
   bool button(std::string text, int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, SDL_Renderer *renderer, TTF_Font *font);
} // namespace sdl

// updates the mouse's x,y and leftbutton state
void mouse_update();