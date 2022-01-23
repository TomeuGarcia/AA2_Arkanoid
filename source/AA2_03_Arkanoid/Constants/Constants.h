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
const Vector2D<float> ROTATED_BRICK_DESTINATION_SIZE(BRICK_DESTINATION_HEIGHT, BRICK_DESTINATION_WIDTH);
const Vector2D<float> OFFSET((SCREEN_WIDTH / 2) - (BRICK_DESTINATION_HEIGHT * (ROWS / 2)), BRICK_SOURCE_WIDTH);

const int NORMAL_BRICK_LIVES{ 1 };
const int NORMAL_BRICK_SOURCE_WIDTH_GAP{ BRICK_SOURCE_WIDTH * 2 };
const Vector2D<int> NORMAL_BRICK_SOURCE_START(0, 0);

const int HEAVY_BRICK_LIVES{ 3 };
const int HEAVY_BRICK_SOURCE_WIDTH_GAP{ BRICK_SOURCE_WIDTH };
const Vector2D<int> HEAVY_BRICK_SOURCE_START(0, 20);

const int FIX_BRICK_SOURCE_WIDTH_GAP{ BRICK_SOURCE_WIDTH };
const Vector2D<int> FIX_BRICK_SOURCE_START(0, 40);
const int FIX_BRICK_SOURCE_TOTAL_WIDTH{ FIX_BRICK_SOURCE_WIDTH_GAP * 5 };

const int TOTAL_BRICK_FRAMES{ 5 };

// Platform
const int PLATFORM_SOURCE_WIDTH{ 60 };
const int PLATFORM_SOURCE_HEIGHT{ 20 };
const Vector2D<int> PLATFORM_SOURCE_SIZE(PLATFORM_SOURCE_WIDTH, PLATFORM_SOURCE_HEIGHT);
const int PLATFORM_DESTINATION_WIDTH{ 60 };
const int PLATFORM_DESTINATION_HEIGHT{ 20 };
const Vector2D<int> PLATFORM_DESTINATION_SIZE(PLATFORM_DESTINATION_WIDTH, PLATFORM_DESTINATION_HEIGHT);
const Vector2D<float> PLATFORM_1_START_POSITION(16, SCREEN_HEIGHT/2 - PLATFORM_DESTINATION_WIDTH);
const Vector2D<float> PLATFORM_2_START_POSITION(720, SCREEN_HEIGHT/2 - PLATFORM_DESTINATION_WIDTH);


// Ball
const int BALL_SOURCE_WIDTH{ 186 };
const int BALL_SOURCE_HEIGHT{ 185 };
const Vector2D<int> BALL_SOURCE_SIZE(BALL_SOURCE_WIDTH, BALL_SOURCE_HEIGHT);
const int BALL_DESTINATION_WIDTH{ 20 };
const int BALL_DESTINATION_HEIGHT{ 20 };
const Vector2D<int> BALL_DESTINATION_SIZE(BALL_DESTINATION_WIDTH, BALL_DESTINATION_HEIGHT);

// PowerUp
const int POWERUP_SOURCE_WIDTH{ 20 };
const int POWERUP_SOURCE_HEIGHT{ 20 };
const Vector2D<int> POWERUP_SOURCE_SIZE(POWERUP_SOURCE_WIDTH, POWERUP_SOURCE_HEIGHT);
const Vector2D<int> POWERUP_MINI_SOURCE_START(0, 0);
const Vector2D<int> POWERUP_EXTRA_SOURCE_START(20, 0);
const int POWERUP_DESTINATION_WIDTH{ 20 };
const int POWERUP_DESTINATION_HEIGHT{ 20 };
const Vector2D<int> POWERUP_DESTINATION_SIZE(POWERUP_DESTINATION_WIDTH, POWERUP_DESTINATION_HEIGHT);



// SCENES
// Splash Screen
const float SPLASH_WAIT_TIME{ 3.0f };