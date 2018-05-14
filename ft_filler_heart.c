/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_heart.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:18:33 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/14 11:18:34 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_filler_heart(t_fill *fill)
{
	ft_check_fig_x(fill);
	ft_check_fig_y(fill);
	ft_check_place(fill);
	ft_printf("%d %d\n", fill->rex - fill->ux, fill->rey - fill->ly);
	ft_zero_fill(fill);
}
