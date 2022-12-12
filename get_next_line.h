#ifndef GET_NEXT_LINE_N
#define GET_NEXT_LINE_N

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char *get_next_line(int fd); 
char *ft_calloc(size_t len, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char  *s1, char  *s2);
int ft_strlen(const char *str, int end);
void ft_bzero(char *str);

#endif