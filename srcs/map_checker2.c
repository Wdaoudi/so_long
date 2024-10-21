/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:57:08 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 13:58:48 by wdaoudi-         ###   ########.fr       */
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
		info->exit_x = j;
		info->exit_y = i;
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
