/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:32:08 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 23:39:49 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_single_image(void *mlx, void **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	return (*img != NULL);
}

int	load_images(t_map_info *map)
{
	if (!load_single_image(map->mlx.mlx, &map->wall_img, "assets/wall.xpm")
		|| !load_single_image(map->mlx.mlx, &map->player_img,
			"assets/player.xpm") || !load_single_image(map->mlx.mlx,
			&map->collectible_img, "assets/collectible.xpm")
		|| !load_single_image(map->mlx.mlx, &map->exit_img, "assets/exit.xpm")
		|| !load_single_image(map->mlx.mlx, &map->floor_img,
			"assets/floor.xpm"))
	{
		cleanup(map);
		return (0);
	}
	return (1);
}

void	put_image(t_map_info *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, img, x * 32, y * 32);
	//passer en brut de decalage bas et droite
}

void	draw_tile(t_map_info *map, int x, int y)
{
	char	tile;

	tile = map->map[y][x];
	if (tile == '1')
		put_image(map, map->wall_img, x, y);
	else if (tile == '0')
		put_image(map, map->floor_img, x, y);
	else if (tile == 'E')
	{
		put_image(map, map->exit_img, x, y);
		if (x == map->x && y == map->y)
			put_image(map, map->player_img, x, y);
	}
	else if (tile == 'C')
		put_image(map, map->collectible_img, x, y);
	else if (tile == 'P')
		put_image(map, map->player_img, x, y);
}

void	draw_map(t_map_info *map)
{
	int	x;
	int	y;

	if (!map || !map->map)
		return ((void)ft_putendl_fd("Error: map or map->map is NULL", 2));
	y = -1;
	while (++y < map->row)
	{
		x = -1;
		while (++x < map->column)
		{
			if (y >= map->row || x >= map->column)
			{
				ft_putendl_fd("Error: Out of bounds access", 2);
				return ;
			}
			draw_tile(map, x, y);
		}
	}
}
