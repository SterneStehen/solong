#include "so_long.h"

int get_line_length(const char *line) 
{
    return strlen(line);
}

int ft_count_lines(const char *filename) 
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

void ft_read_data_to_struct(t_complete *game, char *filename)
{
    int i;
	i = 0;
	game->fd = open(filename, O_RDONLY);
    if (game->fd < 0)
		return;
    game->heightmap = ft_count_lines(filename);
    close(game->fd);
    game->fd = open(filename, O_RDONLY);
    if (game->fd < 0) 
		return;

    game->map = (char **)malloc(sizeof(char *) * game->heightmap);
    if (game->map == NULL) 
		return; 

    while (i < game->heightmap) 
	{
        char *line = get_next_line(game->fd);
        if (line) 
		{
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
		i++;
    }
    close(game->fd);
}
