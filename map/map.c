#include "so_long.h"

int get_line_length(const char *line) 
{
    return strlen(line);
}

int count_lines(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    int count = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file) != NULL) 
	{
        count++;
    }

    fclose(file);
    return count;
}

void read_data_to_struct(t_complete *game, char *filename)
{
    game->fd = open(filename, O_RDONLY);
    if (game->fd < 0) return;
    game->heightmap = count_lines(filename);
    close(game->fd);
    game->fd = open(filename, O_RDONLY);
    if (game->fd < 0) return;

    game->map = (char **)malloc(sizeof(char *) * game->heightmap);
    if (game->map == NULL) return; 

    for (int i = 0; i < game->heightmap; i++) {
        char *line = get_next_line(game->fd);
        if (line) {
            game->map[i] = ft_strdup(line);
            if (game->map[i] == NULL) 
			{
                while (i-- > 0) 
				{
					free(game->map[i]);
				}
                free(game->map);
                game->map = NULL;
                close(game->fd);
                return;
            }
            free(line);
        }
    }
    close(game->fd);
}
