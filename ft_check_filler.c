
#include "filler.h"

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
				fill->lx = fill->lx != -1 && j > fill->lx ? fill->lx : j;
				fill->rx = fill->rx == -1 && j < fill->lx ? fill->rx : j;
			}
			j++;
		}
		i++;
	}
}

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
				fill->uy = fill->uy == -1 ? i : fill->uy;
				fill->dy = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_len(t_fill *fill)
{

}

int		ft_put_figure(t_fill *fill, int k, int z)
{
	int i;
	int j;

	i = fill->uy;
	while (fill->fig && i < fill->dy && fill->map && fill->map[k])
	{
		j = fill->lx;
		while (j < fill->rx)
		{
			if (fill->fig[i][j] == '*')
			{
				if (fill->map && fill->map[k][z] && fill->map[k][z] == '.')
					ft_check_len(fill);
				else
					return (0);
			}
			j++;
			z++;
		}
		z = 0;
		k++;
		i++;
	}
}

void	ft_check_place(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (fill->map && fill->map[i])
	{
		j = 0;
		while (fill->map[i][j])
		{
			if (fill->map[i][j] == '.')
				ft_put_figure(fill, i, j);
			j++;
		}
		i++;
	}
}
