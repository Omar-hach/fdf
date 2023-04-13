/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:48:39 by ohachami          #+#    #+#             */
/*   Updated: 2023/04/07 23:00:51 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	wide_count(char *line)
{
	int	len;

	len = 0;
	if (!line)
	{
		ft_printf("No data found.\n");
		exit(1);
	}
	if (*line != ' ' && *line && *line != '\n')
		len++;
	if (*line)
		line++;
	while (*line)
	{
		if (*line == ' ' && *(line + 1) != ' ' && *(line + 1))
			len++;
		line++;
	}
	return (len);
}

void	check_name(int fd, char *file)
{
	int	i;

	if (fd < 1)
	{
		ft_printf("No file wrong.\n");
		exit(1);
	}
	i = ft_strlen(file);
	if (i < 5)
	{
		ft_printf("Found wrong line length, Exiting...\n");
		exit(1);
	}
	if (file[i - 4] != '.' || file[i - 3] != 'f'
		|| file[i - 2] != 'd' || file[i - 1] != 'f')
	{
		ft_printf("Found wrong line length, Exiting...\n");
		exit(1);
	}
}

void	check_map(char *file)
{
	char	*line;
	int		new_wide;
	int		wide;
	int		fd;

	fd = open(file, O_RDONLY);
	check_name(fd, file);
	line = get_next_line(fd);
	wide = wide_count(line);
	while (line != NULL)
	{
		new_wide = wide_count(line);
		free(line);
		if (new_wide < wide)
		{
			ft_printf("Found wrong line length, Exiting...\n");
			exit(1);
		}
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	malloc_map(t_map *map)
{
	int	i;

	map->multi = 0;
	map->north = 0;
	map->south = 0;
	map->elem = (int **)ft_calloc(map->lenght, sizeof(int *));
	map->color = (int **)ft_calloc(map->lenght, sizeof(int *));
	i = -1;
	while (++i < map->lenght)
	{
		map->color[i] = (int *)ft_calloc(map->wide, sizeof(int));
		map->elem[i] = (int *)ft_calloc(map->wide, sizeof(int));
	}
}

t_map	*create_map(t_map *map, char *file)
{
	int		fd;
	char	*line;

	check_map(file);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		exit(1);
	map->lenght = 0;
	map->wide = wide_count(line);
	while (line && ++map->lenght)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	malloc_map(map);
	return (map);
}
