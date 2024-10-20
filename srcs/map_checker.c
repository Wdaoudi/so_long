/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:55:24 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/20 15:15:13 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file_exists(t_map_info *map)
{
	int	fd;

	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	check_rectangular(t_map_info *info)
{
	size_t	column;
	int		i;

	if (!info->map || !info->map[0])
		return (1);
	column = ft_strlen(info->map[0]);
	i = 1;
	while (info->map[i])
	{
		if (ft_strlen(info->map[i]) != column)
			return (1);
		i++;
	}
	if (i * column < 3 * 5)
		return (1);
	return (0);
}

int	check_walls(t_map_info *info)
{
	int	i;
	int	j;
	int	column;
	int	row;

	row = 0;
	while (info->map[row])
		row++;
	column = 0;
	while (info->map[0][column])
		column++;
	info->row = row;
	info->column = column;
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < column)
			if (i == 0 || i == row - 1 || j == 0 || j == column - 1)
				if (info->map[i][j] != '1')
					return (1);
		if (info->map[i][column] != '\0')
			return (1);
	}
	return (0);
}

int	check_element(char element, t_map_info *info, int i, int j)
{
	if (element == 'C')
		info->collectibles++;
	else if (element == 'E')
	{
		if (info->exit == 0)
			return (0);
		info->exit--;
	}
	else if (element == 'P')
	{
		if (info->player == 0)
			return (0);
		info->player--;
		info->x = j;
		info->y = i;
	}
	else if (element != '0' && element != '1' && element != 'C'
			&& element != 'E' && element != 'P')
		return (0);
	return (1);
}
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
