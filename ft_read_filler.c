
#include "filler.h"

void	ft_read_map(int fd, t_fill *fill, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	fill->map = (char**)malloc(sizeof(char*) * (fill->y + 1));
	fill->map[fill->y] = NULL;
	while (i < fill->y && get_next_line(fd, &line))
	{
		while (line && line[j] != '.' && line[j] != 'X' && line[j] != 'O')
			j++;
		fill->map[i] = ft_strdup(line + j);
		ft_strdel(&line);
		i++;
	}
}

void	ft_read_fig(int fd, t_fill *fill, char *line)
{
	int i;

	i = 6;
	fill->fy = (int)ft_atoi(line + i);
	while (line && line[i] && line[i] != ' ')
		i++;
	fill->fx = (int)ft_atoi(line + i);
	fill->fig = (char**)malloc(sizeof(char*) * (fill->fy + 1));
	fill->fig[fill->fy] = NULL;
	i = 0;
	while (i < fill->fy && get_next_line(fd, &fill->fig[i]))
		i++;
	for (int j = 0; j < fill->fy; ++j)
	{
		ft_printf("%s\n", fill->fig[j]);
	}
	ft_filler_heart(fill);
}

void	ft_read_args(int fd, char *line, t_fill *fill)
{
	int i;

	i = 8;
	while (get_next_line(fd, &line) && line)
	{
		if (fill->map)
			ft_read_fig(fd, fill, line);
		if (!fill->p && !ft_strcmp("$$$ exec p1 : [./aryabenk.filler]", line))
			fill->p = 1;
		else if (!fill->p && !ft_strcmp("$$$ exec p2 : [./aryabenk.filler]", line))
			fill->p = 2;
		else if (fill->p && !fill->x && !fill->y)
		{
			fill->elem = (char)(fill->p == 1 ? '0' : 'X');
			fill->y = (int)ft_atoi(line + i);
			while (line && line[i] && line[i] != ' ')
				i++;
			fill->x = (int)ft_atoi(line + (++i));
		}
		else if (!fill->map)
			ft_read_map(fd, fill, line);
		ft_strdel(&line);
	}
}
