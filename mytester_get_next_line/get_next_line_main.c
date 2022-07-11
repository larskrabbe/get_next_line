
#include    <stdio.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    "../git_get_next_line/get_next_line.h"

// #ifndef FILENAME
// # define FILENAME "100words.txt" big_line_no_nl
// #endif

int main()
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("100words.txt",O_RDONLY);
	printf("fd == %i\n",fd);
	while(str != NULL && i < 8)
	{
		str = get_next_line(fd);
		printf("%s",str);
		i++;
		free(str);
	}
	close(fd);
	return (0);
}