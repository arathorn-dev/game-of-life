#include "../includes/raylib.h"
#include "../includes/screen.h"

//----------------------------------------------------------------------------------
// Define private variables & functions
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Implement public functions
//----------------------------------------------------------------------------------

GOL struct Screen *main_screen_create(void) {
  struct Screen *main = MemAlloc(sizeof(struct Screen));
  if (!main) {
    TraceLog(LOG_ERROR, "[Main] struct Struct * doesn't initialize");
    return NULL;
  }

#if defined(GOL_DEBUG)
  TraceLog(LOG_DEBUG, "[Main] struct Screen * created");
#endif
  main->type = SCREEN_MAIN;

  return main;
}

GOL void main_screen_update(struct Screen *const screen) {
  // TODO
}

GOL void main_screen_render(const struct Screen *const screen) {
  ClearBackground(BLUE);
}

GOL void main_screen_destroy(struct Screen **ptr) {
  if (*ptr) {
    MemFree((*ptr));
    *ptr = NULL;
    ptr = NULL;

#if defined(GOL_DEBUG)
    TraceLog(LOG_DEBUG, "[Main] struct Screen * destroy");
#endif
  }
}

//----------------------------------------------------------------------------------
// Implement private variables & functions
//----------------------------------------------------------------------------------
