/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:19:14 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/22 14:35:41 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"
#include "so_long.h"

void	fill(char **tab, t_position size, t_position cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_position){cur.x - 1, cur.y}, to_fill); // recursive appelle la fonction sur les 4 cases autour
	fill(tab, size, (t_position){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_position){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_position){cur.x, cur.y + 1}, to_fill);
}
void	flood_fill(char **tab, t_position size, t_position begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}