/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:14:45 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/22 19:32:43 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_info	*init_map(void)
{
	int i;
	int j;
	int fd;
	char *line;
    t_map_info *map;
    
    i  = 0;
    j = 0;
	fd = open("../map/map.ber", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return (1);
    }
    map = malloc(sizeof(t_map_info)); // ?? necessaire ?
    while ((line = get_next_line(fd)) != NULL)
    {
        map->map = line;
        free(line);
    }
    close(fd);
    return ;
}
int main(int ac, char **av)
{
    
}