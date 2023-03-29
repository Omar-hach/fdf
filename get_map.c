/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:02:08 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/07 18:02:13 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	ft_hexa(char *hexa)
{
	int	len;
	int	number;
	int	multi;

	if (hexa[0] == '0' && (hexa[1] == 'x' || hexa[1] == 'X'))
		hexa += 2;
	else
		return (0);
	multi = 1;
	number = 0;
	len = ft_strlen(hexa);
	len -= (hexa[len - 1] == 10);
	while (len--)
	{
		if (hexa[len] >= 'a' && hexa[len] <= 'f')
			number += (hexa[len] - 87) * multi;
		else if (hexa[len] >= 'A' && hexa[len] <= 'F')
			number += (hexa[len] - 55) * multi;
		else if (hexa[len] >= '0' && hexa[len] <= '9')
			number += (hexa[len] - 48) * multi;
		multi *= 16;
	}
	return (number);
}

void	get_elem_color(t_map *map, int fd, int j)
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
		free(line_elem[i]);
	}
	free(line_elem);
	free(line);
}

void	get_value(t_map *map, char *file)
{
	int		fd;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	if (!map->elem)
		exit(1);
	j = -1;
	i = -1;
	while (++j < map->lenght)
		get_elem_color(map, fd, j);
	close(fd);
}
