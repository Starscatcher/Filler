/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:09:30 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/15 16:34:31 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuse.h"

t_flag	*ft_create_flag(t_flag *flag)
{
	flag = (t_flag*)malloc(sizeof(t_flag));
	flag->h = 0;
	flag->t = 300;
	flag->f = 0;
	flag->first = 0;
	flag->second = 0;
	flag->pp1 = NULL;
	flag->pp2 = NULL;
	return (flag);
}

void	ft_del_flag(t_flag *flag)
{
	ft_strdel(&flag->pp1);
	ft_strdel(&flag->pp2);
	free(flag);
	flag = NULL;
}
