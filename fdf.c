/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:11:20 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/04 22:11:36 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
		return (0);
	map = NULL;
	map = create_map(map, argv[1]);
	get_value(map, argv[1]);
	print_map(map);
}
