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
