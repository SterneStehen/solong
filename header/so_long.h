/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreron <7353718@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:20:07 by smoreron          #+#    #+#             */
/*   Updated: 2024/03/15 16:20:07 by smoreron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    int     fd;             // Дескриптор файла

    int     heightmap;      // Высота карты
    int     widthmap;       // Ширина карты

    int     exitcount;      // Количество выходов на карте
	int     targetcount;    // collectables Количество предметов для сбора
	int    	playercount;    // Количество игроков на карте
	int		columncount;   // Количество стен на карте

    int     x_axis;         // Текущая позиция игрока по оси X
    int     y_axis;         // Текущая позиция игрока по оси Y

    int     counter;        // Счетчик выполненных действий игрока
	int	    size;			// Размер клетки карты
    
    char    **map;          // Двумерный массив карты

    void    *floor;         // Изображение для пола
    void    *wall;       	// barrier Изображение для стены
    void    *player;        // Изображение игрока
    void    *exit;          // Изображение выхода
    void    *target;   		// collectableИзображение предмета для сбора

    void    *mlxpointer;    // Указатель на экземпляр MLX
    void    *winpointer;    // Указатель на окно
} t_complete;


//map
void ft_read_data_to_struct(t_complete *game, char *filename);
int ft_count_lines(const char *filename);
int get_line_length(const char *line);
int ft_audit_map(t_complete *game);
int check_walls(t_complete *comp);
int check_required_elements(t_complete *comp);
void exit_cleanup(t_complete *game, char *error_message);

//grafics
void	images_in_game(t_complete *game);
void	adding_in_graphics(t_complete *game);
int		ft_add_images(t_complete *game);
void	place_elements_in_game(t_complete *game);

//controls
int controls_working(int command, t_complete *game);

# endif
