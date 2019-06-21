//
// Created by Abdelfettah BESBES on 2019-06-20.
//

#include "libft.h"
#include "filler.h"

int		fi_zone_scan(t_game *game, t_player player)
{
	if (fi_zone_scan_ltx(game, player) == KO
		|| fi_zone_scan_lty(game, player) == KO
		|| fi_zone_scan_rbx(game, player) == KO
		|| fi_zone_scan_rby(game, player) == KO)
		return (KO);
	game->mezone_lt.x += -game->pnc + 1;
	game->mezone_lt.x = game->mezone_lt.x < 0 ? 0 : game->mezone_lt.x;
	game->mezone_lt.y += -game->pnl + 1;
	game->mezone_lt.y = game->mezone_lt.y < 0 ? 0 : game->mezone_lt.y;
	game->mezone_rb.x = game->mezone_rb.x + game->pnc >= game->mnc ?
		game->mnc - game->pnc : game->mezone_rb.x;
	game->mezone_rb.y = game->mezone_rb.y + game->pnl >= game->mnl ?
						game->mnc - game->pnl : game->mezone_rb.y;
	FT_LOG(FT_LOG_LDEB, FT_LOG_FMESS, "Zone: LT[%d , %d]  RB[%d, %d]",
		game->mezone_lt.y, game->mezone_lt.x, game->mezone_rb.y, game->mezone_rb.x)
	return (OK);
}

int		fi_zone_scan_lty(t_game *game, t_player player)
{
	int i;
	int j;

	i = -1;
	while (++i < game->mnl) {
		j = -1;
		while (++j < game->mnc)
			if (game->map[i][j] == player.ch)
			{
				game->mezone_lt.y = i;
				return (OK);
			}
	}
	return (KO);
}

int		fi_zone_scan_ltx(t_game *game, t_player player)
{
	int i;
	int j;

	j = -1;
	while (++j < game->mnc)
	{
		i = -1;
		while (++i < game->mnl)
			if (game->map[i][j] == player.ch)
			{
				game->mezone_lt.x = j;
				return (OK);
			}
	}
	return (KO);
}

int		fi_zone_scan_rby(t_game *game, t_player player) {
	int i;
	int j;

	i = game->mnl;
	while (--i > -1) {
		j = -1;
		while (++j < game->mnc)
			if (game->map[i][j] == player.ch) {
				game->mezone_rb.y = i;
				return (OK);
			}
	}
	return (KO);
}

int		fi_zone_scan_rbx(t_game *game, t_player player)
{
	int i;
	int j;

	j = game->mnc;
	while (--j > -1)
	{
		i = -1;
		while (++i < game->mnl)
			if (game->map[i][j] == player.ch)
			{
				game->mezone_rb.x = j;
				return (OK);
			}
	}
	return (KO);
}
