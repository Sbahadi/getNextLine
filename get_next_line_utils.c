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

int ft_strlen(const char *str)
{
    int i;
     
    i = 0;
	if (!str)
		return 0;
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
		return NULL;
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

char	*str_before_new_line(char *s)
{
	int i;
	char *str;

	if (!s)
		return NULL;
	i = 0;
	while (s[i])
		i++;
	str = ft_calloc(i + 2, 1);
	if (!str)
		return NULL;
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		if (str[i] == '\n')
			break;
		i++;
	}
	return str;
}

char *str_after_new_line(char *s)
{
	int i;
	int j;
	char *str;
	
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break;
		i++;
	}
	if (!s[i])
	{
		free(s);
		return NULL;
	}

	str = ft_calloc(ft_strlen(s) - i + 1, 1);
	if (!str)
		return NULL;
	i++;
	while (s[i])
		str[j++] = s[i++];
	free(s);
	return (str);
}
