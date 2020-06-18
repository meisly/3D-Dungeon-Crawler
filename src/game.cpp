#include "game.h"
#include <iostream>
#include "SDL.h"
#include <vector>
#include <algorithm>

Game::Game(const std::size_t screen_width, const std::size_t screen_height, std::size_t grid_width, std::size_t grid_height)
    : screen_height(screen_height),
      screen_width(screen_width),
      grid_height(grid_height),
      grid_width(grid_width),
      player((int)grid_width, (int)grid_height),
      map((int)grid_width, (int)grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height))
{
}

void Game::Run(Controller &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  int bufWidth = grid_width;
  int bufHeight = grid_height;

  controller.SetMap(map);

  Tiles *screen = new Tiles[bufWidth * bufHeight];

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, player, frame_duration);
    Update();

    // Get Player View

    for (int x = 0; x < bufWidth; x++)
    {
      // For each column, calculate the projected ray angle into world space
      float fRayAngle = (player.direction - player.FOV / 2.0f) + ((float)x / (float)bufWidth) * player.FOV;

      // Find distance to wall
      float fStepSize = 0.1f;       // Increment size for ray casting, decrease to increase
      float fDistanceToWall = 0.0f; //                                      resolution

      bool bHitWall = false;  // Set when ray hits wall block
      bool bBoundary = false; // Set when ray hits boundary between two wall blocks

      float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
      float fEyeY = cosf(fRayAngle);

      // Incrementally cast ray from player, along ray angle, testing for
      // intersection with a block
      while (!bHitWall && fDistanceToWall < max_depth)
      {
        fDistanceToWall += fStepSize;
        int nTestX = (int)(player.player_x + fEyeX * fDistanceToWall);
        int nTestY = (int)(player.player_y + fEyeY * fDistanceToWall);

        // Test if ray is out of bounds
        if (nTestX < 0 || nTestX >= map.getWidth() || nTestY < 0 || nTestY >= map.getHeight())
        {
          bHitWall = true; // Just set distance to maximum depth
          fDistanceToWall = max_depth;
        }
        else
        {
          // Ray is inbounds so test to see if the ray cell is a wall block
          if (map.getString().c_str()[nTestX * map.getWidth() + nTestY] == '#')
          {
            // Ray has hit wall
            bHitWall = true;

            // To highlight tile boundaries, cast a ray from each corner
            // of the tile, to the player. The more coincident this ray
            // is to the rendering ray, the closer we are to a tile
            // boundary, which we'll shade to add detail to the walls
            std::vector<std::pair<float, float>> p;

            // Test each corner of hit tile, storing the distance from
            // the player, and the calculated dot product of the two rays
            for (int tx = 0; tx < 2; tx++)
              for (int ty = 0; ty < 2; ty++)
              {
                // Angle of corner to eye
                float vy = (float)nTestY + ty - player.player_y;
                float vx = (float)nTestX + tx - player.player_x;
                float d = sqrt(vx * vx + vy * vy);
                float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
                p.push_back(std::make_pair(d, dot));
              }

            // Sort Pairs from closest to farthest
            std::sort(p.begin(), p.end(), [](const std::pair<float, float> &left, const std::pair<float, float> &right) { return left.first < right.first; });

            // First two/three are closest (we will never see all four)
            float fBound = 0.001;
            if (acos(p.at(0).second) < fBound)
              bBoundary = true;
            if (acos(p.at(1).second) < fBound)
              bBoundary = true;
            if (acos(p.at(2).second) < fBound)
              bBoundary = true;
          }
        }
      }

      // Calculate distance to ceiling and floor
      int nCeiling = (float)(bufHeight / 2.0) - bufHeight / ((float)fDistanceToWall);
      int nFloor = bufHeight - nCeiling;

      // Shader walls based on distance
      Tiles nShade = black;
      if (fDistanceToWall <= max_depth / 4.0f)
        nShade = wall1; // Very close
      else if (fDistanceToWall < max_depth / 3.0f)
        nShade = wall2;
      else if (fDistanceToWall < max_depth / 2.0f)
        nShade = wall3;
      else if (fDistanceToWall < max_depth)
        nShade = wall4;
      else
        nShade = black; // Too far away

      if (bBoundary)
        nShade = black; // Black it out

      for (int y = 0; y < bufHeight; y++)
      {
        // Each Row
        if (y <= nCeiling)
          screen[y * bufWidth + x] = ceil1;
        else if (y > nCeiling && y <= nFloor)
          screen[y * bufWidth + x] = nShade;
        else // Floor
        {
          // Shade floor
          float b = 1.0f - (((float)y - bufHeight / 2.0f) / ((float)bufHeight / 2.0f));
          if (b < 0.95)
            nShade = ground1;
          // else if (b < 0.8)	nShade = ground2;
          // else if (b < 0.9)	nShade = ground3;
          else if (b < 1.0)
            nShade = ground4;
          else
            nShade = black;
          screen[y * bufWidth + x] = nShade;
        }
      }
    }

    renderer.Render(screen);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count, player);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update()
{
  if (!player.alive)
    return;

  player.Update();

  int new_x = static_cast<int>(player.player_x);
  int new_y = static_cast<int>(player.player_y);
}

int Game::GetScore() const { return score; }
