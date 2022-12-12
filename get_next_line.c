#include "get_next_line.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

char *str_before_new_line(char *line)
{
    int index;
    char *str;
    int line_full_length;
    int line_until_new_line_length;

    index = 0;
    line_full_length = ft_strlen(line, 0);
    line_until_new_line_length = ft_strlen(line, '\n');
    if (line_full_length > 0 && line_until_new_line_length == 0)
    {
        str = ft_calloc(2, 1);
        if (!str)
            return NULL;
        str[0] = '\n';
        return str;
    }
    str = ft_calloc(ft_strlen(line, '\n') + 2, 1);
    if (!str)
        return NULL;
    while (line[index])
    {
        str[index] = line[index];
        if (str[index] == '\n')
            break;
        index++;
    }
    return str;
}

char *str_after_new_line(char *line)
{
    int lineindex;
    int strindex;
    char *str;

    lineindex = 1;
    strindex = 0;
    if(!line) return NULL;
    str = ft_calloc(ft_strlen(line, 0), 1);
    if (!str)
        return NULL;
    while (line[lineindex])
    {
        str[strindex] = line[lineindex];
        strindex++;
        lineindex++;
    }
    return str;
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
    while (!ft_strchr(buff, '\n') && bytes_read > 0)
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
        line = ft_strjoin(line, buff);   
    }
    free(buff);
    return (line);
    
}


char *get_next_line(int fd)
{
    char *line;
    char static *wasted_chars;
    char *line_to_return;
    // int line_to_return_length;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    line = get_lineee(fd);

    // printf("%s%s\n", KYEL,line);
    if (!line && !wasted_chars)
    {
        return NULL;
    }

    if (wasted_chars)
    {
        // printf("%s%s%s\n", KBLU ,"Okey we have wasted chars to handle and it is ", wasted_chars);
        line = ft_strjoin(wasted_chars, line);
        // ft_bzero(wasted_chars);
        // free(wasted_chars);
    }
   

    
    if (ft_strchr(line, '\n'))
        line_to_return = str_before_new_line(line);
    else
    {
        int i = 0;
        line_to_return = ft_calloc(ft_strlen(line, 0) + 1, 1);
        while(line[i])
        {
            line_to_return[i] = line[i];
            i++;
        }
        line_to_return[i] = '\0';
    }

    if (ft_strchr(line, '\n') && ft_strlen(ft_strchr(line, '\n') ,0) > 1)
        wasted_chars = str_after_new_line(ft_strchr(line, '\n'));


    // printf("%s||%s||\n", KRED, wasted_chars);
    
    // printf("%sCall end\n", KWHT);
    


    free(line);
    return (line_to_return);
}

int main(void)
{
    int fd = open("ff.txt", O_RDONLY);
    printf("%s%s", KGRN ,get_next_line(fd));
    printf("%s%s", KGRN ,get_next_line(fd));
    // printf("%s%s", KGRN ,get_next_line(fd));
    // printf("%s%s", KGRN ,get_next_line(fd));
    
    
    
    // printf("%s", get_next_line(fd));

    // char *test = "p\n\nl";
    
    // printf("%d", ft_strlen(ft_strchr(test, '\n'), 0));

    // return (0);
    // char *x = str_after_new_line(ft_strchr(test, '\n'));
    // printf("%s", x);
    

    return (0);
}


