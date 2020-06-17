#include "renderer.h"
#include <iostream>
#include <string>
#include <algorithm>




Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(wchar_t *screen) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;  
  // block.w = 1;
  // block.h = 1;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
  
  for(size_t i = 0; i < grid_height*grid_width; i++){
    int x = (int)i % grid_width;
    int y = (int)floor(i/grid_width);
    SDL_Color color;
    if(screen[i] == '#'){
      color.r = 0x22;
      color.g = 0x8B;
      color.b = 0x22;
      color.a = 0xFF;
    }
    if(screen[i] == 'b'){
      color.r = 0x87;
      color.g = 0xCE;
      color.b = 0xEB;
      color.a = 0xFF;
    }
    if(screen[i] == '.'){
      color.r = 0x00;
      color.g = 0x80;
      color.b = 0x00;
      color.a = 0xFF;
    }
    if(screen[i] == '-'){
      color.r = 0x00;
      color.g = 0x64;
      color.b = 0x00;
      color.a = 0xFF;
    }
    if(screen[i] == ' '){
      color.r = 0x00;
      color.g = 0x00;
      color.b = 0x00;
      color.a = 0xFF;
    }
    if(screen[i] == 0x2588){  //dark grey walls
      color.r = 0x80;  
      color.g = 0x80;
      color.b = 0x80;
      color.a = 0xFF;
    }
    if(screen[i] == 0x2593){
      color.r = 0xa9;
      color.g = 0xa9;
      color.b = 0xa9;
      color.a = 0xFF;
    }
    if(screen[i] == 0x2592){
      color.r = 0xC0;
      color.g = 0xC0;
      color.b = 0xC0;
      color.a = 0xFF;
    }
    if(screen[i] == 0x2591){
      color.r = 0xDC;
      color.g = 0xDC;
      color.b = 0xDC;
      color.a = 0xFF;
    }
    SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
    block.x = x * block.w;
    block.y = y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }
// End Render Player View

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps, Player player) {
  std::string title{" FPS: " + std::to_string(fps) + "  X: " + std::to_string((int)player.player_x) + "  Y: " + std::to_string((int)player.player_y) + "  Angle: " + std::to_string((int)player.direction)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
