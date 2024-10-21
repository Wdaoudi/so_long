/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:55:24 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 13:58:45 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_row_elements(t_map_info *info, int i)
{
	int	j;

	j = -1;
	while (++j < info->column)
	{
		if (!check_element(info->map[i][j], info, i, j))
			return (0);
	}
	return (1);
}

void	init_element_counts(t_map_info *info)
{
	info->collectibles = 0;
	info->exit = 1;
	info->player = 1;
	info->moves = 0;
	info->exit_x = 0;
	info->exit_y = 0;
}

int	count_map_elements(t_map_info *info)
{
	int	i;

	init_element_counts(info);
	i = -1;
	while (++i < info->row)
	{
		if (!count_row_elements(info, i))
			return (0);
	}
	return (info->collectibles > 0 && info->exit == 0 && info->player == 0);
}

void	flood_fill(t_map_info *info, char **map_copy, int x, int y)
{
	if (x < 0 || y < 0 || x >= info->row || y >= info->column
		|| map_copy[x][y] == '1' || map_copy[x][y] == 'F')
		return ;
	if (map_copy[x][y] == 'C')
		info->collectibles_reached++;
	if (map_copy[x][y] == 'E')
		info->exit_reached = 1;
	map_copy[x][y] = 'F';
	flood_fill(info, map_copy, x + 1, y);
	flood_fill(info, map_copy, x - 1, y);
	flood_fill(info, map_copy, x, y + 1);
	flood_fill(info, map_copy, x, y - 1);
}

int	check_map_validity(t_map_info *info)
{
	char	**map_copy;

	info->exit = 1;
	info->exit_reached = 0;
	info->collectibles_reached = 0;
	map_copy = create_map_cpy(info);
	if (!map_copy)
		return (0);
	flood_fill(info, map_copy, info->y, info->x);
	ft_free_tab(map_copy, info);
	if (is_valid(info) == 0)
		return (0);
	return (1);
}
