#include "../includes/raylib.h"
#include "../includes/screen.h"

//----------------------------------------------------------------------------------
// Define private variables & functions
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Implement public functions
//----------------------------------------------------------------------------------

GOL struct Screen *menu_screen_create(void) {
  struct Screen *menu = MemAlloc(sizeof(struct Screen));
  if (!menu) {
    TraceLog(LOG_ERROR, "[Menu] struct Struct * doesn't initialize");
    return NULL;
  }

#if defined(GOL_DEBUG)
  TraceLog(LOG_DEBUG, "[Menu] struct Screen * created");
#endif
  menu->type = SCREEN_MENU;

  return menu;
}

GOL void menu_screen_update(struct Screen *const screen) {
  // TODO
}

GOL void menu_screen_render(const struct Screen *const screen) {
  ClearBackground(BLUE);
}

GOL void menu_screen_destroy(struct Screen **ptr) {
  if (*ptr) {
    MemFree((*ptr));
    *ptr = NULL;
    ptr = NULL;

#if defined(GOL_DEBUG)
    TraceLog(LOG_DEBUG, "[Menu] struct Screen * destroy");
#endif
  }
}

//----------------------------------------------------------------------------------
// Implement private variables & functions
//----------------------------------------------------------------------------------
