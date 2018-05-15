/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:18:40 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/14 11:18:40 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_map(int fd, t_fill *fill, char *line)
{
	int i;

	i = 0;
	if (line[0] == 'P')
	{
		get_next_line(fd, &line);
		ft_strdel(&line);
	}
	while (i < fill->x && get_next_line(fd, &line))
	{
		if (!i)
		{
			fill->map = (char **)malloc(sizeof(char *) * (fill->x + 1));
			fill->map[fill->x] = NULL;
		}
		fill->map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
}

void	ft_read_fig(int fd, t_fill *fill, char *line)
{
	int i;

	i = 6;
	fill->fx = (int)ft_atoi(line + i);
	while (line && line[i] && line[i] != ' ')
		i++;
	fill->fy = (int)ft_atoi(line + i);
	fill->fig = (char**)malloc(sizeof(char*) * (fill->fx + 1));
	fill->fig[fill->fx] = NULL;
	i = 0;
	while (i < fill->fx && get_next_line(fd, &fill->fig[i]))
		i++;
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
		else if (!fill->p && !ft_strcmp("p1 : [./aryabenk.filler]", line + 9))
			fill->p = 1;
		else if (!fill->p && !ft_strcmp("p2 : [./aryabenk.filler]", line + 9))
			fill->p = 2;
		else if (fill->p && !fill->x && !fill->y && line[0] == 'P')
		{
			fill->me = (char)(fill->p == 1 ? 'O' : 'X');
			fill->enemy = (char)(fill->me == 'X' ? 'O' : 'X');
			fill->x = (int)ft_atoi(line + i);
			while (line && line[i] && line[i] != ' ')
				i++;
			fill->y = (int)ft_atoi(line + (++i));
		}
		else if (!fill->map)
			ft_read_map(fd, fill, line);
		ft_strdel(&line);
	}
}
