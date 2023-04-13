/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:08:46 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/23 23:09:04 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

//  color is 0xTTRRGGBB
// if T = 0 --> T == 255

void	min_max_y(t_map *map)
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
			y = (p.y - p.x) * sin(M_PI / 6) - map->elem[p.y][p.x];
			if (y < map->north)
				map->north = y;
			if (y > map->south)
				map->south = y;
		}
	}
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	project_p(t_point *p, int x, int y, t_map *map)
{
	p->color = map->color[y][x];
	p->x = (y + x) * map->multi + 10;
	p->y = ((y - x) * sin(M_PI / 6) - map->elem[y][x]
			- map->north + 1) * map->multi + 10;
}

void	get_window(t_window *win, t_map *map, t_image *img)
{
	t_point	screen;

	map->multi = 32;
	screen.x = (map->lenght + map->wide - 2) * map->multi;
	min_max_y(map);
	screen.y = (map->south - map->north + 2) * map->multi;
	if (screen.y <= 0 || screen.x <= 0)
	{
		win->win_ptr = NULL;
		return ;
	}
	while (screen.y > 1310 || screen.x > 2550 || map->multi <= 0)
	{
		screen.y = screen.y / 2;
		screen.x = screen.x / 2;
		map->multi = map->multi / 2;
	}
	screen.x += 20;
	screen.y += 20;
	win->win_ptr = mlx_new_window(win->mlx_ptr, screen.x, screen.y,
			"hyper realistic futuristic map printer");
	img->imag = mlx_new_image(win->mlx_ptr, screen.x, screen.y);
	img->addr = mlx_get_data_addr(img->imag, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}
