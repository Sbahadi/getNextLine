/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-bah <sait-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:51:30 by sait-bah          #+#    #+#             */
/*   Updated: 2022/12/21 17:43:15 by sait-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

char	*get_next_line(int fd);
char	*str_before_new_line(char *s);
char	*str_after_new_line(char *s);
char	*ft_calloc(size_t len, size_t size);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(char *str);

#endif
