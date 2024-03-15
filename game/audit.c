/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:48 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/15 16:19:48 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_cleanup(t_complete *game, char *error_message)
{
    int i;

    if (error_message)
    {
        printf("%s\n", error_message);
    }
	if (game->winpointer)
 		mlx_destroy_window(game->mlxpointer, game->winpointer);
	if (game->mlxpointer)
		free(game->mlxpointer);
    if (game->map)
    {
        for (i = 0; i < game->heightmap; i++)
        {
            if (game->map[i])
            {
                free(game->map[i]);
            }
        }
        free(game->map);
    }

    exit(error_message ? EXIT_FAILURE : EXIT_SUCCESS);
}

int check_walls(t_complete *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (i == 0 || i == game->heightmap - 1)
			{
				if (game->map[i][j] != '1')
				{
					return 0;
				}
			}
			if (j == 0 || j == game->widthmap - 1)
			{
				if (game->map[i][j] != '1')
				{
					return 0;
				}
			}
			j++;
		}
		i++;
	}
	return 1;
}

int check_count_elements(t_complete *game)
{
	int i;
	int j;


	i = 0;
	game->playercount = 0;
	game->exitcount = 0;
	game->targetcount = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (game->map[i][j] == 'P')
			{
				game->playercount++;
			}
			if (game->map[i][j] == 'E')
			{
				game->exitcount++;
			}
			if (game->map[i][j] == 'C')
			{
				game->targetcount++;
			}
			j++;
		}
		i++;
	}
	if (game->playercount != 1 || game->exitcount != 1 || game->targetcount < 1)
	{
		return 0;
	}
	return 1;

}

int check_true_elements(t_complete *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if ((game->map[i][j] == 'P') || (game->map[i][j] == 'E') || (game->map[i][j] == 'C') || (game->map[i][j] == '1') || (game->map[i][j] == '0') || (game->map[i][j] == '\n'))
			{
				j++;
			}
			else
			{
				return 0;
			}
		}
		i++;
	}
	return 1;
}

int ft_audit_map(t_complete *game)
{
    if (!check_walls(game)) 
	{
    	exit_cleanup(game, "Error Wall");
	}
	if (!check_count_elements(game)) 
	{
    	exit_cleanup(game, "Error count Elements");
	}
	if (!check_true_elements(game))
	{
    	exit_cleanup(game, "Error True Elements");
	}
    return 0;
}
