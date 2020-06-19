#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "player.h"
#include "map.h"

class Game {
 public:
  Game(const std::size_t screen_width, const std::size_t screen_height, std::size_t grid_width, std::size_t grid_height);
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);



 private:
  Player player;
  Map map;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  int max_depth{32};
  void Update();
};

#endif