#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"
#include "map.h"



class Player {
 public:
  

  Player(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        player_x(grid_width / 2),
        player_y(grid_height / 2) {}
  void Update();


  float direction{0.0f};

  float speed{0.1f};
  
  bool alive{true};
  float player_x;
  float player_y;
  float FOV{0.785f};


 private:
  void UpdatePosition();
  void UpdateView();
  int grid_width;
  int grid_height;
  
};

#endif