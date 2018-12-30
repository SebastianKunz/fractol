# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 11:07:58 by skunz             #+#    #+#              #
#    Updated: 2018/12/15 11:08:00 by skunz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIB = -L minilibx_macos -lmlx -I minilibx_macos/mlx.h

LIBFT = -L libft/ -lft

FRAMEWORK = -framework OpenGL -framework AppKit

NAME = fractol

SRC = main.c fractal.c helper.c draw.c eventhandler.c update.c calchelper.c

OBJ = $(SRC:.c=.o)

################################### RULES ######################################

all: $(NAME)

$(NAME): lib
	@gcc -c $(SRC)
	@gcc $(OBJ) $(LIB) $(MINILIB) $(LIBFT) $(FRAMEWORK) -O4 -o $(NAME)

clean: libclean
	@/bin/rm -f $(OBJ)

fclean: clean libfclean
	@/bin/rm -f $(NAME)

lib:
	@make -C libft/ all

libfclean:
	@make -C libft/ fclean

libclean:
	@make -C libft/ clean

re: fclean all
