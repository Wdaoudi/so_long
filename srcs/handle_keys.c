/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:26:31 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 17:01:49 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_player_position(t_map_info *map, int new_x, int new_y)
{
	if (map->x == map->exit_x && map->y == map->exit_y)
		map->map[map->y][map->x] = 'E';
	else
		map->map[map->y][map->x] = '0';
	map->x = new_x;
	map->y = new_y;
	if (new_x == map->exit_x && new_y == map->exit_y)
		map->map[map->y][map->x] = 'E';
	else
		map->map[map->y][map->x] = 'P';
}

static void	handle_collectible(t_map_info *map, int new_x, int new_y)
{
	if (map->map[new_y][new_x] == 'C')
	{
		map->collectibles--;
		map->map[new_y][new_x] = '0';
	}
}

static void	handle_exit(t_map_info *map, int new_x, int new_y)
{
	if (map->map[new_y][new_x] == 'E' && map->collectibles == 0)
	{
		ft_printf("GG! You've completed the level\n");
		close_window(map);
	}
}

static int	is_valid_move(t_map_info *map, int new_x, int new_y)
{
	return (new_x >= 0 && new_x < map->column && new_y >= 0 && new_y < map->row
		&& map->map[new_y][new_x] != '1');
}

void	move_player(t_map_info *map, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = map->x + dx;
	new_y = map->y + dy;
	if (is_valid_move(map, new_x, new_y))
	{
		handle_collectible(map, new_x, new_y);
		handle_exit(map, new_x, new_y);
		update_player_position(map, new_x, new_y);
		draw_map(map);
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
}
// void	move_player(t_map_info *map, int dx, int dy)
// {
// 	int	new_x;
// 	int	new_y;

// 	new_x = map->x + dx;
// 	new_y = map->y + dy;
// 	if (new_x >= 0 && new_x < map->column && new_y >= 0 && new_y < map->row
// 		&& map->map[new_y][new_x] != '1')
// 	{
// 		if (map->map[new_y][new_x] == 'C')
// 		{
// 			map->collectibles--;
// 			map->map[new_y][new_x] = '0';
// 		}
// 		if (map->map[new_y][new_x] == 'E' && map->collectibles == 0)
// 		{
// 			ft_printf("GG! You ve completed the level\n");
// 			close_window(map);
// 		}
// 		if (map->x == map->exit_x && map->y == map->exit_y)
// 			map->map[map->y][map->x] = 'E';
// 		else
// 			map->map[map->y][map->x] = '0';
// 		map->x = new_x;
// 		map->y = new_y;
// 		map->map[map->y][map->x] = 'P';
// 		if (!(new_x == map->exit_x && map->exit_y))
// 			map->map[map->y][map->x] = 'P';
// 		draw_map(map);
// 		map->moves++;
// 		ft_printf("Moves: %d\n", map->moves);
// 	}
// }