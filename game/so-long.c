#include "so_long.h"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    t_complete game;
    read_data_to_struct(&game, argv[1]);

    // Демонстрация работы с map
    for (int i = 0; i < game.heightmap; i++) {
        printf("result[%d] = %s\n", i, game.map[i]);
    }

    // Освобождение выделенной памяти
    for (int i = 0; i < game.heightmap; i++) {
        free(game.map[i]);
    }
    free(game.map);
	//free(game.exit);

    return 0;
}
