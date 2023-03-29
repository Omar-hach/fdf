/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:43:37 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/12 18:43:40 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_key_close(int keycode, t_window *win)
{
	if (keycode == 53)
	{
		mlx_destroy_image(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	return (0);
}

int	ft_win_close(t_window *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(0);
	return (0);
}

void	put_point_on_map(t_map *map, t_window win, t_image *img)
{
	t_point		p;
	t_point		iso_p;
	t_point		iso_p_adv;

	p.y = -1;
	while (++p.y < map->lenght && win.win_ptr)
	{
		p.x = -1;
		while (++p.x < map->wide)
		{
			project_p(&iso_p, p.x, p.y, map);
			my_mlx_pixel_put(img, iso_p.x, iso_p.y,
			map->color[p.y][p.x]);
			if (p.x + 1 < map->wide)
			{
				project_p(&iso_p_adv, p.x + 1, p.y, map);
				draw_line(iso_p, iso_p_adv, img);
			}
			if (p.y + 1 < map->lenght)
			{
				project_p(&iso_p_adv, p.x, p.y + 1, map);
				draw_line(iso_p, iso_p_adv, img);
			}
		}
	}
}

void	print_map(t_map *map)
{
	int			i;
	t_window	win;
	t_image		img;

	win.mlx_ptr = mlx_init();
	get_windows(&win, map, &img);
	put_point_on_map(map, win, &img);
	i = -1;
	while (++i < map->lenght)
		free(map->elem[i]);
	free(map->elem);
	i = -1;
	while (++i < map->lenght)
		free(map->color[i]);
	free(map->color);
	free(map);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img.imag, 0, 0);
	mlx_key_hook(win.win_ptr, ft_key_close, &win);
	mlx_hook(win.win_ptr, 17, 0, ft_win_close, &win);
	mlx_loop(win.mlx_ptr);
}
