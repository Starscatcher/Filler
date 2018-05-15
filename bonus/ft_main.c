/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:04:50 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/15 16:39:10 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "bonuse.h"

int	main(int argc, char **argv)
{
	t_flag	*flag;
	char	*line;
	int		fd;

	flag = NULL;
	line = NULL;
	setlocale(LC_ALL, "");
	fd = 0;
	flag = ft_create_flag(flag);
	ft_read_flags(argc, argv, flag);
	ft_read(fd, line, flag);
	ft_print_final(flag);
	ft_del_flag(flag);
	return (1);
}
