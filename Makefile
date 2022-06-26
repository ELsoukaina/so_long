# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jala <sel-jala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 20:18:39 by sel-jala          #+#    #+#              #
#    Updated: 2022/06/26 20:42:53 by sel-jala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INC = so_long.h
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
CFILES = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
		 ./ft_printf/ft_functions.c ./ft_printf/ft_functions2.c \
		 ./ft_printf/ft_printf.c \
		 ./srcs/ft_map.c ./srcs/ft_check_error.c ./srcs/ft_check_map_elements.c \
		 ./srcs/mlx.c ./srcs/mouvement.c ./srcs/mlx_loop.c \
		 ./srcs/so_long.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) : $(OFILES)
	$(CC) -lmlx -framework OpenGL -framework AppKit $^ -o $@
	
%.o:%.c $(INC)
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	$(RM) $(OFILES)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all