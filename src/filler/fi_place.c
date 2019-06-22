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
	if (score < 0)
		return (KO);
	if (game->lastmove.v < 0)
		game->lastmove = (t_cell){.y = i, .x = j, .v = score};
	else if (game->lastmove.v > score && score > 0)
		game->lastmove = (t_cell){.y = i, .x = j, .v = score};
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
