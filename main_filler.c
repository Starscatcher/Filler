
#include "filler.h"

int 	main()
{
	int		fd;
	char	*line;
	t_fill	*fill;

	fd = open("../1", O_RDONLY);
	line = NULL;
	fill = ft_create_fill(fill);
	ft_read_args(fd, line, fill);
}
