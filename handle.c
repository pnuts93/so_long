/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:20:53 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/07 15:55:00 by pnuti            ###   ########.fr       */
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
	if (v->map[v->p.y][v->p.x] == 'E')
		purge(v, 1);
	put_image(v);
	return (0);
}

int	handle_x(t_vars *v)
{
	purge(v, 1);
	return (0);
}
