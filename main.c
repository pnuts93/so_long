/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:46:59 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/07 15:36:52 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	v;

	if (argc != 2)
		error(&v, 0);
	v.map = get_map(argv[1]);
	if (!v.map[0])
		error(&v, 1);
	else if (!check_map(v.map))
		purge(&v, 0);
	init(&v);
	get_player(&v);
	get_mask(&v);
	put_image(&v);
	mlx_hook(v.win, 33, 1L << 5, handle_x, &v);
	mlx_key_hook(v.win, handle_key, &v);
	mlx_loop_hook(v.mlx, handle_loop, &v);
	mlx_loop(v.mlx);
	return (0);
}
