/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:14:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/15 17:59:25 by wdaoudi-         ###   ########.fr       */
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
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!tab)
			tab = ft_strdup(line);
		else
		{
			temp = ft_strjoin(tab, line);
			free(tab);
			tab = temp;
		}
		free(line);
	}
	close(fd);
	line = get_next_line(-1);
	free(line);
	map->map = ft_split(tab, '\n');
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
	map->file = av;
	if (check_file_exists(map) == 1 || check_map_extension(map) == 1
		|| init_map(map) == 1)
		return (1);
	if (check_rectangular(map) == 1 || check_walls(map) == 1)
		return (1);
	return (0);
}
