#ifndef __GOL_SCREEN_H__
#define __GOL_SCREEN_H__

#include "config.h"

enum ScreenType { SCREEN_MENU = 0, SCREEN_OPTION, SCREEN_LEVEL_0 };

struct Screen {
  enum ScreenType type;
};

#if defined(__cplusplus)
extern "C" {
#endif

GOL struct Screen *menu_screen_create(void);
GOL void menu_screen_update(struct Screen *const screen);
GOL void menu_screen_render(const struct Screen *const screen);
GOL void menu_screen_destroy(struct Screen **ptr);

#if defined(__cplusplus)
}
#endif

#endif //__GOL_SCREEN_H__
