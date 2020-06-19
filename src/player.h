#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"
#include "map.h"



class Player {
 public:
  

  Player(int map_width, int map_height)
      : map_width(map_width),
        map_height(map_height),
        player_x(map_width / 2),
        player_y(map_height / 2) {}
  void Update();


  float direction{0.0f};

  float speed{0.01f};
  
  bool alive{true};
  float player_x;
  float player_y;
  float FOV{0.785f};


 private:
  void UpdatePosition();
  void UpdateView();
  int map_width;
  int map_height;
  
};

#endif