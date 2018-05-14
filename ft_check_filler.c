/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:18:13 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/14 11:18:14 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_check_fig_y(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (fill->fig[i])
	{
		j = 0;
		while (fill->fig[i][j])
		{
			if (fill->fig[i][j] == '*')
			{
				fill->ly = fill->ly != -1 && fill->ly < j ? fill->ly : j;
				fill->ry = fill->ry == -1 || j > fill->ry ? j : fill->ry;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_fig_x(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (fill->fig[i])
	{
		j = 0;
		while (fill->fig[i][j])
		{
			if (fill->fig[i][j] == '*')
			{
				fill->ux = fill->ux == -1 ? i : fill->ux;
				fill->dx = i;
			}
			j++;
		}
		i++;
	}
}

int		ft_check_len(t_fill *fill, int x, int y)
{
	int r;
	int k;
	int q;

	r = 1;
	while (r < fill->x + fill->y)
	{
		k = -r;
		while (k <= r && x + k < fill->x)
		{
			q = -r;
			while (q <= r && y + q < fill->y)
			{
				if (x + k >= 0 && y + q >= 0 && \
					(fill->map[x + k][y + q] == ft_tolower(fill->enemy) || \
						fill->map[x + k][y + q] == fill->enemy))
				{
					if (!fill->len || fill->len > r)
					{
						fill->len = r;
						return (1);
					}
					else
						return (0);
				}
				q++;
			}
			k++;
		}
		r++;
	}
	return (0);
}

int		ft_put_figure(t_fill *fill, int i, int j)
{
	int x;
	int y;
	int s;
	int t;

	t = j;
	s = 0;
	x = fill->ux;
	while (x <= fill->dx && i < fill->x)
	{
		j = t;
		y = fill->ly;
		while (y <= fill->ry && j < fill->y)
		{
			if (fill->fig[x][y] == '*')
			{
				if (fill->map[i][j] == fill->enemy)
					return (0);
				else if (fill->map[i][j] == fill->me)
					s++;
				if (s > 1)
					return (0);
			}
			y++;
			j++;
		}
		x++;
		i++;
	}
	if (s == 1 && x > fill->dx && y > fill->ry)
		return (1);
	else
		return (0);
}

void	ft_check_place(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	while (fill->map && fill->map[i])
	{
		j = 0;
		while (fill->map[i][j])
		{
			if (ft_put_figure(fill, i, j))
			{
				if (ft_check_len(fill, i, j))
				{
					fill->rex = i;
					fill->rey = j;
				}
			}
			j++;
		}
		i++;
	}
}
