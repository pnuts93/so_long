/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mask.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:54:48 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/07 16:11:31 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mask(t_vars *v)
{
	int	i;

	i = 0;
	while (i < W_H / 64)
	{
		ft_bzero(v->mask[0][i], W_W / v->i_xy[0]);
		ft_bzero(v->mask[1][i], W_W / v->i_xy[0]);
		i++;
	}
}

static void	get_coordinates(t_vars *v)
{
	int	margin;

	margin = 0;
	if (v->m_xy[0] > W_W / v->i_xy[0])
	{
		if (v->p.x - (W_W / 2) / v->i_xy[0] < 0)
			margin = v->p.x - (W_W / 2) / v->i_xy[0];
		else if (v->p.x + (W_W / 2) / v->i_xy[0] > v->m_xy[0])
			margin = v->p.x + (W_W / 2) / v->i_xy[0] - v->m_xy[0];
		v->m2_xy[0] = v->p.x - (W_W / 2) / v->i_xy[0] - margin;
	}
	else
		v->m2_xy[0] = (v->m_xy[0] - W_W / v->i_xy[0]) / 2;
	margin = 0;
	if (v->m_xy[1] > W_H / v->i_xy[1])
	{
		if (v->p.y - (W_H / 2) / v->i_xy[1] < 0)
			margin = v->p.y - (W_H / 2) / v->i_xy[1];
		else if (v->p.y + (W_H / 2) / v->i_xy[1] > v->m_xy[1])
			margin = v->p.y + (W_H / 2) / v->i_xy[1] - v->m_xy[1];
		v->m2_xy[1] = v->p.y - (W_H / 2) / v->i_xy[1] - margin;
	}
	else
		v->m2_xy[1] = (v->m_xy[1] - W_H / v->i_xy[1]) / 2;
}

void	get_mask(t_vars *v)
{
	int	i;
	int	j;
	int	lim[2];

	get_coordinates(v);
	init_mask(v);
	if (v->m2_xy[1] < 0)
		i = v->m2_xy[1] * -1;
	else
		i = 0;
	lim[1] = W_H / v->i_xy[1] - i;
	while (i < lim[1] && v->map[i + v->m2_xy[1]])
	{
		if (v->m2_xy[0] < 0)
			j = v->m2_xy[0] * -1;
		else
			j = 0;
		lim[0] = W_W / v->i_xy[0] - j;
		while (j < lim[0] && v->map[i + v->m2_xy[1]][j + v->m2_xy[0]])
		{
			v->mask[0][i][j] = v->map[i + v->m2_xy[1]][j + v->m2_xy[0]];
			j++;
		}
		i++;
	}
}
