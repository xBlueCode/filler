
#include "libft.h"
#include "filler.h"

int		fi_place_distdiff_tocom(t_game *g, t_cell c1, t_cell c2)
{
	t_cell mid1;
	t_cell mid2;
	t_cell com;

	mid1 = ft_cell_mid(
		(t_cell){.x = c1.x + g->parea_lt.x, .y = c1.y + g->parea_lt.y, .v = 0},
		(t_cell){.x = c1.x + g->parea_rb.x, .y = c1.y + g->parea_rb.y, .v = 0});
	mid2 = ft_cell_mid(
		(t_cell){.x = c2.x + g->parea_lt.x, .y = c2.y + g->parea_lt.y, .v = 0},
		(t_cell){.x = c2.x + g->parea_rb.x, .y = c2.y + g->parea_rb.y, .v = 0});
	com = ut_mtx_center_of_mass(g->map, g->mnl, g->mnc, -g->en.id);
	return (ut_vec_normsquare(mid2, com) - ut_vec_normsquare(mid1, com));
}

int		fi_place_distdiff(t_game *g, t_cell c1, t_cell c2)
{
	t_cell mid1;
	t_cell mid2;
	t_cell miden;

	mid1 = ft_cell_mid(
		(t_cell){.x = c1.x + g->parea_lt.x, .y = c1.y + g->parea_lt.y, .v = 0},
		(t_cell){.x = c1.x + g->parea_rb.x, .y = c1.y + g->parea_rb.y, .v = 0});
	mid2 = ft_cell_mid(
		(t_cell){.x = c2.x + g->parea_lt.x, .y = c2.y + g->parea_lt.y, .v = 0},
		(t_cell){.x = c2.x + g->parea_rb.x, .y = c2.y + g->parea_rb.y, .v = 0});
	miden = ft_cell_mid(g->enarea_lt, g->enarea_rb);
	return (ut_vec_normsquare(mid2, miden) - ut_vec_normsquare(mid1, miden));
}

int		fi_place_enadj(t_game *game, int i, int j)
{

	int pi;
	int pj;
	int neighbors;

	pi = -1;
	neighbors = 0;
	while (++pi < game->pnl && (pj = -1))
	{
		while (++pj < game->pnc)
			if (game->piece[pi][pj] == (int)'*')
				if (fi_map_adjacent(game, i, j, -game->en.id))
					neighbors++;
	}
	return (neighbors);
}