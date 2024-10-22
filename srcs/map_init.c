/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:14:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/22 17:02:47 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_map(t_map_info *map)
{
	int		fd;
	char	*line;
	char	*tab;
	char	*temp;

	tab = NULL;
	fd = open(map->file, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd),get_next_line(-1), 1);
	while (line != NULL)
	{
		if (line[0] == '\n')
		{
			free(line);
			if (tab)
				free(tab);
			close(fd);
			get_next_line(-1);
			return (1);
		}
		temp = ft_strjoin_free(tab, line);
		if(!temp)
		{
			free(line);
			if (tab)
				free(tab);
			close(fd);
			get_next_line(-1);
			return (1);
		}
		free(line);
		tab = temp;
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	if (!tab)
		return (1);
	map->map = ft_split(tab, '\n');
	free(tab);
	if (!map->map)
		return (1);
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
	if (check_file_exists(map) == 1 || check_map_extension(map) == 1)
		return (free_failure(map), ft_putendl_fd("Error", 2),
			ft_putendl_fd("Invalid files", 2), 1);
	if (init_map(map) == 1)
		return (free_failure(map), ft_putendl_fd("Error", 2),
			ft_putendl_fd("Invalid map", 2), 1);
	if (check_rectangular(map) == 1)
		return (free_failure(map), ft_putendl_fd("Error", 2),
			ft_putendl_fd("Map is not rectangular", 2), 1);
	if (check_walls(map) == 1)
		return (free_failure(map), ft_putendl_fd("Error", 2),
			ft_putendl_fd("Invalid walls", 2), 1);
	if (count_map_elements(map) == 0)
		return (free_failure(map), ft_putendl_fd("Error", 2),
			ft_putendl_fd("Invalid Elements", 2), 1);
	if (check_map_validity(map) == 0)
		return (free_failure(map), ft_putendl_fd("Error", 2),
			ft_putendl_fd("Invalid map", 2), 1);
	return (0);
}

void	free_failure(t_map_info *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}
