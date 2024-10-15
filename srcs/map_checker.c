/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:55:24 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/15 18:26:02 by wdaoudi-         ###   ########.fr       */
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
	size_t	width;
	int		i;

	if (!info->map || !info->map[0])
		return (1);
	width = ft_strlen(info->map[0]);
	i = 1;
	while (info->map[i])
	{
		if (ft_strlen(info->map[i]) != width)
			return (1);
		i++;
	}
	return (0);
}

// int	check_walls(t_map_info *info)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	printf("i = %d\n", i);
// 	printf("j = %d\n", j);
// 	while (info->map[i][j])
// 	{
// 		if (info->map[i][j] != '1')
// 			return (1);
// 		j++;
// 	}
// 	printf("i = %d\n", i);
// 	printf("j = %d\n", j);
// 	j = j - 2;
// 	while (info->map[i][j])
// 	{
// 		if (info->map[i][j] != '1')
// 			return (1);
// 		i++;
// 	}
// 	i = i - 1;
// 	printf("i = %d\n", i);
// 	printf("j = %d\n", j);
// 	while (j > 0)
// 	{
// 		if (info->map[i][j] != '1')
// 			return (1);
// 		j--;
// 	}
// 	j = j + 1;
// 	printf("i = %d\n", i);
// 	printf("j = %d\n", j);
// 	while (i > 0)
// 	{
// 		if (info->map[i][j] != '1')
// 			return (1);
// 		i--;
// 	}
// 	i = i + 1;
// 	printf("i = %d\n", i);
// 	printf("j = %d\n", j);
// 	return (0);
// }

int	check_walls(t_map_info *info)
{
	int	i;
	int	j;
	int	width;
	int	height;

	height = 0;
	while (info->map[height])
		height++;
	i = 0;
	printf("%d\n", height);
	while (i < height)
	{
		j = 0;
		width = 0;
		while (info->map[i][j])
		{
			if ((i == 0 || i == height - 1) && info->map[i][j] != '1')
               return( printf("Error: Invalid wall at i=%d, j=%d\n", i, j), 1);			if (i == 0)
				width++;
			j++;
		}
		if (i > 0 && j != width)
			return (printf("line %d width: %d\n",i,j),1);
		i++;
	}
	printf("i = %d et j = %d\n", i, j);
	printf("%d\n", width);
	i = 1;
	while (i < height - 1)
	{
		if (info->map[i][0] != '1' || info->map[i][width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

// void	flood_fill(t_map_info *info, int x, int y)
// {
// 	// creeer une copie de la map pour ne pas modifier celle de base et gerer les entree a la fin car ne pas valider tant qu on a pas fini le checking
// 	if (x < 0 || y < 0 || x >= info->cols || y >= info->rows
// 		|| info->map[x][y] == '1' || info->map[x][y] == 'F')
// 		return ;
// 	if (info->map[x][y] == 'C')
// 		info->collectibles--;
// 	if (info->map[x][y] == 'E')
// 		info->exit = 0;
// 	info->map[x][y] = 'F';
// 	flood_fill(info, x + 1, y);
// 	flood_fill(info, x, y + 1);
// 	flood_fill(info, x - 1, y);
// 	flood_fill(info, x, y - 1);
// }

// int	count_map_elements(t_map_info *info, t_position *pos_player)
// {
// 	int	i;
// 	int	j;

// 	info->collectibles = 0; // comment connaitre le nombre de collectible
// 	info->exit = 0;
// 	info->player = 0;
// 	i = -1;
// 	while (++i < info->rows)
// 	{
// 		j = -1;
// 		while (++j < info->cols)
// 		{
// 			if (info->map[i][j] == 'C')
// 				info->collectibles++;
// 			else if (info->map[i][j] == 'E')
// 				info->exit++;
// 			else if (info->map[i][j] == 'P')
// 			{
// 				info->player++;
// 				*pos_player = (t_position){i, j};
// 			}
// 			else if (info->map[i][j] != '0' && info->map[i][j] != '1'
// 				&& info->map[i][j] != 'C' && info->map[i][j] != 'E'
// 				&& info->map[i][j] != 'P')
// 				return (0);
// 		}
// 		printf("collectibles = %d\n", info->collectibles);
// 	}
// 	return (info->collectibles > 0 && info->exit == 1 && info->player == 1);
// }

// int	check_map(t_map_info *info)
// {
// 	t_position	pos_player;

// 	printf("dans check map\n");
// 	if (check_rectangular(info) == 1 || check_walls(info) == 1
// 		/*|| count_map_elements(info, &pos_player) == 1*/)
// 		return (1); // 1 est errreur;
// 	printf("full check passee\n");
// 	info->exit = 1;
// 	flood_fill(info, pos_player.x, pos_player.y);
// 	if (info->collectibles == 0 && info->exit == 0) // a voir
// 		return (0);
// 	// si tout est vrais retourne 0
// 	else
// 		return (0);
// }
