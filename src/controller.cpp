#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "player.h"

void Controller::SetMap(Map &m){
  map = &m;
}
void Controller::ChangeDirectionCW(Player &player, Uint32 duration) const {
  player.direction += (player.speed * 0.1f) * duration;
  return;
}
void Controller::ChangeDirectionCCW(Player &player, Uint32 duration) const {
  player.direction -= (player.speed * 0.1f) * duration;
  return;
}
void Controller::MoveForward(Player &player, Uint32 duration) const {
  player.player_x += sinf(player.direction) * player.speed * duration; 
	player.player_y += cosf(player.direction) * player.speed * duration;
  if (map->getString().c_str()[(int)player.player_x * map->getWidth() + (int)player.player_y] == '#')
    {
      player.player_x -= sinf(player.direction) * player.speed * duration;
      player.player_y -= cosf(player.direction) * player.speed * duration;
    }	
  return;
}
void Controller::MoveBackward(Player &player, Uint32 duration) const {
  player.player_x -= sinf(player.direction) * player.speed * duration;
	player.player_y -= cosf(player.direction) * player.speed * duration;
	if (map->getString().c_str()[(int)player.player_x * map->getWidth() + (int)player.player_y] == '#')
  {
    player.player_x += sinf(player.direction) * player.speed * duration;
    player.player_y += cosf(player.direction) * player.speed * duration;
  }	
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