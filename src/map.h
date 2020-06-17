#ifndef MAP_H
#define MAP_H

#include <vector>
#include <stdio.h>
#include "SDL.h"
#include <iostream>


class Map {
 public:
  enum tiles;
  Map(int width, int height);

  void Update();
  std::wstring _string;
  int _width;
  int _height;
 private:
  void readMapFromFile(std::string file);

};

#endif