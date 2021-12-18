/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:34:56 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/07 15:43:05 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_sprite(t_vars *v, int i, int j)
{
	if (v->mask[0][i][j] != v->mask[1][i][j])
	{
		if (v->mask[0][i][j] == '0' || v->mask[0][i][j] == 'P')
			mlx_put_image_to_window(v->mlx, v->win, v->img[0],
				j * v->i_xy[0], i * v->i_xy[1]);
		else if (v->mask[0][i][j] == '1')
			mlx_put_image_to_window(v->mlx, v->win, v->img[1],
				j * v->i_xy[0], i * v->i_xy[1]);
		else if (v->mask[0][i][j] == 'C')
			mlx_put_image_to_window(v->mlx, v->win, v->img[2],
				j * v->i_xy[0], i * v->i_xy[1]);
		else if (v->mask[0][i][j] == 'E')
			mlx_put_image_to_window(v->mlx, v->win, v->img[3],
				j * v->i_xy[0], i * v->i_xy[1]);
		v->mask[1][i][j] = v->mask[0][i][j];
	}
}

void	put_image(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_H / v->i_xy[1])
	{
		j = 0;
		while (j < W_W / v->i_xy[0])
		{
			put_sprite(v, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img[4],
		(v->p.x - v->m2_xy[0]) * v->i_xy[0],
		(v->p.y - v->m2_xy[1]) * v->i_xy[0]);
	v->mask[0][v->p.y - v->m2_xy[1]][v->p.x - v->m2_xy[0]] = 'P';
}
