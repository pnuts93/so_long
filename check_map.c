/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 09:57:32 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/08 15:03:48 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_check(int *check)
{
	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
	check[3] = 0;
	check[4] = 0;
}

static void	loop(char **map, int *check, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && ((i == 0 || i == y - 1)
				|| (j == 0 || j == x - 1)))
				check[0] = -1;
			else if (map[i][j] == 'E')
				check[1]++;
			else if (map[i][j] == 'C')
				check[2]++;
			else if (map[i][j] == 'P')
				check[3]++;
			j++;
		}
		if (j != x)
			check[4] = -1;
		i++;
	}
}

static void	throw_error(int *check, int count)
{
	ft_putendl_fd("Error", 2);
	ft_putnbr_fd(count, 2);
	if (count > 1)
		ft_putstr_fd(" errors detected:", 2);
	else
		ft_putstr_fd(" error detected:", 2);
	write(2, "\n", 1);
	if (check[0] == -1)
		ft_putendl_fd("The map should be surrounded by walls", 2);
	if (!check[1])
		ft_putendl_fd("The map should contain at least one exit", 2);
	if (!check[2])
		ft_putendl_fd("The map should contain at least one collectible", 2);
	if (!check[3])
		ft_putendl_fd("The map should contain at least one starting point", 2);
	if (check[4] == -1)
		ft_putendl_fd("The map should be rectangular", 2);
}

int	check_map(char **map)
{
	int	check[5];
	int	count;
	int	i;

	count = 0;
	i = 0;
	init_check(check);
	loop(map, check, ft_strlen(map[0]), get_y(map));
	while (i < 5)
	{
		if ((i == 0 || i == 4) && check[i] == -1)
			count++;
		else if ((i > 0 && i < 4) && !check[i])
			count++;
		i++;
	}
	if (count > 0)
	{
		throw_error(check, count);
		return (0);
	}
	return (1);
}
