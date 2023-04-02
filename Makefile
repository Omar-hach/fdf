# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 22:08:54 by ohachami          #+#    #+#              #
#    Updated: 2023/03/04 22:08:59 by ohachami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

ADDS = -lmlx -framework OpenGL -framework AppKit

SRC = libft/ft_atoi.c\
	libft/ft_bzero.c\
	libft/ft_calloc.c\
	libft/ft_isalnum.c\
	libft/ft_isalpha.c\
	libft/ft_isascii.c\
	libft/ft_isdigit.c\
	libft/ft_isprint.c\
	libft/ft_itoa.c\
	libft/ft_memchr.c\
	libft/ft_memcmp.c\
	libft/ft_memcpy.c\
	libft/ft_memset.c\
	libft/ft_putchar_fd.c\
	libft/ft_putendl_fd.c\
	libft/ft_putnbr_fd.c\
	libft/ft_putstr_fd.c\
	libft/ft_strchr.c\
	libft/ft_strdup.c\
	libft/ft_striteri.c\
	libft/ft_strlcat.c\
	libft/ft_strjoin.c\
	libft/ft_strlcpy.c\
	libft/ft_strlen.c\
	libft/ft_strncmp.c\
	libft/ft_strrchr.c\
	libft/ft_substr.c\
	libft/ft_split.c\
	libft/ft_memmove.c\
	libft/ft_strnstr.c\
	libft/ft_tolower.c\
	libft/ft_toupper.c\
	libft/ft_strtrim.c\
	libft/ft_strmapi.c\
	print/ft_strlen.c\
	print/ft_putnbr.c\
	print/ft_putnbr_abs.c\
	print/ft_putstr.c\
	print/ft_putchar.c\
	print/ft_printf.c\
	print/ft_address.c\
	get_next_line/get_next_line_bonus.c\
	get_next_line/get_next_line_utils_bonus.c\
	get_map.c\
	print_map.c\
	check_map.c\
	ft_project_draw.c\
	draw_line.c

SRC_bonus = fdf_bonus.c\
			color_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_bonus = $(SRC_bonus:.c=.o)

all:$(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(ADDS) -o fdf fdf.c $(NAME) 

bonus:$(OBJ) $(OBJ_bonus)
	ar rc $(NAME) $(OBJ) $(OBJ_bonus)
	$(CC) $(CFLAGS) $(ADDS)  -o fdf fdf_bonus.c $(NAME) 

clean:
	rm -f *.o libft/*.o get_next_line/*.o print/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
