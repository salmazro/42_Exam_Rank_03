// Expected files : get_next_line.c get_next_line.h
// Allowed functions: read, free, malloc
// prototype should be: char *get_next_line(int fd);
// Your program will be compiled with the flag -D BUFFER_SIZE=xx

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *ft_strdup(char *str)
{
    int i = ft_strlen(str);
    char *s = malloc(i + 1);
    if (!s)
        return (NULL);
    int x = -1;
    while (str[++x])
        s[x] = str[x];
    s[x] = '\0';
    return(s);
}

char *get_next_line(int fd)
{
    char *str;
    char c;
    int i = 0;
    char array[999999] = {0};

    while (read(fd, &c, 1) > 0)
    {
        array[i++] = c;
        if (c == '\n')
            break ;
    }
    if (!array[0])
        return NULL;
    str = ft_strdup(array);
    return str;
}

int main()
{
    int fd;
    fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s\n", str);
}