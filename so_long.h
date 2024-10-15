/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:46:11 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/15 18:09:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./printf/ft_printf.h"
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
	char	*file;
	char	**map;
	int		collectibles;
	int		exit;
	int		player;
	int		valid;
}			t_map_info;

// manipulation de structure

int			init_struct(t_map_info *map, char *av);

// check de map

int	check_file_exists(t_map_info *map);
int			check_rectangular(t_map_info *info);
int			check_walls(t_map_info *info);
void		flood_fill(t_map_info *info, int x, int y);
int			count_map_elements(t_map_info *info, t_position *pos_player);
int			check_map(t_map_info *info);
int			check_map_extension(t_map_info *info);

#endif