#include "get_next_line.h"

int count(char *str, char c)
{
    int i = 0;
    int count = 0;

    while (str[i])
    {
        if (str[i] == c)
        count++;
        i++;
    }
    return count;
}

char *save(char *str)
{
    int i = 1;
    int a = 0;
    char *saved_chars;

    saved_chars = ft_calloc(ft_strlen(str, 0), 1);
    while (str[i])
    {
        saved_chars[a] = str[i];
        i++;
        a++;
    }
    return saved_chars;
}

char *ft_cut(char *str, char cut_specifier)
{
    int i = 0;
    char *ptr = ft_calloc(ft_strlen(str, cut_specifier) + 2 , 1);
    while (str[i] && str[i] != cut_specifier)
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i] = '\n';
    return ptr;
}

char *get_next_line(int fd)
{
    ssize_t bytes_read;
    char    *buff;
    char    *join;
    static  char *saved;

    if (fd == 1 || fd == 2 || BUFFER_SIZE < 0 || fd < 0)
        return (0);
    
    bytes_read = 1;
    join = "";
    // saved = "";
    buff = ft_calloc(BUFFER_SIZE + 1, 1);

   
    // printf("saved => %s\n", saved);
    if (saved)
    {
    join = ft_strjoin(saved, join);
    saved = 0;
    }

    while (bytes_read > 0)
    {
        bytes_read = read(fd, buff, BUFFER_SIZE);
        join = ft_strjoin(join, buff);
        ft_bzero(buff);
        if (ft_strchr(join, '\n'))
        {
            saved = save(ft_strchr(join, '\n'));
            join = ft_cut(join, '\n');
            // printf("save => %s\n", saved);
            break;
        }
    }
    // printf("%s\n", saved);

    free(buff);

    return (join);
}


int main()
{
    
    int fd = open("ff.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    

    // printf("%s", get_next_line(fd));
    
    

    // char *name = "Salah";
    // printf("%d", ft_strlen(name, 'a') + 1);
    
    
    
   


    return (0);
}