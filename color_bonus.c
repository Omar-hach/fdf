/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:15:11 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/30 23:15:15 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"fdf_bonus.h"

int	get_elem_colors(t_map *map, int fd, int j, int total)
{
	char	*line;
	char	**line_elem;
	int		i;
	int		k;

	line = get_next_line(fd);
	line_elem = ft_split(line, ' ');
	i = -1;
	while (++i < map->wide)
	{
		k = 0;
		map->elem[j][i] = ft_atoi(line_elem[i]);
		while (line_elem[i][k] != '\0' && line_elem[i][k] != ',')
			k++;
		if (line_elem[i][k] == ',' )
			map->color[j][i] = ft_hexa(line_elem[i] + k + 1);
		else
			map->color[j][i] = 0xffffff;
		total += map->color[j][i] - 0xffffff;
		free(line_elem[i]);
	}
	free(line_elem);
	free(line);
	return (total);
}

int	get_values(t_map *map, char *file)
{
	int		fd;
	int		total;
	int		i;
	int		j;

	total = 0;
	fd = open(file, O_RDONLY);
	if (!map->elem)
		exit(1);
	j = -1;
	i = -1;
	while (++j < map->lenght)
		total += get_elem_colors(map, fd, j, total);
	close(fd);
	return (total);
}
