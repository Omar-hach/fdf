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

t_point	obl_project(t_point *p, int x, int y, t_map *map)
{
	p->color = map->color[y][x];
	p->x = (x + y) * map->multi + 10;
	p->y = ((-map->elem[y][x] + y * sin(M_PI / 6))
			- map->north + 1) * map->multi + 10;
	return(*p);
}

void	project_on_map(t_map *map, t_window *win, t_image *img)
{
	int			i;
	t_point		p;
	t_point		iso_p;
	t_point		iso_p_adv;

	i = 0;
	p.y = -1;
	while (++p.y < win->map->lenght && win->win_ptr)
	{
		p.x = -1;
		while (++p.x < map->wide)
		{
			project_p(&win->iso_cord[i], p.x, p.y, map);
			win->obl_cord[i] = obl_project(&iso_p, p.x, p.y, map);
			my_mlx_pixel_put(img, iso_p.x, iso_p.y,
				map->color[p.y][p.x]);
			if (p.x + 1 < map->wide)
			{
				obl_project(&iso_p_adv, p.x + 1, p.y, map);
				draw_line(iso_p, iso_p_adv, img);
			}
			if (p.y + 1 < map->lenght)
			{
				obl_project(&iso_p_adv, p.x, p.y + 1, map);
				draw_line(iso_p, iso_p_adv, img);
			}
			i++;
		}
	}
}

void	map_printer(t_map *map)
{
	int	j;
	int	i;

	j = -1;
	i = -1;
	while (++j < map->lenght)
	{
		i = -1;
		while (++i < map->wide)
			ft_printf("| %d |", map->elem[j][i]);
		ft_printf("\n");
	}
}

void	min_max_y_b(t_map *map)
{
	int		y;
	t_point	p;

	p.x = -1;
	p.y = -1;
	map->north = map->elem[0][0];
	map->south = map->elem[0][0];
	y = 0;
	while (++p.y < map->lenght)
	{
		p.x = -1;
		while (++p.x < map->wide)
		{
			y = p.y * sin(M_PI / 4) - map->elem[p.y][p.x] ;
			if (y < map->north)
				map->north = y;
			if (y > map->south)
				map->south = y;
		}
	}
}

void	get_window(t_window *win, t_map *map, t_image *img)
{
	map->multi = 32;
	win->screen.x = (map->lenght + map->wide - 2) * map->multi;
	min_max_y_b(map);
	win->screen.y = (map->south - map->north + 2) * map->multi;
	if (win->screen.y <= 0 || win->screen.x <= 0)
	{
		win->win_ptr = NULL;
		return ;
	}
	while (win->screen.y > 1310 || win->screen.x > 2550 || map->multi <= 0)
	{
		win->screen.y = win->screen.y / 2;
		win->screen.x = win->screen.x / 2;
		map->multi = map->multi / 2;
	}
	win->screen.x += 150;
	win->screen.y += 150;
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->screen.x, win->screen.y,
			"hyper realistic futuristic map printer");
	img->imag = mlx_new_image(win->mlx_ptr, win->screen.x, win->screen.y);
	img->addr = mlx_get_data_addr(img->imag, &img->bits_per_pixel,
			&img->line_length, &img->endian);
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

	if (argc != 2)
		return (0);
	win.map  = create_map(win.map, argv[1]);
	get_value(win.map, argv[1]);
	map_printer(win.map);
	win.mlx_ptr = mlx_init();
	win.img = (t_image *)ft_calloc(1,sizeof(t_image));
	get_window(&win, win.map, win.img);
	win.obl_cord = (t_point *)ft_calloc(win.map->wide * win.map->lenght ,sizeof(t_point));
	win.iso_cord = (t_point *)ft_calloc(win.map->wide * win.map->lenght ,sizeof(t_point));
	project_on_map(win.map, &win, win.img);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img->imag, 0, 0);
	mlx_hook(win.win_ptr, 2, 0, ft_multi_key, &win);
	mlx_hook(win.win_ptr, 17, 0, close_win, &win);
	mlx_loop(win.mlx_ptr);
}