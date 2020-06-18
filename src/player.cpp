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
  player_x = fmod(player_x + grid_width, grid_width);
			
  player_y = fmod(player_y + grid_height, grid_height);
}
void Player::UpdateView() {

}


