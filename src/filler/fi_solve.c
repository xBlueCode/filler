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
	if (fi_place(game) == KO)
		return (KO);
	return (OK);
}
