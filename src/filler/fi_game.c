/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:25:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/28 15:25:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		fi_game_run(void)
{
	t_game	game;

	if (fi_game_init(&game) == KO)
		return (KO);
	if (fi_game_play(&game) == KO)
		exit(1);
	return (OK);
}

int		fi_game_init(t_game *game)
{
	if (fi_read_player(game) == KO)
		return (KO);
	game->map = NULL;
	game->piece = NULL;
	game->mnl = 0;
	game->pnl = 0;
	return (OK);
}

int		fi_game_play(t_game *game)
{
	if (!game)
		return (KO);
	while (1)
	{
		if (fi_read_map(game) == KO || fi_read_piece(game) == KO)
		{
			fi_game_clean(game);
			return (KO);
		}
		ut_log_mtx_ch(game->piece, game->pnl, game->pnc);
		if (fi_solve(game) == KO)
		{
			fi_game_clean(game);
			ft_printf("0 0\n");
			break ;
		}
		ft_printf("%d %d\n", game->lastmove.y, game->lastmove.x);
		fi_game_clean(game);
	}
	return (OK);
}

int		fi_game_clean(t_game *game)
{
	ft_arr_free((void***)&(game->map), game->mnl);
	ft_arr_free((void***)&(game->piece), game->pnl);
	return (OK);
}
