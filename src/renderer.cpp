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
      grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  // Create textures
  // SDL_Texture *grass = IMG_LoadTexture(renderer, "/home/workspace/3D-Dungeon-Crawler/src/textures/grass20.png");
  // SDL_Texture *wall = IMG_LoadTexture(renderer, "/home/workspace/3D-Dungeon-Crawler/src/textures/stone wall 7.png");
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Tiles *screen)
{
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  for (size_t i = 0; i < grid_height * grid_width; i++)
  {
    int x = (int)(i % grid_width);
    int y = (int)floor(i / grid_width);
    SDL_Color color;
    Tiles currentTile = screen[i];
    
    switch (currentTile)
    {
    case wall1:
      color.r = 0xf2;
      color.g = 0xf2;
      color.b = 0xf2;
      color.a = 0xFF;
      break;
    case wall2:
      color.r = 0xd8;
      color.g = 0xd8;
      color.b = 0xd8;
      color.a = 0xFF;
      break;
    case wall3:
      color.r = 0xb2;
      color.g = 0xb2;
      color.b = 0xb2;
      color.a = 0xFF;
      break;
    case wall4:
      color.r = 0x66;
      color.g = 0x66;
      color.b = 0x66;
      color.a = 0xFF;
      break;
    case ceil1:
      color.r = 0x87;
      color.g = 0xCE;
      color.b = 0xEB;
      color.a = 0xFF;
      break;
    case ceil2:
      color.r = 0x66;
      color.g = 0x66;
      color.b = 0x66;
      color.a = 0xFF;
      break;
    case ground1:
      color.r = 0x14;
      color.g = 0x94;
      color.b = 0x14;
      color.a = 0xFF;
      break;
    case ground2:
      color.r = 0x0e;
      color.g = 0x6b;
      color.b = 0x0e;
      color.a = 0xFF;
      break;
    case ground3:
      color.r = 0x64;
      color.g = 0x95;
      color.b = 0x68;
      color.a = 0xFF;
      break;
    case ground4:
      color.r = 0x2b;
      color.g = 0x53;
      color.b = 0x29;
      color.a = 0xFF;
      break;
    case black:
      color.r = 0x00;
      color.g = 0x00;
      color.b = 0x00;
      color.a = 0xFF;
      break;
    }

    block.x = x * block.w;
    block.y = y * block.h;

    if (1 == 2)
    {
      SDL_RenderCopy(sdl_renderer, _wall, NULL, &block);
    }else
    {
      SDL_SetRenderDrawColor(sdl_renderer, color.r, color.g, color.b, color.a);
      SDL_RenderFillRect(sdl_renderer, &block);
    }


  }
  // End Render Player View

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps, Player player)
{
  std::string title{" FPS: " + std::to_string(fps) + "  X: " + std::to_string((int)player.player_x) + "  Y: " + std::to_string((int)player.player_y) + "  Angle: " + std::to_string((int)player.direction)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
