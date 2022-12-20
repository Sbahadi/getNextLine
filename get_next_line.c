#include "get_next_line.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

// char *wasted(char *str)
// {
//     char *pointer;

// }

char *get__line(int fd, char *txt)
{
    ssize_t bytes_read;
    char *buff;

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
            return NULL;
        }
        txt = ft_strjoin(txt, buff);   
    }
    
    free(buff);
    return (txt);
    
}

char *get_next_line(int fd)
{
    char static *txt;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    txt = get__line(fd, txt);
    if (ft_strlen(txt) == 0)
    {
        free(txt);
        txt = NULL;
        return NULL;
    }

    line = str_before_new_line(txt);
    txt = str_after_new_line(txt);

    // printf("%s%s", KGRN, line);
    // printf("%s%s", KRED, txt);

   
    return (line);
} 

// int main(void)
// {
//     int fd = open("ff.txt", O_RDONLY);
//     printf("%s%s", KGRN, get_next_line(fd));
//     // printf("%s%s", KGRN, get_next_line(fd));
//     // printf("%s%s", KGRN, get_next_line(fd));
//     return (0);
// }
