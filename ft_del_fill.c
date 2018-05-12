
#include "filler.h"

void	ft_zero_fill(t_fill *fill)
{
	fill->fx = 0;
	fill->fx = 0;
	ft_del_doublestr(&fill->map);
	ft_del_doublestr(&fill->fig);
}

void	ft_del_fill(t_fill *fill)
{
	ft_zero_fill(fill);
	free(fill);
	fill = NULL;
}
