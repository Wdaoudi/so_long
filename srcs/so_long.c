/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:46:16 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/17 16:12:21 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int ac, char **av)
{
    t_map_info map;
    (void)ac;
    (void)av;
    // char *filename;
    // filename = "./maps/maps.ber";
    // if (ac != 2)
    //     return (0);
    if (init_struct(&map,"./maps/maps.ber") == 1) //(init_struct(&map, av[1]) == 1)
        return (ft_putendl_fd("Invalid map",2),1);
    printf ("map valide");        
    // init_map();
	
	return (0);
}