
#include    <stdio.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    "../get_next_line.h"

// #ifndef FILENAME
// # define FILENAME "100words.txt" big_line_no_nl
// #endif

// int main()
// {
// 	int		fd;
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	fd = open("100words.txt",O_RDONLY);
// 	while(str != NULL && i < 20)
// 	{
// 		str = get_next_line(fd);
// 		if (str != NULL)
// 		printf("%s",str);
// 		fflush(stdout);
// 		i++;
// 		free(str);
// 	}
// 	close(fd);
// 	return (0);
// }


int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("100words.txt", O_RDONLY);
	fd2 = open("../notmystuff/surfi89/tests/test2.txt", O_RDONLY);
	fd3 = open("../notmystuff/surfi89/tests/test3.txt", O_RDONLY);
	i = 1;
	while (i <30)
	{
		line = get_next_line(fd1);
		printf("fd 1 line %i=>%s| ",i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
