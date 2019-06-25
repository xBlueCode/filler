
#include "libft.h"
#include "filler.h"

int		ut_mtx_scan_zone(int **mtx, t_cell meta, t_cell *lt, t_cell *rb)
{
	if (
		ut_mtx_scan_zone_ltx(mtx, meta, lt) == KO
		|| ut_mtx_scan_zone_lty(mtx, meta, lt) == KO
		|| ut_mtx_scan_zone_rbx(mtx, meta, rb) == KO
		|| ut_mtx_scan_zone_rby(mtx, meta, rb) == KO)
		return (KO);
	return (OK);
}

int		ut_mtx_scan_zone_lty(int **mtx, t_cell meta, t_cell *lt)
{
	int i;
	int j;

	i = -1;
	while (++i < meta.y)
	{
		j = -1;
		while (++j < meta.x)
			if (mtx[i][j] == meta.v)
			{
				lt->y = i;
				return (OK);
			}
	}
	return (KO);
}

int		ut_mtx_scan_zone_ltx(int **mtx, t_cell meta, t_cell *lt)
{
	int i;
	int j;

	j = -1;
	while (++j < meta.x)
	{
		i = -1;
		while (++i < meta.y)
			if (mtx[i][j] == meta.v)
			{
				lt->x = j;
				return (OK);
			}
	}
	return (KO);
}

int		ut_mtx_scan_zone_rby(int **mtx, t_cell meta, t_cell *rb)
{
	int i;
	int j;

	i = meta.y;
	while (--i > -1)
	{
		j = -1;
		while (++j < meta.x)
			if (mtx[i][j] == meta.v)
			{
				rb->y = i;
				return (OK);
			}
	}
	return (KO);
}

int		ut_mtx_scan_zone_rbx(int **mtx, t_cell meta, t_cell *rb)
{
	int i;
	int j;

	j = meta.x;
	while (--j > -1)
	{
		i = -1;
		while (++i < meta.y)
			if (mtx[i][j] == meta.v)
			{
				rb->x = j;
				return (OK);
			}
	}
	return (KO);
}
