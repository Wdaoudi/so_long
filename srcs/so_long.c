/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:46:16 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/22 14:51:42 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_screen_size(t_map_info *map)
{
	int	screen_width;
	int	screen_height;
	int	window_width;
	int	window_height;

	mlx_get_screen_size(map->mlx.mlx, &screen_width, &screen_height);
	window_width = map->column * TILE_SIZE;
	window_height = map->row * TILE_SIZE;
	if (window_width > screen_width || window_height > screen_height)
	{
		ft_putendl_fd("Error: Map is too large for the screen", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_map_info	map;

	if (ac != 2)
		return (ft_putendl_fd("Error: Not enough argument",
								2),
				1);
	if (init_struct(&map, av[1]) == 1)
		return (cleanup(&map),1);
	if (!init_mlx(&map) || !map.mlx.mlx || !map.mlx.win)
		return (cleanup(&map), 1);
	if (!load_images(&map))
		return (cleanup(&map), ft_putendl_fd("Error: Failed to load images", 2),
			1);
	draw_map(&map);
	mlx_hook(map.mlx.win, 17, 0, close_window, &map);
	mlx_hook(map.mlx.win, 2, 1L << 0, key_press, &map);
	mlx_loop_hook(map.mlx.mlx, render_frame, &map);
	mlx_loop(map.mlx.mlx);
	cleanup(&map);
	return (0);
}
