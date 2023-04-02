/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:38:57 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/24 15:39:29 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"fdf_bonus.h"

void	color_map(t_map *map, int coloring)
{
	t_point	p;

	if (coloring)
		return ;
	p.x = -1;
	p.y = -1;
	while (++p.y < map->lenght)
	{
		p.x = -1;
		while (++p.x < map->wide)
		{
			if (map->elem[p.y][p.x])
				map->color[p.y][p.x] = 0xffffff
					- (abs(map->elem[p.y][p.x] * 10));
			if (map->color[p.y][p.x] < 0xffff00)
				map->color[p.y][p.x] = 0xffff00;
		}
	}
}

int	close_win(t_window *win)
{
	free(win->img);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(0);
	return (0);
}

int	ft_multi_key(int keycode, t_window *win)
{
	if (keycode == 53)
	{
		free(win->img);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	return (0);
}

void	free_map(t_window *win)
{
	int	i;

	i = -1;
	while (++i < win->map->lenght)
		free(win->map->elem[i]);
	free(win->map->elem);
	i = -1;
	while (++i < win->map->lenght)
		free(win->map->color[i]);
	free(win->map->color);
	i = -1;
	free(win->map);
}

int	main(int argc, char **argv)
{
	t_window	win;
	int			coloring;

	coloring = 0;
	if (argc != 2)
		return (0);
	win.map = create_map(win.map, argv[1]);
	get_values(win.map, argv[1]);
	color_map(win.map, coloring);
	win.mlx_ptr = mlx_init();
	win.img = (t_image *)ft_calloc(1, sizeof(t_image));
	get_window(&win, win.map, win.img);
	put_point_on_map(win.map, win, win.img);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img->imag, 0, 0);
	mlx_hook(win.win_ptr, 2, 0, ft_multi_key, &win);
	mlx_hook(win.win_ptr, 17, 0, close_win, &win);
	mlx_loop(win.mlx_ptr);
}
