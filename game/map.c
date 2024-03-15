/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:09 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/15 16:19:09 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

// int get_line_length(const char *line) 
// {
//     return ft_strlen(line);
// }





int ft_count_lines(const char *filename) 
{
    int count;
    char buffer;
    int bytes_read;
    int i;

	i = 0;
	count = 0;
	int fd = open(filename, O_RDONLY);
    if (fd < 0)
	{
        perror("Failed to open file");
        return (-1);
    }
    while ((bytes_read = read(fd, &buffer, 1)) > 0) 
	{
        i++;
        if (buffer == '\n')
            count++;
    }
    if (bytes_read < 0) 
	{
        perror("Error reading file");
        close(fd);
        return -1;
    }
    if (i > 0 && buffer != '\n')
        	count++; 
    close(fd);
    return count;
}

static int ft_count_string(char *string)
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

int ft_open_file(char *filename) 
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) 
	    return -1;
    return fd;
}

char **ft_allocate_map(int height) 
{
    char **map = (char **)malloc(sizeof(char *) * height);
    if (map == NULL) 
	{
        return NULL;
    }
    return map;
}

void ft_populate_map(t_complete *game) 
{
    int i = 0;
    char *line;
    while (i < game->heightmap && (line = get_next_line(game->fd))) 
	{
        game->map[i] = ft_strdup(line);
        free(line);
        if (game->map[i] == NULL) 
		{
            while (i-- > 0) 
			{
                free(game->map[i]);
            }
            free(game->map);
            game->map = NULL;
            return;
        }
        i++;
    }
}

void ft_read_data_to_struct(t_complete *game, char *filename) 
{
    game->fd = ft_open_file(filename);
    if (game->fd < 0) 
		return;
    game->heightmap = ft_count_lines(filename);
    close(game->fd);
    game->fd = ft_open_file(filename);
    if (game->fd < 0) 
		return;
    game->map = ft_allocate_map(game->heightmap);
    if (game->map == NULL) 
	{
        close(game->fd);
        return;
    }
    ft_populate_map(game);
    if (game->map != NULL) 
        game->widthmap = ft_count_string(game->map[0]);
    close(game->fd);
}



// void ft_read_data_to_struct(t_complete *game, char *filename)
// {
//     int i;
// 	i = 0;
// 	game->fd = open(filename, O_RDONLY);
//     if (game->fd < 0)
// 		return;
//     game->heightmap = ft_count_lines(filename);
//     close(game->fd);
//     game->fd = open(filename, O_RDONLY);
//     if (game->fd < 0) 
// 		return;
//     game->map = (char **)malloc(sizeof(char *) * game->heightmap);
//     if (game->map == NULL) 
// 		return; 
//     while (i < game->heightmap) 
// 	{
//         char *line = get_next_line(game->fd);
//         if (line) 
// 		{
//             game->map[i] = ft_strdup(line);
//             if (game->map[i] == NULL) 
// 			{
//                 while (i-- > 0) 
// 				{
// 					free(game->map[i]);
// 				}
//                 free(game->map);
//                 game->map = NULL;
//                 close(game->fd);
//                 return;
//             }
//             free(line);
//         }
// 		i++;
//     }
// 	game->widthmap = ft_count_string(game->map[0]);
//     close(game->fd);
// }
