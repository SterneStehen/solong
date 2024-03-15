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

int main(int argc, char **argv) 
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    t_complete game;
    ft_read_data_to_struct(&game, argv[1]);
	ft_audit_map(&game);
	game.size = 40;
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * game.size),
			(game.heightmap * game.size), "solong");
	ft_add_images(&game);
	place_elements_in_game(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
    printf("targetcount = %d\n", game.targetcount);
	printf("exitcount = %d\n", game.exitcount);
	printf("playercount = %d\n", game.playercount);
	for (int i = 0; i < game.heightmap; i++) 
	{
        printf("result[%d] = %s\n", i, game.map[i]);
    }
	exit_cleanup(&game, "Exit-all");

    return 0;
}
