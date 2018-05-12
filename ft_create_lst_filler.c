
#include "filler.h"

t_fill	*ft_create_fill(t_fill *fill)
{
	fill = (t_fill*)malloc(sizeof(t_fill));
	fill->p = 0;
	fill->x = 0;
	fill->y = 0;
	fill->fx = 0;
	fill->fy = 0;
	fill->uy = -1;
	fill->dy = -1;
	fill->rx = -1;
	fill->lx = -1;
	fill->len = -1;
	fill->elem = 0;
	fill->map = NULL;
	fill->fig = NULL;
	return (fill);
}
