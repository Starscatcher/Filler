/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:44:12 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/16 09:41:25 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuse.h"

void	ft_print_help(t_flag *flag)
{
	ft_del_flag(flag);
	ft_printf(" ___________________{sea wave}<HELP>{eoc}__________________\n");
	ft_printf("|                                           |\n");
	ft_printf("| ./filler_vm -p1 ./bot1 -p2 ./bot2 -f map  |\n");
	ft_printf("|            | ./visual [keys]              |\n");
	ft_printf("|                                           |\n");
	ft_printf("|                 {sea wave}---KEYS---{eoc}                |\n");
	ft_printf("|                                           |\n");
	ft_printf("|            {sea wave}[ -t ] num{eoc}   time              |\n");
	ft_printf("|            {sea wave}[ -f ]{eoc}       figure            |\n");
	ft_printf("|            {sea wave}[ -h ]{eoc}       help              |\n");
	ft_printf("|                                           |\n");
	ft_printf("|___________________________________________|\n");
	exit(0);
}

void	ft_print_final(t_flag *flag)
{
	if (!flag->pp1 || !flag->pp2)
		ft_print_help(flag);
	else
	{
		ft_printf("\n{green}Player 1:{eoc} %d\n", flag->first);
		ft_printf("{red}Player 2:{eoc} %d\n\n", flag->second);
		if (flag->first > flag->second)
			ft_printf("{green}FIRST PLAYER WON!{eoc}\n");
		else if (flag->first < flag->second)
			ft_printf("{red}SECOND PLAYER WON!{eoc}\n");
		else
			ft_printf("NOBODY WON!\n");
	}
}

char	*ft_print_map(int fd, char *line)
{
	int i;

	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		i = 4;
		if (ft_strstr(line, "Piece"))
			return (line);
		while (line && line[i])
		{
			if (line[i] == '.')
				ft_printf("{gray}%lc{eoc}", L'⬞');
			else if (line[i] == 'O')
				ft_printf("{green}%lc{eoc}", L'■');
			else if (line[i] == 'X')
				ft_printf("{red}%lc{eoc}", L'■');
			else if (line[i] == 'o' || line[i] == 'x')
				ft_printf("{sea wave}%lc{eoc}", L'□');
			i++;
		}
		ft_printf("\n");
		ft_strdel(&line);
	}
	ft_printf("\n");
	return (NULL);
}

char	*ft_print_fig(int fd, char *line)
{
	int i;

	ft_strdel(&line);
	ft_printf("\n{sea wave}FIGURE{eoc}\n");
	while (get_next_line(fd, &line))
	{
		i = 0;
		if (line[0] != '.' && line[0] != '*')
			return (line);
		while (line && line[i])
		{
			if (line[i] == '*')
				ft_printf("{sea wave}%lc{eoc}", L'■');
			else
				ft_printf("%lc", L'⬞');
			i++;
		}
		ft_printf("\n");
		ft_strdel(&line);
	}
	return (NULL);
}
