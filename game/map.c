/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:26:48 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/18 14:26:48 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(int fd)
{
	int		count;
	char	buffer;
	int		bytes_read;
	int		i;

	i = 0;
	count = 0;
	if (fd < 0)
		return (-1);
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		i++;
		if (buffer == '\n')
			count++;
		bytes_read = read(fd, &buffer, 1);
	}
	if (bytes_read < 0)
	{
		perror("Error reading file");
		return (-1);
	}
	if (i > 0 && buffer != '\n')
		count++;
	return (count);
}

int	ft_count_string(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (width > 0 && string[width - 1] == '\n')
		width--;
	if (width > 0 && string[width - 1] != '1')
		width--;
	return (width);
}



void	ft_populate_map(t_complete *game)
{
	int		i;
	char	*line;

	i = 0;
	while (i < game->heightmap)
	{
		line = get_next_line(game->fd);
		if (line == NULL)
			break ;
		game->map[i] = ft_strdup(line);
		free(line);
		if (game->map[i] == NULL)
		{
			while (i-- > 0)
				free(game->map[i]);
			free(game->map);
			game->map = NULL;
			return ;
		}
		i++;
	}
}

void	ft_read_data_to_struct(t_complete *game, char *filename)
{
	game->fd = open_file(filename);
	if (game->fd < 0)
		return ;
	game->heightmap = ft_count_lines(game->fd);
	close_file(game->fd);
	game->fd = open_file(filename);
	if (game->fd < 0)
		return ;
	game->map = ft_allocate_map(game->heightmap);
	if (game->map == NULL)
	{
		close_file(game->fd);
		return ;
	}
	ft_populate_map(game);
	if (game->map != NULL)
		game->widthmap = ft_count_string(game->map[0]);
	close_file(game->fd);
}
