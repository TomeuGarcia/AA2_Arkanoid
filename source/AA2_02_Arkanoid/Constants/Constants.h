#pragma once
#include "../Physics/Vector2D.h"
#include "SDL.h"

// Screen
const int SCREEN_WIDTH{ 800 };
const int SCREEN_HEIGHT{ 600 };
const Vector2D<int> SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);

// Game
const int ROWS{ 12 };
const int COLUMNS{ 11 };


// Brick
const int BRICK_SOURCE_WIDTH{ 40 };
const int BRICK_SOURCE_HEIGHT{ 20 };
const Vector2D<int> BRICK_SOURCE_SIZE(BRICK_SOURCE_WIDTH, BRICK_SOURCE_HEIGHT);

const int BRICK_DESTINATION_WIDTH{ 36 };
const int BRICK_DESTINATION_HEIGHT{ 18 };
const Vector2D<int> BRICK_DESTINATION_SIZE(BRICK_DESTINATION_WIDTH, BRICK_DESTINATION_HEIGHT);
const Vector2D<int> ROTATED_BRICK_DESTINATION_SIZE(BRICK_DESTINATION_HEIGHT, BRICK_DESTINATION_WIDTH);
const Vector2D<int> OFFSET((SCREEN_WIDTH / 2) - (BRICK_DESTINATION_HEIGHT * (ROWS / 2)), BRICK_SOURCE_WIDTH);

const int NORMAL_BRICK_LIVES{ 3 };
const int NORMAL_BRICK_SOURCE_WIDTH_GAP{ BRICK_SOURCE_WIDTH * 2 };
const Vector2D<int> NORMAL_BRICK_SOURCE_START(0, 0);

const int HEAVY_BRICK_LIVES{ 5 };
const int HEAVY_BRICK_SOURCE_WIDTH_GAP{ BRICK_SOURCE_WIDTH };
const Vector2D<int> HEAVY_BRICK_SOURCE_START(0, 20);

const int FIX_BRICK_SOURCE_WIDTH_GAP{ BRICK_SOURCE_WIDTH };
const Vector2D<int> FIX_BRICK_SOURCE_START(0, 40);
const int FIX_BRICK_SOURCE_TOTAL_WIDTH{ FIX_BRICK_SOURCE_WIDTH_GAP * 5 };


// Platform
const int PLATFORM_SOURCE_WIDTH{ 60 };
const int PLATFORM_SOURCE_HEIGHT{ 20 };
const Vector2D<int> PLATFORM_SOURCE_SIZE(PLATFORM_SOURCE_WIDTH, PLATFORM_SOURCE_HEIGHT);
const int PLATFORM_DESTINATION_WIDTH{ 60 };
const int PLATFORM_DESTINATION_HEIGHT{ 20 };
const Vector2D<int> PLATFORM_DESTINATION_SIZE(PLATFORM_SOURCE_WIDTH, PLATFORM_SOURCE_HEIGHT);
const Vector2D<int> PLATFORM_1_START_POSITION(20, SCREEN_HEIGHT - PLATFORM_SOURCE_WIDTH);
const Vector2D<int> PLATFORM_2_START_POSITION(720, SCREEN_HEIGHT - PLATFORM_SOURCE_WIDTH);

// Ball
const int BALL_SOURCE_WIDTH{ 186 };
const int BALL_SOURCE_HEIGHT{ 185 };
const Vector2D<int> BALL_SOURCE_SIZE(BALL_SOURCE_WIDTH, BALL_SOURCE_HEIGHT);
const int BALL_DESTINATION_WIDTH{ 20 };
const int BALL_DESTINATION_HEIGHT{ 20 };
const Vector2D<int> BALL_DESTINATION_SIZE(BALL_DESTINATION_WIDTH, BALL_DESTINATION_HEIGHT);

// Walls
//SDL_Rect UPPER_WALL_COLLIDER{ 10, 10,  780, 25 };
//SDL_Rect LOWER_WALL_COLLIDER{ 10, 575,  780, 25 };
//SDL_Rect LEFT_WALL_COLLIDER{ 10, 25,  20, 550 };
//SDL_Rect RIGHT_WALL_COLLIDER{ 780, 25,  20, 550 };




// SCENES
// Splash Screen
const float SPLASH_WAIT_TIME{ 3.0f };