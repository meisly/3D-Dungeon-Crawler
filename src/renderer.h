#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
// #include "SDL_image.h"
#include "player.h"
#include "map.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render( Tiles *screen, Map *map, Player *player);
  void UpdateWindowTitle(int fps, Player player);
  
 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Texture* _grass;
  SDL_Texture* _wall;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  
};

#endif