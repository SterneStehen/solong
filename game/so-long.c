/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so-long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:00 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/15 16:19:00 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	
	t_complete	*game;
	game = create_complete_struct();

	if (!game)
	{
		ft_putstr("Error\nFailed to allocate memory for game structure\n");
		return (EXIT_FAILURE);
	}

	if (argc != 2)
	{
		ft_putstr("Error\nInvalid number of arguments\n");
		free(game); // Освободить память перед выходом, если есть только один аргумент
		return (EXIT_FAILURE);
	}
	//game.size = 48;
	ft_read_data_to_struct(game, argv[1]);
	if (ft_audit_map(game) != 0) // Убедитесь, что ft_audit_map возвращает 0 в случае успеха и 1 при ошибке
	{
		exit_cleanup(game, NULL); // Успешное завершение игры
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
