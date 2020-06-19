# 3D Dungeon Crawler
Walk around in this 3-D world explorer.  You can see your characters position in the small, on screen map in the upper left corner.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./DungeonCrawler`.

## Explore

Walk around the world and explore using keyboard controls.
#### Controls
You can move around the world using the keyboard.  
  * Forward = `Up arrow` or `W`
  * Backward = `Down arrow` or `S`
  * Turn Right = `Right arrow` or `D`
  * Turn Left = `Left arrow` or `A`

## Future Modifications
 1. Add more interesting world features like trees and boulders
 2. Add some sprites
 3. Turn this into an actual game?


## Credit
I got the idea from this from a video by [Javidx9](https://www.github.com/onelonecoder) where he developed a simple first person shooter that renders/plays in the command line.  I learned about ray casting from that video and used his ray casting [code from that project](https://github.com/OneLoneCoder/CommandLineFPS) as a starting place for this.

## Author
Tierra Farris
