/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so-long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:00 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/21 04:19:21 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_complete	*create_complete_struct(void)
{
	t_complete	*game;

	game = (t_complete *)malloc(sizeof(t_complete));
	if (!game)
	{
		return (NULL);
	}
	game->size = 48;
	game->target = 0;
	game->map = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->target = NULL;
	game->mlxpointer = NULL;
	game->winpointer = NULL;
	return (game);
}

int	main(int argc, char **argv)
{
	t_complete	*game;

	game = create_complete_struct();
	if (argc != 2)
	{
		exit_cleanup(game, "Error\nInvalid number of arguments\n");
	}
	ft_read_data_to_struct(game, argv[1]);
	if (ft_audit_map(game) != 0)
	{
		exit_cleanup(game, NULL);
		return (EXIT_SUCCESS);
	}
	game->mlxpointer = mlx_init();
	game->winpointer = mlx_new_window(game->mlxpointer,
			(game->widthmap * game->size),
			(game->heightmap * game->size), "solong");
	ft_add_images(game);
	place_elements_in_game(game);
	mlx_key_hook(game->winpointer, put_controls, game);
	mlx_hook(game->winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game->mlxpointer);
	exit_cleanup(game, "Exit-all");
	return (0);
}
