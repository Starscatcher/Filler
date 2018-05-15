/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:03:56 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/15 16:42:38 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuse.h"

int			ft_find(char *arr, char elem)
{
	int j;

	j = 0;
	while (arr && arr[j])
	{
		if (arr[j] == elem)
			return (1);
		j++;
	}
	return (0);
}

int			ft_is_flag(char f, char s)
{
	if (f != '-')
		return (0);
	if (ft_find("thf", s))
		return (1);
	else
		return (0);
}

void		ft_read_flags(int argc, char **argv, t_flag *flag)
{
	int i;

	i = 1;
	while (i < argc && ft_is_flag(argv[i][0], argv[i][1]) && !argv[i][2])
	{
		flag->h += argv[i][1] == 'h' ? 1 : 0;
		flag->f += argv[i][1] == 'f' ? 1 : 0;
		if (argv[i][1] == 't')
			flag->t = ft_atoi(argv[++i]);
		i++;
	}
	flag->h += i < argc ? 1 : 0;
	if (flag->h)
		ft_print_help(flag);
}

void		ft_win(int *p, char *line, t_flag *flag)
{
	if (!*p)
	{
		flag->first = (int)ft_atoi(line + 10);
		++*p;
	}
	else
		flag->second = (int)ft_atoi(line + 10);
}

void		ft_read(int fd, char *line, t_flag *flag)
{
	int p;

	p = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, "$$$ exec p1"))
			flag->pp1 = ft_strdup(line + 14);
		else if (ft_strstr(line, "$$$ exec p2"))
			flag->pp2 = ft_strdup(line + 14);
		else if (ft_strstr(line, "Plateau"))
		{
			usleep((useconds_t)flag->t * 1000);
			system("clear");
			ft_printf("{green}Player 1{eoc} %s\n", flag->pp1);
			ft_printf("{red}Player 2{eoc} %s\n", flag->pp2);
			line = ft_print_map(fd, line);
		}
		if (ft_strstr(line, "Piece") && flag->f)
			line = ft_print_fig(fd, line);
		if (ft_strstr(line, "=="))
			ft_win(&p, line, flag);
		ft_strdel(&line);
	}
}
