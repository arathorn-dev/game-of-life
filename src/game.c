#include "includes/game.h"
#include "includes/config.h"
#include "includes/raylib.h"
#include "includes/screen.h"
#include <stdint.h>

//----------------------------------------------------------------------------------
// Define private variables & functions
//----------------------------------------------------------------------------------

#if defined(__cplusplus)
extern "C" {
#endif

GOL void current_screen_update(struct Screen *const screen);
GOL void current_screen_render(const struct Screen *const screen);
GOL void current_screen_destroy(struct Screen **ptr);

#if defined(__cplusplus)
}
#endif

//----------------------------------------------------------------------------------
// Implement public functions
//----------------------------------------------------------------------------------

GOL struct Game *game_init(void) {
  struct Game *game = MemAlloc(sizeof(struct Game));
  if (!game) {
    TraceLog(LOG_ERROR, "struct Game * doesn't initialize");
    return NULL;
  }

#if defined(GOL_DEBUG)
  SetTraceLogLevel(LOG_DEBUG);
#endif

  InitWindow(GOL_SCREEN_WIDTH, GOL_SCREEN_HEIGHT, GOL_SCREEN_TITLE);
  SetTargetFPS(GOL_FPS);

  game->screen_index = 0;
  game->screens[0] = menu_screen_create();

#if defined(GOL_DEBUG)
  TraceLog(LOG_DEBUG, "struct Game * created");
#endif

  return game;
}

GOL void game_run(const struct Game *const game) {

  while (!WindowShouldClose()) {
    const int8_t index = game->screen_index;
    current_screen_update(game->screens[index]);

    BeginDrawing();
    current_screen_render(game->screens[index]);
    EndDrawing();
  }
}

GOL void game_delete(struct Game **ptr) {
  if (ptr) {
    CloseWindow();
    const int8_t index = (*ptr)->screen_index;
    current_screen_destroy(&((*ptr)->screens[index]));
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
GOL void current_screen_update(struct Screen *const screen) {
  switch (screen->type) {
  case SCREEN_MENU:
    menu_screen_update(screen);
  default: {
  }
  }
}

GOL void current_screen_render(const struct Screen *const screen) {
  switch (screen->type) {
  case SCREEN_MENU:
    menu_screen_render(screen);
  default: {
  }
  }
}

GOL void current_screen_destroy(struct Screen **ptr) {
  switch ((*ptr)->type) {
  case SCREEN_MENU:
    menu_screen_destroy(ptr);
  default: {
  }
  }
}
