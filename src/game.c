#include "includes/game.h"
#include "includes/config.h"
#include "includes/raylib.h"

//----------------------------------------------------------------------------------
// Define private variables & functions
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Implement public functions
//----------------------------------------------------------------------------------

GOL struct Game *game_init(void) {

#if defined(GOL_DEBUG)
  SetTraceLogLevel(LOG_DEBUG);
#endif

  InitWindow(GOL_SCREEN_WIDTH, GOL_SCREEN_HEIGHT, GOL_SCREEN_TITLE);

  struct Game *game = MemAlloc(sizeof(struct Game));
  if (!game) {
    TraceLog(LOG_ERROR, "struct Game * doesn't initialize");
    return NULL;
  }

  SetTargetFPS(GOL_FPS);
#if defined(GOL_DEBUG)
  TraceLog(LOG_DEBUG, "struct Game * created");
#endif

  return game;
}

GOL void game_run(const struct Game *const game) {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GOL_BACKGROUND);
    EndDrawing();
  }
}

GOL void game_delete(struct Game **ptr) {
  if (ptr) {
    CloseWindow();
    MemFree(*ptr);
    (*ptr) = NULL;
    ptr = NULL;
#if defined(GOL_DEBUG)
    TraceLog(LOG_DEBUG, "struct Game * deleted");
#endif
  }
}

//----------------------------------------------------------------------------------
// Implement private variables & functions
//----------------------------------------------------------------------------------
