#include "includes/game.h"
#include "includes/config.h"
#include "includes/raylib.h"

//----------------------------------------------------------------------------------
// Define private variables & functions
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Implement public functions
//----------------------------------------------------------------------------------

GOF struct Game *game_init(void) {
  InitWindow(GOL_SCREEN_WIDTH, GOL_SCREEN_HEIGHT, GOL_SCREEN_TITLE);

  struct Game *game = MemAlloc(sizeof(struct Game));
  if (!game) {
    TraceLog(LOG_ERROR, "struct Game * doesn't initialize");
    return NULL;
  }

  SetTargetFPS(GOL_FPS);

  return game;
}

GOF void game_run(const struct Game *const game) {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GOL_BACKGROUND);
    EndDrawing();
  }
}

GOF void game_delete(struct Game **ptr) {
  if (ptr) {
    CloseWindow();
    MemFree(*ptr);
    (*ptr) = NULL;
  }
}

//----------------------------------------------------------------------------------
// Implement private variables & functions
//----------------------------------------------------------------------------------
