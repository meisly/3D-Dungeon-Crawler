#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"

class Controller {
 public:
  void HandleInput(bool &running, Player &snake, Uint32 duration) const;
  void SetMap(Map &map);

 private:
  
  Map* map;
  void ChangeDirectionCW(Player &snake, Uint32 duration ) const;
  void ChangeDirectionCCW(Player &snake, Uint32 duration ) const;

  void MoveForward(Player &snake, Uint32 duration) const;
  void MoveBackward(Player &snake, Uint32 duration) const;

};

#endif