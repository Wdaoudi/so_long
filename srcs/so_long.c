/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:46:16 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/20 22:29:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_map_info map;

	(void)ac;
	(void)av;
	// if (ac != 2)
	//     return (0);
	//(init_struct(&map,av[1]) == 1)
	if (init_struct(&map, "./maps/maps.ber") == 1)
		return (ft_putendl_fd("Invalid map", 2), 1);

	if (!init_mlx(&map) || !map.mlx.mlx || !map.mlx.win)
		return (ft_putendl_fd("Error: Failed to initialize MLX or create window",
								2),
				cleanup(&map),
				1);

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