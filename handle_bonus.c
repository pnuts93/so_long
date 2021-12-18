/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:53:18 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/08 14:31:04 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int kn, t_vars *v)
{
	int	x;
	int	y;

	x = v->p.x - v->m2_xy[0];
	y = v->p.y - v->m2_xy[1];
	if (kn == 'w' || kn == 's' || kn == 'a' || kn == 'd')
		do_move(kn, v, x, y);
	else if (kn == 65307)
		purge(v, 1);
	if (v->map[v->p.y][v->p.x] == 'C')
	{
		v->map[v->p.y][v->p.x] = '0';
		v->mask[0][y][x] = '0';
	}
	return (0);
}

int	handle_loop(t_vars *v)
{
	char	*c;

	if (v->map[v->p.y][v->p.x] == 'E')
		purge(v, 1);
	put_image(v);
	c = ft_itoa(v->count);
	mlx_put_image_to_window(v->mlx, v->win, v->img[1], W_W - v->i_xy[0], 0);
	mlx_string_put(v->mlx, v->win, W_W - 2 * v->i_xy[0], v->i_xy[1] / 2,
		0XFFFFFFFF, "Moves: ");
	mlx_string_put(v->mlx, v->win, W_W - v->i_xy[0], v->i_xy[1] / 2,
		0XFFFFFFFF, c);
	free(c);
	return (0);
}

int	handle_x(t_vars *v)
{
	purge(v, 1);
	return (0);
}
