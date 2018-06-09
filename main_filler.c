/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:18:05 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/16 09:55:21 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	int		fd;
	char	*line;
	t_fill	*fill;

	fill = NULL;
	fd = 0;
	line = NULL;
	fill = ft_create_fill(fill);
	ft_read_args(fd, line, fill);
	ft_del_fill(fill);
}
