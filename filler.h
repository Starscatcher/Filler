/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:34:02 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/19 15:34:03 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "./libftprintf/libft/libft.h"

typedef struct			s_fill
{
	int		p;
	int		x;
	int		y;
	int		fx;
	int		fy;
	int		ux;
	int		ly;
	int		dx;
	int		ry;
	int		len;
	int		rex;
	int		rey;
	int		on;
	char	me;
	char	enemy;
	char	**map;
	char	**fig;
}						t_fill;

void					ft_check_place(t_fill *fill);
void					ft_check_fig_x(t_fill *fill);
void					ft_check_fig_y(t_fill *fill);
void					ft_filler_heart(t_fill *fill);
void					ft_zero_fill(t_fill *fill);
void					ft_del_fill(t_fill *fill);
t_fill					*ft_create_fill(t_fill *fill);
void					ft_read_args(int fd, char *line, t_fill *fill);

#endif
