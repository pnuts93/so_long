/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:31:50 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/08 14:32:45 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	continue_move(int kn, t_vars *v, int x, int y)
{
	if (kn == 'a' && v->mask[0][y][x - 1] != '1')
	{
		if (v->m2_xy[0] - 1 >= 0
			&& v->m2_xy[0] - 1 + (W_W / v->i_xy[0]) <= v->m_xy[0])
			slide(v, -1, 0);
		v->p.x -= 1;
		v->count++;
	}
	else if (kn == 'd' && v->mask[0][y][x + 1] != '1')
	{
		if (v->m2_xy[0] + 1 >= 0
			&& v->m2_xy[0] + 1 + (W_W / v->i_xy[0]) <= v->m_xy[0])
			slide(v, 1, 0);
		v->p.x += 1;
		v->count++;
	}
}

void	do_move(int kn, t_vars *v, int x, int y)
{
	if (kn == 'w' && v->mask[0][y - 1][x] != '1')
	{
		if (v->m2_xy[1] - 1 >= 0
			&& v->m2_xy[1] - 1 + (W_H / v->i_xy[1]) <= v->m_xy[1])
			slide(v, 0, -1);
		v->p.y -= 1;
		v->count++;
	}
	else if (kn == 's' && v->mask[0][y + 1][x] != '1')
	{
		if (v->m2_xy[1] + 1 >= 0
			&& v->m2_xy[1] + 1 + (W_H / v->i_xy[1]) <= v->m_xy[1])
			slide(v, 0, 1);
		v->p.y += 1;
		v->count++;
	}
	else if (kn == 'a' || kn == 'd')
		continue_move(kn, v, x, y);
	v->mask[0][y][x] = '0';
}
