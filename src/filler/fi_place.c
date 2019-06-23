//
// Created by Abdelfettah BESBES on 2019-06-21.
//

#include "libft.h"
#include "filler.h"

int 	fi_place(t_game *game)
{
	int i;
	int j;

	game->lastmove.v = -1;
	i = game->mezone_lt.y - 1;
	while (++i <= game->mezone_rb.y)
	{
		j = game->mezone_lt.x - 1;
		while (++j <= game->mezone_rb.x)
			fi_place_update(game, i, j, fi_place_at(game, i, j));
	}
	if (game->lastmove.v < 0)
		return (KO);
	return (OK);
}

int 	fi_place_at(t_game *game, int i, int j)
{
	int pi;
	int pj;
	int score;
	int placable;

	pi = -1;
	score = 0;
	placable = 0;
	while (++pi < game->pnl && (pj = -1))
	{
		while (++pj < game->pnc)
		{
			if (game->piece[pi][pj] == (int)'*')
			{
				if (game->map[i + pi][j + pj] == -game->en.id)
					return (-1);
				if (game->map[i + pi][j + pj] > 0)
					score += game->map[i + pi][j + pj];
				else if (game->map[i + pi][j + pj] == -game->me.id)
				{
					if (!placable)
						placable = 1;
					else
						return (-1);
				}
				// todo: ^^^^^^ Implement sum{1/s0, 1/s1 ...}.
			}
		}
	}
	//FT_LOG(FT_LOG_LDEB, FT_LOG_FMESS, "[%d][%d] : Score=%d : Placable: %d\n",
	//	i , j, score, placable);
	return (placable ? score : -1);
}

int 	fi_place_update(t_game *game, int i, int j, int score)
{
	t_cell new_move;

	if (score < 0)
		return (KO);
	new_move = (t_cell){.y = i, .x = j, .v = score};
	if (game->lastmove.v < 0)
		game->lastmove = new_move;
	else if (!score)
		return (KO);
	else if (game->lastmove.v > score)
		game->lastmove = new_move;
	//else if (score == game->lastmove.v
	//	&& 0 > fi_place_distdiff(game, game->lastmove, new_move))
	//	game->lastmove = new_move;
	else if (score == game->lastmove.v
		&& 0 > fi_place_distdiff_tocom(game, game->lastmove, new_move))
		game->lastmove = new_move;
	return (OK);
}

int		fi_place_mezone(t_game *game)
{
	if (ut_mtx_scan_zone(game->map,
		(t_cell){.y = game->mnl, .x = game->mnc, .v = -game->me.id},
		&(game->mezone_lt), &(game->mezone_rb))
		== KO)
		return (KO);
	game->mezone_lt.x += -game->pnc + 1;
	game->mezone_lt.x = game->mezone_lt.x < 0 ? 0 : game->mezone_lt.x;
	game->mezone_lt.y += -game->pnl + 1;
	game->mezone_lt.y = game->mezone_lt.y < 0 ? 0 : game->mezone_lt.y;
	game->mezone_rb.x = game->mezone_rb.x + game->pnc >= game->mnc ?
						game->mnc - game->pnc - 1 : game->mezone_rb.x;
	game->mezone_rb.y = game->mezone_rb.y + game->pnl >= game->mnl ?
						game->mnl - game->pnl : game->mezone_rb.y;
	FT_LOG(FT_LOG_LDEB, FT_LOG_FMESS, "Zone: LT[%d , %d]  RB[%d, %d]\n",
		   game->mezone_lt.y, game->mezone_lt.x, game->mezone_rb.y, game->mezone_rb.x)
	return (OK);
}

int 	fi_place_distdiff_tocom(t_game *game, t_cell c1, t_cell c2)
{
	t_cell mid1;
	t_cell mid2;
	t_cell com;

	mid1 = ft_cell_mid(
		(t_cell){.x = c1.x + game->parea_lt.x, .y = c1.y + game->parea_lt.y, .v = 0},
		(t_cell){.x = c1.x + game->parea_rb.x, .y = c1.y + game->parea_rb.y, .v = 0}
	);
	mid2 = ft_cell_mid(
		(t_cell){.x = c2.x + game->parea_lt.x, .y = c2.y + game->parea_lt.y, .v = 0},
		(t_cell){.x = c2.x + game->parea_rb.x, .y = c2.y + game->parea_rb.y, .v = 0}
	);
	com = ut_mtx_center_of_mass(game->map, game->mnl, game->mnc, -game->en.id);
	return (ut_vec_normsquare(mid2, com) - ut_vec_normsquare(mid1, com));
}

int 	fi_place_distdiff(t_game *game, t_cell c1, t_cell c2)
{
	t_cell mid1;
	t_cell mid2;
	t_cell miden;

	mid1 = ft_cell_mid(
		(t_cell){.x = c1.x + game->parea_lt.x, .y = c1.y + game->parea_lt.y, .v = 0},
		(t_cell){.x = c1.x + game->parea_rb.x, .y = c1.y + game->parea_rb.y, .v = 0}
		);
	mid2 = ft_cell_mid(
		(t_cell){.x = c2.x + game->parea_lt.x, .y = c2.y + game->parea_lt.y, .v = 0},
		(t_cell){.x = c2.x + game->parea_rb.x, .y = c2.y + game->parea_rb.y, .v = 0}
		);
	miden = ft_cell_mid(game->enarea_lt, game->enarea_rb);
	return (ut_vec_normsquare(mid2, miden) - ut_vec_normsquare(mid1, miden));
}