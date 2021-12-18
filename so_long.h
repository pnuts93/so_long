/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:50:17 by pnuti             #+#    #+#             */
/*   Updated: 2021/09/07 16:12:59 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W_W 1848
# define W_H 1046

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player
{
	int	w;
	int	h;
	int	x;
	int	y;
}	t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img[5];
	int			i_xy[2];
	char		**map;
	int			m_xy[2];
	char		mask[2][W_H / 64][W_W / 64];
	int			m2_xy[2];
	int			count;
	t_player	p;
}	t_vars;

int		check_map(char **map);
void	do_move(int kn, t_vars *v, int x, int y);
void	error(t_vars *v, int id);
char	**get_map(char *src);
void	get_mask(t_vars *v);
void	get_player(t_vars *v);
int		get_y(char **map);
int		handle_key(int kn, t_vars *v);
int		handle_loop(t_vars *v);
int		handle_x(t_vars *v);
void	init(t_vars *v);
void	print_map(char **map);
void	put_mask(t_vars *v);
void	purge_map(char **map);
void	purge(t_vars *vars, int id);
void	put_image(t_vars *v);
void	slide(t_vars *v, int dir_x, int dir_y);

#endif