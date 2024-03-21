/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:31 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/21 03:49:58 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	update_position(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E' && game->targetcount == 0)
	{
		exit_cleanup(game, "You have won the game");
	}
	else if (game->map[j][i] == '0' || game->map[j][i] == 'C')
	{
		if (game->map[j][i] == 'C')
			game->targetcount--;
		game->map[game->y_axis][game->x_axis] = '0';
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
		return (1);
	}
	return (0);
}

static int	process_movement(t_complete *game, int x, int y)
{
	int	i;
	int	j;

	i = game->x_axis + x;
	j = game->y_axis + y;
	if (game->map[j][i] != '1')
	{
		if (!update_position(game, i, j))
			return (0);
	}
	else
		return (0);
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %d\n", game->targetcount);
	return (1);
}

static int	keyboard_w_s(t_complete *game, int movement)
{
	if (movement == 13 || movement == 'w' || movement == 'W')
		return (process_movement(game, 0, -1));
	else if (movement == 1 || movement == 's' || movement == 'S')
		return (process_movement(game, 0, 1));
	return (0);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	if (movement == 0 || movement == 'a' || movement == 'A')
		return (process_movement(game, -1, 0));
	else if (movement == 2 || movement == 'd' || movement == 'D')
		return (process_movement(game, 1, 0));
	return (0);
}

int	put_controls(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == 65307 || command == 53)
		exit_cleanup(game, "turn off the game");
	if (command == 119 || command == 87 || command == 13)
		works = keyboard_w_s(game, command);
	if (command == 115 || command == 83 || command == 1)
		works = keyboard_w_s(game, command);
	if (command == 97 || command == 65 || command == 0)
		works = keyboard_a_d(game, command);
	if (command == 100 || command == 68 || command == 2)
		works = keyboard_a_d(game, command);
	if (works)
		place_elements_in_game(game);
	return (1);
}
