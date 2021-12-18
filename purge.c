/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:12:07 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/03 10:08:28 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	purge_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void	purge(t_vars *vars, int id)
{
	int	i;

	purge_map(vars->map);
	if (id)
	{
		i = 0;
		while (i < 5)
		{
			mlx_destroy_image(vars->mlx, vars->img[i]);
			i++;
		}
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
}
