/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:40:42 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/10/20 17:46:30 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



int init_mlx(t_map_info *data)
{
    data->mlx.mlx = mlx_init();
    if (!data->mlx.mlx)
    {
        ft_putendl_fd("Error: Failed to initialize MLX", 2);
        return (0);
    }

    data->mlx.win = mlx_new_window(data->mlx.mlx, data->column * 32, data->row * 32, "So Long");
    if (!data->mlx.win)
    {
        ft_putendl_fd("Error: Failed to create window", 2);
        mlx_destroy_display(data->mlx.mlx);
        free(data->mlx.mlx);
        return (0);
    }

    return (1);
}
int close_window(t_map_info *data)
{
    mlx_destroy_window(data->mlx.mlx, data->mlx.mlx);
    mlx_destroy_display(data->mlx.mlx);
    free_images(data);
    free(data->mlx.mlx);
    
    //futur liberation de memoire prevoir une fonction de clean
    exit(0);
}
