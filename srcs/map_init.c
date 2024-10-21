/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:14:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/21 13:56:23 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_map(t_map_info *map)
{
	int		fd;
	char	*line;
	char	*tab;

	tab = NULL;
	fd = open(map->file, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tab = ft_strjoin_free(tab, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	map->map = ft_split(tab, '\n');
	if (!map->map)
		return (free(tab), 1);
	free(tab);
	return (0);
}

int	check_map_extension(t_map_info *info)
{
	char	*extension;

	extension = ft_strrchr(info->file, '.');
	if (extension == NULL)
		return (1);
	if (ft_strncmp(extension, ".ber", 5) == 0)
		return (0);
	return (1);
}

int	init_struct(t_map_info *map, char *av)
{
	ft_memset(map, 0, sizeof(t_map_info));
	map->file = av;
	if (check_file_exists(map) == 1 || check_map_extension(map) == 1
		|| init_map(map) == 1)
		return (free_failure(map), 1);
	if (check_rectangular(map) == 1 || check_walls(map) == 1
		|| count_map_elements(map) == 0)
		return (free_failure(map), 1);
	if (check_map_validity(map) == 0)
		return (free_failure(map), 1);
	return (0);
}

void	free_failure(t_map_info *map)
{
	if (map->map)
	{
		ft_free_tab(map->map, map);
		map->map = NULL;
	}
}
