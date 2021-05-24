#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%d = |%s|\n", ret, line);
			free(line);
		}
		ret = get_next_line(fd, &line);
		printf("%d = |%s|\n", ret, line);
		free(line);
		/*ret = get_next_line(fd, &line);
		printf("%d = |%s|\n", ret, line);
		ret = get_next_line(fd, &line);
		printf("%d = |%s|\n", ret, line);
		ret = get_next_line(fd, &line);
		printf("%d = |%s|\n", ret, line);
		ret = get_next_line(fd, &line);
		printf("%d = |%s|\n", ret, line);*/
		close(fd);
	}
	else
		printf("Only/At least 2 arguments required, buddy.\n");
	return (0);
}
