/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:23 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/21 03:11:22 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_add_images(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer, "img/floor.xpm", &i,
			&j);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer, "img/wall.xpm", &i,
			&j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer, "img/player.xpm", &i,
			&j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer, "img/exit.xpm", &i,
			&j);
	game->target = mlx_xpm_file_to_image(game->mlxpointer, "img/target.xpm", &i,
			&j);
	return (0);
}

void *get_image_for_char(t_complete *game, char map_char)
{
    if (map_char == '1') 
        return game->wall;
    else if (map_char == 'E')
        return game->exit;
    else if (map_char == '0')
        return game->floor;
    else if (map_char == 'C')
	{
        game->targetcount++;
        return game->target;
    }
	else if (map_char == 'P')
	    return game->player;
    return NULL;
}

// The main function simplified to meet the new structure.
void place_elements_in_game(t_complete *game) {
    for (int height = 0; height < game->heightmap; height++) {
        for (int width = 0; game->map[height][width]; width++) {
            // Set the current position before calling.
            game->x_axis = width;
            game->y_axis = height;
            
            void *image_to_place = get_image_for_char(game, game->map[height][width]);
            if (image_to_place != NULL) {
                mlx_put_image_to_window(game->mlxpointer, game->winpointer, image_to_place, width * game->size, height * game->size);
            }
        }
    }
}
