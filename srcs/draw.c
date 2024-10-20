/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:32:08 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/20 18:26:12 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	load_images(t_map_info *map)
// {
// 	int width, height;
// 	map->wall_img = mlx_xpm_file_to_image(map->mlx.mlx, "../assets/wall.xpm",
// 			&width, &height);
// 	map->player_img = mlx_xpm_file_to_image(map->mlx.mlx,"../assets/player.xpm",
	// 			&width, &height);
	// 	map->collectible_img = mlx_xpm_file_to_image(map->mlx.mlx,
	// 													"../assets/collectible.xpm",
	// 													&width,
	// 													&height);
	// 	map->exit_img = mlx_xpm_file_to_image(map->mlx.mlx,"../assets/exit.xpm",
	// 			&width, &height);
	// 	map->floor_img = mlx_xpm_file_to_image(map->mlx.mlx,"../assets/floor.xpm",
	// 			&width, &height);
	// 	if (!map->wall_img || !map->player_img || !map->collectible_img ||
	// 		!map->exit_img || !map->floor_img)
	// 	{
	//         free_images(map);
	// 		return (0);
	// 	}
	// 	return (1);
	// }
int load_images(t_map_info *map)
{
	int width, height;
    
	printf("Loading wall image...\n");
	map->wall_img = mlx_xpm_file_to_image(map->mlx.mlx, "../assets/wall.xpm",
			&width, &height);
	if (!map->wall_img)
	{
		printf("Failed to load wall image\n");
		return (0);
	}
	printf("Loading player image...\n");
	map->player_img = mlx_xpm_file_to_image(map->mlx.mlx,
											"../assets/player.xpm",
											&width,
											&height);
	if (!map->player_img)
	{
		printf("Failed to load player image\n");
		free_images(map);
		return (0);
	}
	printf("Loading collectible image...\n");
	map->collectible_img = mlx_xpm_file_to_image(map->mlx.mlx,
													"../assets/collectible.xpm",
													&width,
													&height);
	if (!map->collectible_img)
	{
		printf("Failed to load collectible image\n");
		free_images(map);
		return (0);
	}
	printf("Loading exit image...\n");
	map->exit_img = mlx_xpm_file_to_image(map->mlx.mlx, "../assets/exit.xpm",
			&width, &height);
	if (!map->exit_img)
	{
		printf("Failed to load exit image\n");
		free_images(map);
		return (0);
	}
	printf("Loading floor image...\n");
	map->floor_img = mlx_xpm_file_to_image(map->mlx.mlx, "../assets/floor.xpm",
			&width, &height);
	if (!map->floor_img)
	{
		printf("Failed to load floor image\n");
		free_images(map);
		return (0);
	}
	printf("All images loaded successfully\n");
	return (1);
}

// void	draw_map(t_map_info *map)
// {
// 	int x, y;
// 	y = 0;
// 	while (y < map->row)
// 	{
// 		x = 0;
// 		while (x < map->column)
// 		{
// 			if (map->map[y][x] == '1')
// 				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
// 						map->wall_img, x * 32, y * 32);
// 			else if (map->map[y][x] == '0')
// 				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
// 						map->floor_img, x * 32, y * 32);
// 			else if (map->map[y][x] == 'E')
// 				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
// 						map->exit_img, x * 32, y * 32);
// 			else if (map->map[y][x] == 'C')
// 				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
// 						map->collectible_img, x * 32, y * 32);
// 			else if (map->map[y][x] == 'P')
// 				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
// 						map->player_img, x * 32, y * 32);
// 			x++;
// 		}
// 		y++;
// 	}
// }
void	draw_map(t_map_info *map)
{
	int x, y;
	if (!map || !map->map)
	{
		printf("Error: map or map->map is NULL in draw_map\n");
		return ;
	}
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->column)
		{
			if (y >= map->row || x >= map->column)
			{
				printf("Error: Trying to access out of bounds map element at [%d][%d]\n",
						y,
						x);
				return ;
			}
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
						map->wall_img, x * 32, y * 32);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
						map->floor_img, x * 32, y * 32);
			else if (map->map[y][x] == 'E')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
						map->exit_img, x * 32, y * 32);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
						map->collectible_img, x * 32, y * 32);
			else if (map->map[y][x] == 'P')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
						map->player_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	free_images(t_map_info *map)
{
	if (map->wall_img)
		mlx_destroy_image(map->mlx.mlx, map->wall_img);
	if (map->player_img)
		mlx_destroy_image(map->mlx.mlx, map->player_img);
	if (map->collectible_img)
		mlx_destroy_image(map->mlx.mlx, map->collectible_img);
	if (map->exit_img)
		mlx_destroy_image(map->mlx.mlx, map->exit_img);
	if (map->floor_img)
		mlx_destroy_image(map->mlx.mlx, map->floor_img);
}

int	render_frame(t_map_info *map)
{
	draw_map(map);
	return (0);
}
