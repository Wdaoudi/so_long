/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:26:31 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/20 16:21:42 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_map_info *map)
{
	if (keycode == 65307) // ESC key
		close_window(map);
	else if (keycode == 119 || keycode == 65362) // W
		move_player(map, 0, -1);
	else if (keycode == 115 || keycode == 65364) // S
		move_player(map, 0, 1);
	else if (keycode == 97 || keycode == 65361) // A
		move_player(map, -1, 0);
	else if (keycode == 100 || keycode == 65363) // D
		move_player(map, 1, 0);
	return (0);
}

void	move_player(t_map_info *map, int dx, int dy)
{
	int new_x = map->x + dx;
	int new_y = map->y + dy;

	if (new_x >= 0 && new_x < map->column && new_y >= 0 && new_y < map->row
		&& map->map[new_y][new_x] != '1')
	{
		if (map->map[new_y][new_x] == 'C')
		{
			map->collectibles--;
			map->map[new_y][new_x] = '0';
		}
		if (map->map[new_y][new_x] == 'E' && map->collectibles == 0)
		{
			ft_printf("GG! You ve completed the level\n");
			close_window(map);
		}
		map->map[map->y][map->x] = '0';
		map->x = new_x;
		map->y = new_y;
		map->map[map->y][map->x] = 'P';

		draw_map(map);
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
}

