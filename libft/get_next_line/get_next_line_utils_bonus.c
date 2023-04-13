/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:39:25 by ohachami          #+#    #+#             */
/*   Updated: 2022/12/04 19:39:34 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"

int	ft_strlen_b(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_b(char *s1, char *s2)
{
	char	*uni;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = ft_calloc_b(1, 1);
		*s1 = '\0';
	}
	i = -1;
	j = -1;
	uni = (char *)ft_calloc_b(ft_strlen_b(s1) + ft_strlen_b(s2) + 1, 1);
	if (!uni)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		uni[i] = s1[i];
	while (s2[++j])
		uni[i + j] = s2[j];
	free(s1);
	return (uni);
}

void	ft_bzero_b(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)s = 0;
		s++;
		i++;
	}
}

void	*ft_calloc_b(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero_b(p, count * size);
	return (p);
}
