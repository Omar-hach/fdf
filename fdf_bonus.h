/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:40:01 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/24 15:41:40 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include "libft/print/ft_printf.h"
# include "libft/get_next_line/get_next_line_bonus.h"

typedef struct s_image
{
	void	*imag;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_image;

typedef struct s_color
{
	int	r;
	int	b;
	int	g;
}t_color;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}t_point;

typedef struct s_map
{
	int	multi;
	int	north;
	int	south;
	int	lenght;
	int	wide;
	int	**elem;
	int	**color;
}t_map;

typedef struct s_window
{
	void	*win_ptr;
	void	*mlx_ptr;
	t_point	screen;
	t_map	*map;
	t_image	*img;
}t_window;

t_map	*create_map(t_map *map, char *file);
int		get_values(t_map *map, char *argv);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	print_map(t_map	*map);
void	get_window(t_window *win, t_map *map, t_image *img);
void	put_point_on_map(t_map *map, t_window win, t_image *img);
int		ft_hexa(char *hexa);

int		close_win(t_window *win);
int		ft_multi_key(int keycode, t_window *win);
void	free_map(t_window *win);

#endif
