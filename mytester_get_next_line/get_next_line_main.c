
#include    <stdio.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    "../git_get_next_line/get_next_line.h"

int main()
{
    int     fd;
    char    *str;
    int     i;

    fd = open("100words.txt",O_RDONLY);
    printf("fd == %i\n",fd);
    while(i < 15)
    {
        str = get_next_line(fd);
        printf("%3i => %s\n",i,str);
        i++;

        free(str);
    }
    close(fd);
    return (0);
}