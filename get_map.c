/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:45:36 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/07 18:11:15 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_line(int fd, char *buf, char **tmp)
{
	int		n;
	char	*tmp2;

	n = read(fd, buf, 99);
	buf[n] = 0;
	tmp2 = ft_strjoin(*tmp, buf);
	free(*tmp);
	*tmp = tmp2;
	return (n);
}

char	**get_map(char *src)
{
	int		map_fd;
	char	buf[100];
	char	*tmp;
	char	**res;
	int		n;

	map_fd = open(src, O_APPEND);
	if (map_fd == -1)
		error(NULL, 0);
	tmp = ft_strdup("");
	n = 1;
	while (n > 0)
		n = get_line(map_fd, buf, &tmp);
	res = ft_split(tmp, '\n');
	free(tmp);
	close(map_fd);
	return (res);
}
