/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:59:42 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/07 15:17:07 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_vars *v)
{
	int	x;
	int	y;

	v->m_xy[0] = ft_strlen(v->map[0]);
	v->m_xy[1] = get_y(v->map);
	v->count = 0;
	v->mlx = mlx_init();
	v->img[0] = mlx_xpm_file_to_image(v->mlx, "./img/floor.xpm", &x, &y);
	v->img[1] = mlx_xpm_file_to_image(v->mlx, "./img/wall.xpm", &x, &y);
	v->img[2] = mlx_xpm_file_to_image(v->mlx, "./img/collectible.xpm", &x, &y);
	v->img[3] = mlx_xpm_file_to_image(v->mlx, "./img/exit.xpm", &x, &y);
	v->img[4] = mlx_xpm_file_to_image(v->mlx, "./img/player.xpm",
			&v->p.w, &v->p.h);
	v->win = mlx_new_window(v->mlx, W_W, W_H, "Bye Bye Nerdie");
	v->i_xy[0] = x;
	v->i_xy[1] = y;
}
