/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-bah <sait-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:51:19 by sait-bah          #+#    #+#             */
/*   Updated: 2022/12/21 17:05:25 by sait-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_before_new_line(char *s)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = ft_calloc(i + 2, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (str);
}

char	*str_after_new_line(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(s) - i + 1, 1);
	if (!str)
		return (NULL);
	i++;
	while (s[i])
		str[j++] = s[i++];
	free(s);
	return (str);
}

char	*get__line(int fd, char *txt)
{
	ssize_t	bytes_read;
	char	*buff;

	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	bytes_read = 1;
	if (!buff)
		return (NULL);
	while (bytes_read != 0 && !ft_strchr(buff, '\n'))
	{
		ft_bzero(buff);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buff);
			free(txt);
			txt = NULL;
			return (NULL);
		}
		txt = ft_strjoin(txt, buff);
	}
	free(buff);
	return (txt);
}

char	*get_next_line(int fd)
{
	char static	*txt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = get__line(fd, txt);
	if (ft_strlen(txt) == 0)
	{
		free(txt);
		txt = NULL;
		return (NULL);
	}
	line = str_before_new_line(txt);
	txt = str_after_new_line(txt);
	return (line);
}

// int main()
// {
// 	int fd = open("ff.txt", O_RDONLY);	
// }