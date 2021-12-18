# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 09:45:15 by pnuti             #+#    #+#              #
#    Updated: 2021/12/18 11:55:26 by pnuti            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		so_long
FLAGS=		-Werror -Wall -Wextra
LIBX=		-L minilibx-linux/ -lmlx_Linux -lXext -lX11 -lm -lz
LIBFT=		-L libft/ -lft
COMMON_F=	check_map.c		error.c			get_map.c		get_mask.c	\
			get_player.c	get_y.c			init.c			main.c		\
			purge.c			put_image.c		slide.c
STANDARD_F=	handle.c		do_move.c
BONUS_F=	handle_bonus.c	do_move_bonus.c

all : $(NAME)

$(NAME) : complib
	$(CC) $(FLAGS) $(COMMON_F) $(STANDARD_F) -o $@ $(LIBX) $(LIBFT)
complib : download_libs
	cd libft; make
	cd minilibx-linux; ./configure
download_libs:
	ls libft/ || git clone https://github.com/pnuts93/libft.git
	ls minilibx-linux || git clone https://github.com/42Paris/minilibx-linux.git
clean :
	cd libft; make clean
	cd minilibx-linux; make clean
fclean : clean
	rm -fr libft minilibx-linux
	rm -f $(NAME)
re : fclean all

bonus :
	$(CC) $(FLAGS) $(COMMON_F) $(BONUS_F) -o $(NAME) $(LIBX) $(LIBFT)

.PHONY: all complib clean fclean re