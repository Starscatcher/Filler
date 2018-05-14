/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:18:28 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/14 11:18:28 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_zero_fill(t_fill *fill)
{
	fill->fx = 0;
	fill->fx = 0;
	fill->len = 0;
	fill->rey = 0;
	fill->rex = 0;
	fill->ux = -1;
	fill->dx = -1;
	fill->ry = -1;
	fill->ly = -1;
	ft_del_doublestr(&fill->map);
	ft_del_doublestr(&fill->fig);
}

void	ft_del_fill(t_fill *fill)
{
	free(fill);
	fill = NULL;
}
