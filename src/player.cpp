#include "player.h"
#include <cmath>
#include <iostream>



void Player::Update() {

  UpdatePosition();
  SDL_Point current_cell{
      static_cast<int>(player_x),
      static_cast<int>(player_y)};  // Capture the head's cell after updating.

}

void Player::UpdatePosition() {
    // Wrap the Snake around to the beginning if going off of the screen.
  if(player_x > map_width)
    player_x = map_width;
  if(player_x < 0)
    player_x = 0;
  if(player_y > map_height)
    player_y = map_height;
  if(player_y < 0)
    player_y = 0;
}
void Player::UpdateView() {

}


