//
// Created by Abdelfettah BESBES on 2019-06-20.
//

#include "libft.h"
#include "filler.h"

int 			fi_solve(t_game *game)
{
	if (fi_map_update(game) == KO)
		return (KO);
	if (fi_place_mezone(game) == KO)
		return (KO);

	if (ut_mtx_scan_zone(game->map,
		(t_cell){.y = game->mnl, .x = game->mnc, .v = -game->en.id},
		&(game->enarea_lt), &(game->enarea_rb)) == KO)
		return (KO);
	if (ut_mtx_scan_zone(game->piece,
		(t_cell){.y = game->pnl, .x = game->pnc, .v = (int)'*'},
		&(game->parea_lt), &(game->parea_rb)) == KO)
		return (KO);
	if (fi_place(game) == KO)
		return (KO);
	return (OK);
}
