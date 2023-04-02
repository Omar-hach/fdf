/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:31:00 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/26 21:31:43 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_color(t_point dp, t_point p1, t_point p2, t_point p)
{
	t_color	c1;
	t_color	c2;
	t_color	c;
	int		t;

	t = 0;
	if (p1.color != p2.color)
	{
		t = ((p.x - p1.x) * dp.x + (p.y - p1.y) * dp.y);
		c1.b = p1.color & 0xff;
		c1.g = (p1.color >> 8) & 0xff;
		c1.r = (p1.color >> 16) & 0xff;
		c1.t = (p1.color >> 24) & 0xff;
		c2.b = p2.color & 0xff;
		c2.g = (p2.color >> 8) & 0xff;
		c2.r = (p2.color >> 16) & 0xff;
		c2.t = (p2.color >> 24) & 0xff;
		c.b = c1.b + (c2.b - c1.b) * t / (dp.x * dp.x + dp.y * dp.y);
		c.r = c1.r + (c2.r - c1.r) * t / (dp.x * dp.x + dp.y * dp.y);
		c.g = c1.g + (c2.g - c1.g) * t / (dp.x * dp.x + dp.y * dp.y);
		c.t = c1.t + (c2.t - c1.t) * t / (dp.x * dp.x + dp.y * dp.y);
		return ((c.t << 24) | (c.r << 16) | (c.g << 8) | (c.b));
	}
	else
		return (p1.color);
}

void	draw_line(t_point p1, t_point p2, t_image *img)
{
	t_point	dp;
	t_point	p;
	t_point	pk;
	int		step;
	int		i;

	dp.x = p2.x - p1.x;
	dp.y = p2.y - p1.y;
	pk.x = dp.x;
	pk.y = dp.y;
	i = -1;
	if (abs(dp.x) > abs(dp.y))
		step = abs(dp.x);
	else
		step = abs(dp.y);
	while (++i < step)
	{
		p.x = p1.x + pk.x / step;
		p.y = p1.y + pk.y / step;
		my_mlx_pixel_put(img, p.x, p.y,
			ft_color(dp, p1, p2, p));
		pk.x += dp.x;
		pk.y += dp.y;
	}
}
