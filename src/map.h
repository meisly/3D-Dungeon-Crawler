#ifndef MAP_H
#define MAP_H

#include <vector>
#include <stdio.h>
#include "SDL.h"
#include <iostream>

using namespace std;

class Map {
 public:
  Map(int width, int height);

  void Update();
  wstring _string;
  int _width;
  int _height;
 private:
  

};

#endif