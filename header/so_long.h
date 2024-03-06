# ifndef SO_LONG_H
#define SO_LONG_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include "get_next_line.h"
#include "mlx.h"

#define BUFFER_SIZE 50

typedef struct t_start {
	int     fd;
	int     heightmap;
	int     widthmap;
	int     exitcount;
	int     x_axis;
	int     y_axis;
	int     counter;
	int     target; //collectables;
	char    **map;
	void    *floor;
	void    *barrier;
	void    *player;
	void    *exit;
	void    *collectable;
	void    *mlxpointer;
	void    *winpointer;
} t_complete;

//map
void ft_read_data_to_struct(t_complete *game, char *filename);
int ft_count_lines(const char *filename);
int get_line_length(const char *line);
int ft_audit_map(t_complete *game);

# endif
