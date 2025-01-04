#include <stdio.h>
#include "../get_next_line.h"

/*#define LINES_COUNT 12*/
/*#define FILE "multiple_line_with_nl"*/

int main(int ac, char **av)
{
	int fd;
	int lines = 1;
	(void)ac;
	if (av && av[1])
		fd = open(av[1], O_RDONLY);
	else
		fd = STDIN_FILENO;
	char *line;
	if (av && atoi(av[2]))
		lines = atoi(av[2]);
	for (int i =0; i < lines; i++)
	{
		line = get_next_line(fd);
		printf("LINE --> |%s|\n", line);
		free(line);
	}


	close(fd);
	return (0);
}
