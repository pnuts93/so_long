/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:05:46 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/07 16:01:48 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	slide(t_vars *v, int dir_x, int dir_y)
{
	int	i;
	int	j;
	int	lim_y;

	if (v->m2_xy[1] >= 0)
		i = 0;
	else
		i = v->m2_xy[1] * -1;
	if (v->m2_xy[0] >= 0)
		j = 0;
	else
		j = v->m2_xy[0] * -1;
	v->m2_xy[0] += dir_x;
	v->m2_xy[1] += dir_y;
	lim_y = W_H / v->i_xy[1] - i;
	while (i < lim_y)
	{
		ft_memmove(&v->mask[0][i][j], &v->map[i + v->m2_xy[1]][j + v->m2_xy[0]],
			W_W / v->i_xy[0] - j);
		i++;
	}
}
