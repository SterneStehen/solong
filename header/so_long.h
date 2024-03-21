/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:20:07 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/21 03:49:20 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>

//#define BUFFER_SIZE 50

typedef struct t_complete
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		exitcount;
	int		targetcount;
	int		playercount;
	int		columncount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		size;
	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*target;
	void	*mlxpointer;
	void	*winpointer;
}			t_complete;

// map
t_complete	*create_complete_struct(void);
void		ft_read_data_to_struct(t_complete *game, char *filename);
char		**ft_allocate_map(int str);
// int ft_count_lines(const char *filename);
// int ft_count_lines(int fd);
int			get_line_length(const char *line);
int			open_file(const char *filename);
void		close_file(int fd);

int			ft_audit_map(t_complete *game);
int			check_walls(t_complete *comp);
int			check_required_elements(t_complete *comp);
void		exit_cleanup(t_complete *game, char *error_message);

// grafics
void		images_in_game(t_complete *game);
void		adding_in_graphics(t_complete *game);
int			ft_add_images(t_complete *game);
void		place_elements_in_game(t_complete *game);

// controls
int			put_controls(int command, t_complete *game);

// utils
int	ft_printf(const char *format, ...);
int	ft_putptr(unsigned long long ptr);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putunisignet(unsigned int n);
int	ft_case(char str, va_list args);
int	ft_puthex(unsigned int n, int up);
int	ft_put_print_ptr(unsigned long long num);
int	ft_lennbr(long int n, int flag);


#endif
