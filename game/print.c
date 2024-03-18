/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:21:26 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/18 13:21:26 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



t_complete *create_complete_struct(void) 
{
    t_complete *game = (t_complete *)malloc(sizeof(t_complete));
    if (!game) 
	{
        return NULL;
    }

    // game->fd = -1; 

    // game->heightmap = 0;
    // game->widthmap = 0;

    // game->exitcount = 0;
    // game->targetcount = 0;
    // game->playercount = 0;
    // game->columncount = 0;

    // game->x_axis = -1;
    // game->y_axis = -1;

    // game->counter = 0;
    game->size = 48;

    game->map = NULL;

    game->floor = NULL;
    game->wall = NULL;
    game->player = NULL;
    game->exit = NULL;
    game->target = NULL;

    game->mlxpointer = NULL;
    game->winpointer = NULL;

    return game;
}

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("Failed to open file");
	return (fd);
}

void	close_file(int fd)
{
	if (fd >= 0)
		close(fd);
}

char	**ft_allocate_map(int height)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		return (NULL);
    map[height] = NULL;
	return (map);
}


void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}