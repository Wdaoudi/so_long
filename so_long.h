/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:46:11 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/14 19:27:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "./printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_position
{
	int x; // x : Width  | x-axis
	int y; // y : Height | y-axis
}			t_position;

typedef struct s_map_state
{
	char	**map;
	int		rows;
	int		cols;
	int		collectibles;
	int		exit;
	int		player;
	int		valid;
}			t_map_info;

//check de map

int	check_file_exists(char *filename);
int	check_rectangular(t_map_info *info);
int	check_walls(t_map_info *info);
void	flood_fill(t_map_info *info, int x,int y);
int	count_map_elements(t_map_info *info, t_position *pos_player);
int	check_map(t_map_info *info, char *filename);


#endif