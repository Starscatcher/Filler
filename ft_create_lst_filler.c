/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst_filler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:18:21 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/14 11:18:21 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill	*ft_create_fill(t_fill *fill)
{
	fill = (t_fill*)malloc(sizeof(t_fill));
	fill->p = 0;
	fill->x = 0;
	fill->y = 0;
	fill->fx = 0;
	fill->fy = 0;
	fill->ux = -1;
	fill->dx = -1;
	fill->ry = -1;
	fill->ly = -1;
	fill->len = 0;
	fill->me = 0;
	fill->enemy = 0;
	fill->rex = 0;
	fill->rey = 0;
	fill->map = NULL;
	fill->fig = NULL;
	return (fill);
}
