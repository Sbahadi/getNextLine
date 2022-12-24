/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-bah <sait-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:51:27 by sait-bah          #+#    #+#             */
/*   Updated: 2022/12/21 17:19:53 by sait-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t len, size_t size)
{
	char	*p;
	size_t	i;

	p = malloc(len * size);
	i = 0;
	if (!p)
		return (0);
	while (i < (len * size))
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		wordindex;
	char	*str;
	int		strindex;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, 1);
	wordindex = 0;
	strindex = 0;
	if (!str)
		return (0);
	while (s1[wordindex])
		str[strindex++] = s1[wordindex++];
	wordindex = 0;
	while (s2[wordindex])
		str[strindex++] = s2[wordindex++];
	free(s1);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((char *)str)[i] == (char)c)
			return (&((char *) str)[i]);
		i++;
	}
	if ((char )c == '\0')
		return (&((char *) str)[i]);
	return (0);
}

void	ft_bzero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}
