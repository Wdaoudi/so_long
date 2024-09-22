/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:55:24 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/22 19:03:44 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_rectangular(t_map_info *info)
{
	int	i;
	int	len;

	if (info->rows < 3 || info->cols < 3)
		return (0);
	len = info->cols;
	i = 0;
	while (i < info->rows)
	{
		if (len != info->cols)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_map_info *info)
{
	int	i;

	i = -1;
	while (++i < info->cols)
		if (info->map[i][0] != '1' || info->map[i][info->rows - 1] != '1')
			return (0);
	i = -1;
	while (++i < info->rows)
	{
		if (info->map[0][i] != '1' || info->map[info->cols - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(t_map_info *info, int x, int y)
{
	if (x < 0 || y < 0 || x >= info->cols || y >= info->rows
		|| info->map[x][y] == '1' || info->map[x][y] == 'F')
		return ;
	if (info->map[x][y] == 'C')
		info->collectibles--;
	if (info->map[x][y] == 'E')
		info->exit = 0;
	info->map[x][y] = 'F';
	flood_fill(info, x + 1, y);
	flood_fill(info, x, y + 1);
	flood_fill(info, x - 1, y);
	flood_fill(info, x, y - 1);
}

int	count_map_elements(t_map_info *info, t_position *pos_player)
{
	int	i;
	int	j;

	info->collectibles = 0;
	info->exit = 0;
	info->player = 0;
	i = -1;
	while (++i < info->rows)
	{
		j = -1;
		while (++j < info->cols)
		{
			if (info->map[i][j] == 'C')
				info->collectibles++;
			else if (info->map[i][j] == 'E')
				info->exit++;
			else if (info->map[i][j] == 'P')
			{
				info->player++;
				*pos_player = (t_position){i, j};
			}
			else if (info->map[i][j] != '0' && info->map[i][j] != '1')
				return (0);
		}
	}
	return (info->collectibles > 0 && info->exit == 1 && info->player == 1);
}

int	check_map(t_map_info *info, char *filename)
{
	t_position pos_player;
	int initial_collectibles;

	if (!check_file_exists(filename) || !check_rectangular(info)
		|| !check_walls(info) || !count_map_elements(info, &pos_player))
		return (0); // 0 est errreur
    initial_collectibles = info->collectibles;
    info->exit = 1;
    flood_fill(info,pos_player.x, pos_player.y);
    return (info->collectibles == 0 && info->exit == 0); // si tout est vrais retourne 1
}

// int main()
// {
//     if (!check_map());
//         return (printf("map pas valid\n"),1);
//     return (0);
// }