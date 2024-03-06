#include "so_long.h"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    t_complete game;
    ft_read_data_to_struct(&game, argv[1]);
	ft_audit_map(&game);

    for (int i = 0; i < game.heightmap; i++) {
        printf("result[%d] = %s\n", i, game.map[i]);
    }

    for (int i = 0; i < game.heightmap; i++) {
        free(game.map[i]);
    }
    free(game.map);

    return 0;
}
