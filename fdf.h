/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:11:45 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/04 22:15:36 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include "print/ft_printf.h"
# include "get_next_line/get_next_line_bonus.h"

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
	int	t;
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
	t_image	img;
}t_window;

t_map	*create_map(t_map *map, char *file);
void	get_value(t_map *map, char *argv);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	print_map(t_map	*map);
void	project_p(t_point *p, int x, int y, t_map *map);
void	get_windows(t_window *win, t_map *map, t_image *img);
void	draw_line(t_point p1, t_point p2, t_image *img);

#endif
