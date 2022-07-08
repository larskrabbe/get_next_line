
#include    <stdio.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    "../git_get_next_line/get_next_line.h"

// #ifndef FILENAME
// # define FILENAME "100words.txt"
// #endif

int main()
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("big_line_no_nl",O_RDONLY);
	printf("fd == %i\n",fd);
	while(str != NULL)
	{
		str = get_next_line(fd);
		printf("%3i => %s\n",i,str);
		i++;
		free(str);
	}
	close(fd);
	return (0);
}