/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:46:11 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 14:19:32 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
}				t_mlx_data;

typedef struct s_map_state
{
	char		*file;
	char		**map;
	int			row;
	int			column;

	int			collectibles;
	int			collectibles_reached;
	int			exit;
	int			exit_reached;
	int			exit_x;
	int			exit_y;
	int			player;
	int			x;
	int			y;
	int			valid;

	int			moves;
	void		*wall_img;
	void		*player_img;
	void		*collectible_img;
	void		*exit_img;
	void		*floor_img;

	t_mlx_data	mlx;
}				t_map_info;

// manipulation de structure

int				init_struct(t_map_info *map, char *av);

// check de map

int				check_file_exists(t_map_info *map);
int				check_rectangular(t_map_info *info);
int				check_walls(t_map_info *info);
int				count_map_elements(t_map_info *info);
void			init_element_counts(t_map_info *info);
int				count_row_elements(t_map_info *info, int i);
int				check_element(char element, t_map_info *info, int i, int j);
int				check_map_extension(t_map_info *info);
int				check_map(t_map_info *info);
void			flood_fill(t_map_info *info, char **map_copy, int x, int y);
int				check_map_validity(t_map_info *info);

// utils check

char			**create_map_cpy(t_map_info *info);
void			ft_free_tab(char **map, t_map_info *info);
int				is_valid(t_map_info *map);
void			free_failure(t_map_info *map);

// minilibx associated function

int				init_mlx(t_map_info *data);
int				close_window(t_map_info *data);
void			draw_map(t_map_info *map);
int				load_images(t_map_info *map);
void			free_images(t_map_info *map);
void			move_player(t_map_info *map, int dx, int dy);
int				render_frame(t_map_info *map);
int				key_press(int keycode, t_map_info *map);
void			cleanup(t_map_info *data);
void			free_map(t_map_info *map);
void			draw_tile(t_map_info *map, int x, int y);
void			put_image(t_map_info *map, void *img, int x, int y);
int				load_single_image(void *mlx, void **img, char *path);

#endif