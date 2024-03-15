/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:16 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/15 16:19:16 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_target(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->target, width * 40, height * 40);
	game->target++;
}

void	images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"img/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer,
			"img/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"img/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"img/exit.xpm", &i, &j);
	game->target = mlx_xpm_file_to_image(game->mlxpointer,
			"img/target.xpm", &i, &j);
}
void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->target = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->wall, width * 40, height * 40);
			if (game->map[height][width] == 'C')
				place_target(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->exit, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->floor, width * 40, height * 40);
			width++;
		}
		height++;
	}
}
