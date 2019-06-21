//
// Created by Abdelfettah BESBES on 2019-06-17.
//

#include "libft.h"
#include "filler.h"

int		fi_game_run(void)
{
	t_game	game;

	if (fi_game_init(&game) == KO)
		return (KO);
	//ft_printf("Player: %s\n", game.me.name);
	FT_LOG(FT_LOG_LINF, FT_LOG_FMESS, "Player: %s\n", game.me.name);
	if (fi_game_play(&game) == KO)
		return (KO);
	return (OK);
}

int 	fi_game_init(t_game *game)
{
	if (fi_read_player(game) == KO)
		return (KO);
	return (OK);
}

int		fi_game_play(t_game *game)
{
	//t_cell	sol;

	if (!game)
		return (KO);
	while (1)
	{
		if (fi_read_map(game) == KO)
			break;
		if (fi_read_piece(game) == KO)
			break;
		ut_log_mtx_ch(game->piece, game->pnl, game->pnc);
		//fi_map_update(game);
		if (fi_solve(game) == KO)
			break;
		fi_print_lastmove(game);
		//ft_dprintf(0, "0 0\n");
		fi_game_clean(game);
	}
	return (OK);
}

int 	fi_game_clean(t_game *game)
{
	ft_arr_free((void***)&(game->map), game->mnl);
	ft_arr_free((void***)&(game->piece), game->pnl);
	game->lastmove = (t_cell){.x = -1, .y = -1, .v = -1};
	return (OK);
}