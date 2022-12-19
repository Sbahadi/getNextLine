#include "get_next_line.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

char *wasted(char *str)
{
    int i = 0;
    int wasted_length;
    char *wasted_chars;
    int x;

    wasted_length = ft_strlen(str, 0) - ft_strlen(str, '\n') - 1;
    if (wasted_length <= 0)
        return NULL;
    wasted_chars = ft_calloc(wasted_length + 1, 1);
    if (!wasted_chars)
        return NULL;
    x = ft_strlen(str, '\n') + 1;
    while (str[x])
    {
        wasted_chars[i++] = str[x++];
    }
    // free(str);
    return wasted_chars;
}

char *get_lineee(int fd)
{
    ssize_t bytes_read;
    char *buff;
    char *line;

    buff = ft_calloc(BUFFER_SIZE + 1, 1);
    line = ft_calloc(1, 1);
    bytes_read = 1;
    if (!buff || !line)
        return (0);
    while (bytes_read)
    {
        ft_bzero(buff);
        bytes_read = read(fd, buff, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(line); 
            free (buff);
            return NULL;
        }
        if (bytes_read == 0)
        {
            free (buff);
            if (ft_strlen(line, 0) > 0)
                return (line);
            free (line);
            return NULL;
        }
        if (ft_strchr(buff, '\n') != -1)
        {
            line = ft_strjoin(line, buff);
            break;
        }
        line = ft_strjoin(line, buff);   
    }
    
    free(buff);
    return (line);
    
}

char *get_next_line(int fd)
{
    char static *line;
    char *get_line_value;
    char *line_to_return;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }

    get_line_value = get_lineee(fd);
    // printf("%s|get line value\n", get_line_value);
    // printf("%s|line before joinning\n", line);



    if (!get_line_value && !line)
    {
        return NULL;
    }

    if (get_line_value)
        line = ft_strjoin(line, get_line_value);

    // printf("%s%s|line after join\n", KGRN ,line);
    if (ft_strchr(line, '\n') != 1)
    {
        line_to_return = ft_substr(line, 0, ft_strlen(line, '\n') + 1);
        // printf("%s%s|line to return\n", KRED , line_to_return);
        line = wasted(line);
        // printf("%s%s|Wasted\n", KYEL , line);

    }
    else
    {
        line_to_return = line;
        ft_bzero(line);
        // free(line);
    }
    // printf("%s-----------------------------------------------------------------\n", KBLU);
    free(get_line_value);
    return (line_to_return);
}



// int main()
// {
//     char *name = "Salah\nEddine\nAit";

//     char *wast = wasted(name);
//     printf("%s", wast);

//     return(0);
// // }

int main(void)
{
    int fd = open("ff.txt", O_RDONLY);
    // get_next_line(fd);
    // get_next_line(fd);

    char *zabi;
    zabi = get_next_line(fd);
    int i = 0;
    while (zabi[i])
    {
        printf("%s%c|", KGRN ,zabi[i++]);
    }
    printf("%s%d", KRED, i);
    
    // printf("%s%s", KGRN, zabi);
    
    
    // printf("%s%s", KGRN ,get_next_line(fd));
    // printf("%s%s", KGRN ,get_next_line(fd));
    // printf("%s%s", KGRN ,get_next_line(fd));
    // printf("%s%s", KGRN ,get_next_line(fd));
    // printf("%s%s", KGRN ,get_next_line(fd));
    // printf("%s%s", KGRN ,get_next_line(fd));
    // printf("%s%s", KGRN ,get_next_line(fd));
    

    return (0);
}


