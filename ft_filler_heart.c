
#include "filler.h"

void	ft_filler_heart(t_fill *fill)
{
	ft_check_fig_x(fill);
	ft_check_fig_y(fill);
	ft_check_place(fill);
	ft_zero_fill(fill);
}