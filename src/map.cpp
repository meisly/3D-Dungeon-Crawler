#include "map.h"
#include <cmath>
#include <iostream>
#include <fstream>

Map::Map(int width, int height) : _width(width), _height(height)
{
  readMapFromFile("/home/workspace/3D-Dungeon-Crawler/src/maps/map1.txt");
}

int Map::getWidth()
{
  return _width;
}

int Map::getHeight()
{
  return _height;
}

std::string Map::getString()
{
  return _string;
}

void Map::readMapFromFile(std::string filepath)
{
  _string = "";
  std::ifstream my_file;
  my_file.open(filepath);
  if (my_file)
  {
    std::string line;
    while (getline(my_file, line))
    {
      _string += line;
    }
    my_file.close();
  }
  else
  {
    std::cout << "file not opened\n";
  }
}