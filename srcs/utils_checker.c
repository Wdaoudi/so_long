/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:38:21 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 14:04:37 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**create_map_cpy(t_map_info *info)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (info->row + 1));
	if (!map_cpy)
		return (NULL);
	while (i < info->row)
	{
		map_cpy[i] = ft_strdup(info->map[i]);
		if (!map_cpy[i])
		{
			while (--i >= 0)
				free(map_cpy[i]);
			free(map_cpy);
			return (NULL);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

void	ft_free_tab(char **map, t_map_info *info)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < info->row)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

int	is_valid(t_map_info *map)
{
	if (map->collectibles_reached != map->collectibles
		|| map->exit_reached != map->exit)
		return (0);
	return (1);
}

int	key_press(int keycode, t_map_info *map)
{
	if (keycode == 65307)
		close_window(map);
	else if (keycode == 119 || keycode == 65362)
		move_player(map, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		move_player(map, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(map, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(map, 1, 0);
	return (0);
}
