/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:06:29 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 14:09:24 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	map->wall_img = NULL;
	map->player_img = NULL;
	map->collectible_img = NULL;
	map->exit_img = NULL;
	map->floor_img = NULL;
}

int	render_frame(t_map_info *map)
{
	draw_map(map);
	return (0);
}
