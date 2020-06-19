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
I got the idea from this from a video by [Javidx9](https://www.github.com/onelonecoder) where he developed a simple first person shooter that renders/plays in the command line.  I learned about ray casting from that video and used his ray casting [code from that project](https://github.com/OneLoneCoder/CommandLineFPS) as a starting place for this.  Additionally, I used the CPPND-Snake as an example for creating the game loop and file structure. 

## Author
Tierra Farris


# Assignment Info

## Optional Criteria 

## Loops, Functions, I/O
|  CRITERIA 	| MEETS SPECIFICATIONS  	|   LOCATION/EXAMPLE	|
|---	        |---	                    |---	                |
|The project demonstrates an understanding of C++ functions and control structures.   |A variety of control structures are used in the project. |The best example of this is in the Controller::HandleInput function. | 
| 	          |The project code is clearly organized into functions.|Yes|
|The project reads data from a file and process the data, or the program writes data to a file.| The project reads data from an external file or writes data to a file as part of the necessary operation of the program.|The game map is read from a file|
|The project accepts user input and processes the input.|The project accepts input from a user as part of the necessary operation of the program.|Player movement is based on user input|

## Object Oriented Programming
|  CRITERIA 	| MEETS SPECIFICATIONS  	|   LOCATION/EXAMPLE	|
|---	|---	|---	|
|  The project uses Object Oriented Programming techniques.	|  The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. 	|   Yes, this project consists of multiple classes which use methods to perform tasks.	|
|   Classes use appropriate access specifiers for class members.	|   All class data members are explicitly specified as public, protected, or private.	|   Yes	|
|  Class constructors utilize member initialization lists. 	|  All class members that are set to argument values are initialized through member initialization lists. 	|  Yes, good examples of this include the player instance, map instance and game instance initialization.  	|
|Classes encapsulate behavior.|Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.| Yes, the map class is a good example of this|


## Memory Management

|  CRITERIA 	| MEETS SPECIFICATIONS  	|   LOCATION/EXAMPLE	|
|---	|---	|---	|
|   The project makes use of references in function declarations.	|   	At least two variables are defined as references, or two functions use pass-by-reference in the project code.| Yes, functions use pass-by-reference in the game and controller classes.   	|
|   The project uses destructors appropriately.	|  At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor. 	|   Yes, the best example of this is in the renderer class.	|
|   The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.	|  The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction. 	|   Yes	|












