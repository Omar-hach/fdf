/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:28:55 by ohachami          #+#    #+#             */
/*   Updated: 2022/12/04 01:28:58 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

void	ft_bzero_b(void *s, size_t n);
void	*ft_calloc_b(size_t count, size_t size);
char	*get_next_line(int fd);
char	*ft_strjoin_b(char *s1, char *s2);
int		ft_strlen(const char *str);

#endif
