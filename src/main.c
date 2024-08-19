#include "includes/game.h"

int main(void) {

  struct Game *game = game_init();
  game_run(game);
  game_delete(&game);

  return 0;
}
