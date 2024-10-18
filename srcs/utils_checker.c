/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:38:21 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/18 18:41:15 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**create_map_cpy(t_map_info *info)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (info->row));
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
	map_cpy[info->row] = NULL;
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
