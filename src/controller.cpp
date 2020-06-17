#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "player.h"

void Controller::ChangeDirectionCW(Player &player, Uint32 duration) const {
  player.direction += (player.speed * 0.75f);
  return;
}
void Controller::ChangeDirectionCCW(Player &player, Uint32 duration) const {
  player.direction -= (player.speed * 0.75f);
  return;
}
void Controller::MoveForward(Player &player, Uint32 duration) const {
  player.player_x += sinf(player.direction) * player.speed;
	player.player_y += cosf(player.direction) * player.speed;
  // if (map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#')
  // {
  //   fPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;;
  //   fPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;;
  // }			
  return;
}
void Controller::MoveBackward(Player &player, Uint32 duration) const {
  player.player_x -= sinf(player.direction) * player.speed;
	player.player_y -= cosf(player.direction) * player.speed;
			
  return;
}
void Controller::HandleInput(bool &running, Player &player, Uint32 duration) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_w:
          MoveForward(player, duration);
          break;
          
        case SDLK_UP:
          MoveForward(player, duration);
          break;

        case SDLK_s:
          MoveBackward(player, duration);
          break;

        case SDLK_DOWN:
          MoveBackward(player, duration);
          break;

        case SDLK_a:
          ChangeDirectionCCW(player, duration);
          break;

        case SDLK_d:
          ChangeDirectionCW(player, duration);
          break;
      }
    }
  }
}