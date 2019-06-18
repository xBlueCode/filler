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
	ft_printf("Player: %s\n", game.me.name);
	if (fi_game_play(&game) == KO)
		return (KO);
	return (OK);
}

int 	fi_game_init(t_game *game)
{
	(void)game;
	if (fi_read_player(game) == KO)
		return (KO);
	return (OK);
}

int		fi_game_play(t_game *game)
{
	//t_cell	sol;

	ft_printf("play\n");
	if (!game)
		return (KO);
	while (1)
	{
		if (fi_read_map(game) == KO)
			break;
		ft_arr_print((char**)game->map, game->mnl);
		/*
		if (fi_read_piece(game) == KO)
			break;
		if (fi_solve(game) == KO)
			break;
		fi_print_lastmove(game);
		 */
		//fi_game_clean(game);
	}
	return (OK);
}
