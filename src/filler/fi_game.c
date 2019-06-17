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
	if (fi_game_play(&game) == KO)
		return (KO);
	return (OK);
}

int 	fi_game_init(t_game *game)
{
	(void)game;
	if (fi_read_player(game) == KO)
		return (KO);
	return (KO);
}

int		fi_game_play(t_game *game)
{
	t_cell	sol;

	if (!game)
		return (KO);
	while (1)
	{
		ft_printf("Playing !\n");
		sleep(2);
		/*
		if (fi_read_map(game) == KO)
			break;
		if (fi_read_piece(game) == KO)
			break;
		if (fi_solve(game) == KO)
			break;
		fi_print_lastmove(game);
		 */
	}
	return (OK);
}
