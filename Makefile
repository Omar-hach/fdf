# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 22:08:54 by ohachami          #+#    #+#              #
#    Updated: 2023/04/07 23:09:12 by ohachami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAME_bonus = fdf_bonus

CFLAGS = -Wall -Werror -Wextra

CC = gcc

ADDS = -lmlx -framework OpenGL -framework AppKit

SRC = get_map.c\
	print_map.c\
	check_map.c\
	ft_project_draw.c\
	draw_line.c

SRC_bonus = fdf_bonus.c\
			color_bonus.c

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

OBJ_bonus = $(SRC_bonus:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(ADDS) $(OBJ) $(LIBFT) fdf.c -o $(NAME)

bonus: $(NAME_bonus)

$(NAME_bonus):$(OBJ) $(OBJ_bonus)
	make -C ./libft
	$(CC) $(CFLAGS) $(ADDS) $(OBJ) $(OBJ_bonus) $(LIBFT) -o $(NAME_bonus)

clean:
	rm -f *.o
	make -C ./libft clean

fclean: clean
	rm -f $(NAME) $(NAME_bonus)
	make -C ./libft fclean 

re: fclean all

.PHONY: clean fclean re all bonus
