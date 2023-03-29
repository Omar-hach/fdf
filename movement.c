/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:20:11 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/24 22:20:15 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"fdf_bonus.h"

int	switch_project(t_window *win, t_image *img,int proj)
{
	int	i;
	t_point *cord;

	ft_printf("proj %d\n", proj);
	proj = !proj;
	ft_printf("!proj %d\n", proj);
	if(proj)
		cord = win->iso_cord;
	else
		cord = win->obl_cord;
	ft_printf("///////////////////\n");
	mlx_destroy_image(win->mlx_ptr, img);
	win->img = (t_image *)ft_calloc(1,sizeof(t_image));
	img->imag = mlx_new_image(win->mlx_ptr, win->screen.x, win->screen.y);
	img->addr = mlx_get_data_addr(img->imag, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	i = -1;
	while (++i < win->map->lenght * win->map->wide)
	{
		my_mlx_pixel_put(img , cord[i].x,
			cord[i].y, cord[i].color);
		if (i % win->map->wide != win->map->wide - 1)
			draw_line(cord[i], cord[i + 1], img);
		if (i < (win->map->lenght - 1) * win->map->wide)
			draw_line(cord[i], cord[i + win->map->wide], img);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->imag, 0, 0);
	return(proj);
}

void	translation(t_window *win, t_image *img,int proj, char mov)
{
	int	i;
	t_point *cord;

	ft_printf("!proj %d\n", proj);
	if(proj)
		cord = win->iso_cord;
	else
		cord = win->obl_cord;
	ft_printf("///////////////////\n");
	mlx_destroy_image(win->mlx_ptr, img);
	win->img = (t_image *)ft_calloc(1,sizeof(t_image));
	img->imag = mlx_new_image(win->mlx_ptr, win->screen.x, win->screen.y);
	img->addr = mlx_get_data_addr(img->imag, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	i = -1;
	while (++i < win->map->lenght * win->map->wide)
	{
		cord[i].x += 2 * ((mov == 'X') - (mov == 'x'));
		cord[i].y += 2 * ((mov == 'Y') - (mov == 'y'));
		if (cord[i].y < win->screen.y - 5 && cord[i].y > 0)
		{
			my_mlx_pixel_put(img , cord[i].x,
				cord[i].y, cord[i].color);
			if (i % win->map->wide != win->map->wide - 1)
			draw_line(cord[i], cord[i + 1], img);
			if (i < (win->map->lenght - 1) * win->map->wide)
			draw_line(cord[i], cord[i + win->map->wide], img);
		}
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->imag, 0, 0);
}

int	close_win(t_window *win)
{
	free(win->iso_cord);
	free(win->obl_cord);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(0);
	return (0);
}

int	ft_multi_key(int keycode, t_window *win)
{
	static int proj;

	ft_printf("keycode = %d\n", keycode);
	if (keycode == 53)
	{
		free(win->iso_cord);
		free(win->obl_cord);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	if (keycode == 1)
		proj = switch_project(win, win->img, proj);
	if (keycode == 124)
		translation(win, win->img,proj, 'X');
	if (keycode == 123)
		translation(win, win->img,proj, 'x');
	if (keycode == 126)
		translation(win, win->img,proj, 'y');
	if (keycode == 125)
		translation(win, win->img,proj,  'Y');
	return (0);
}
// segfaulft if touch down screen 
// or go left and raight in the next frame multipale time
// or go up ??