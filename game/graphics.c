/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:23 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/15 16:19:23 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_add_images(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer, "img/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer, "img/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer, "img/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer, "img/exit.xpm", &i, &j);
	game->target = mlx_xpm_file_to_image(game->mlxpointer, "img/target.xpm", &i, &j);
	return (0);
}

void	place_elements_in_game(t_complete *game)
{
    int	height;
    int	width;

    game->targetcount = 0;
    height = 0;
    while (height < game->heightmap)
    {
        width = 0;
        while (game->map[height][width])
        {
            void *image_to_place = NULL;
            if (game->map[height][width] == '1')
                image_to_place = game->wall;
            else if (game->map[height][width] == 'E')
                image_to_place = game->exit; 
            else if (game->map[height][width] == '0')
                image_to_place = game->floor;
			 else if (game->map[height][width] == 'C')
			{
                image_to_place = game->target;
                game->targetcount++;
			}
            else if (game->map[height][width] == 'P')
            {
                image_to_place = game->player;
                game->x_axis = width;
                game->y_axis = height;
            }
            if (image_to_place != NULL)
                mlx_put_image_to_window(game->mlxpointer, game->winpointer, image_to_place, width * game->size, height * game->size);
            width++;
        }
        height++;
    }
}