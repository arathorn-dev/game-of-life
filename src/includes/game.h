#ifndef __GOL_GAME_H__
#define __GOL_GAME_H__

#include "config.h"

struct Game {
  int32_t width;
  int32_t height;
};

#if defined(_cplusplus)
extern "C" {
#endif

GOL struct Game *game_init(void);
GOL void game_run(const struct Game *const game);
GOL void game_delete(struct Game **ptr);

#if defined(_cplusplus)
}
#endif

#endif // __GOL_GAME_H__
