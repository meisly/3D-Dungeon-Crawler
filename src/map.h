#ifndef MAP_H
#define MAP_H

#include <vector>
#include <stdio.h>
#include "SDL.h"
#include <iostream>

enum Tiles { ground1, ground2, ground3, ground4, wall1, wall2, wall3, wall4, ceil1, ceil2, black};

class Map
{
public:
    Map(int width, int height);
    Tiles tiles;

    void Update();
    int getWidth();
    int getHeight();
    std::string getString();

private:
    std::string _string;
    int _width;
    int _height;
    void readMapFromFile(std::string file);
};

#endif