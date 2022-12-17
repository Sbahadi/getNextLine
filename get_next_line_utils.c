#include "get_next_line.h"

char *ft_calloc(size_t len, size_t size)
{
    char    *p;
    size_t     i;

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

int ft_strlen(const char *str, int end)
{
    int i;
     
    i = 0;
	if (!str)
		return (0);
	if (end > 0)
	{
		while (str[i] && str[i] != end)
			i++;
	}
	else {
		while (str[i])
		{
			i++;
		}
	}
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		wordindex;
	char	*str;
	int		strindex;

	if (!s1)
		return (s2);

	str = ft_calloc((ft_strlen(s1, 0) + ft_strlen(s2, 0)) + 1, 1);
	wordindex = 0;
	strindex = 0;
	if (!str)
		return (0);
	while (s1[wordindex] != '\0')
		str[strindex++] = s1[wordindex++];
	wordindex = 0;
	while (s2[wordindex] != '\0')
		str[strindex++] = s2[wordindex++];
	free(s1);
	return (str);
}

int	ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((char *)str)[i] == (char)c)
			return (i);
		i++;
	}
	if ((char )c == '\0')
		return (i);
	return (-1);
}

void ft_bzero(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = '\0';
        i++;
    }
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	unsigned int	s_i;
	char			*p;
	int			p_i;

	s_i = 0;
	p_i = 0;
	if (start == 0 && len == 0)
	{
		p = ft_calloc(2, 1);
		p[0] = s[0];
	}
	else if (len > ft_strlen (s, 0))
		p = ft_calloc(ft_strlen (s, 0) + 1, 1);
	else
		p = ft_calloc(len + 1, 1);
	if (!p || !s)
		return (0);
	while (s[s_i] != '\0')
	{
		if (s_i >= start && p_i < len)
			p[p_i++] = ((char *)s)[s_i];
		s_i++;
	}
	return (p);
}