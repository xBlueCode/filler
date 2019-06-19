/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 03:24:05 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/16 03:24:28 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "utils.h"

# define LOG_DIR "logs"

# define FI_IN_PL_HEAD "$$$ exec p"
# define FI_IN_PL_HEAD_LEN 10

# define FI_IN_PL_OFF_I 10

# define FI_IN_PL_OFF_N 15

# define FI_IN_FD 0

# define FI_CE_PL1 'O'
# define FI_CE_PL2 'X'
# define FI_CE_EMP '.'
# define FI_CE_PIE '*'

typedef struct	s_player
{
	int		id;
	char	ch;
	char	*name;
}				t_player;

typedef	struct	s_game
{
	t_player	me;
	t_player	en;
	int 		**map;
	int 		mnl;
	int 		mnc;
	int 		**piece;
	int			pnl;
	int 		pnc;
	t_cell		lastmove;
}				t_game;

int 			fi_game_run(void);
int 			fi_game_init(t_game *game);
int 			fi_game_clean(t_game *game);
int 			fi_game_play(t_game *game);

int				fi_read_player(t_game *game);
int 			fi_read_map(t_game *game);
int 			fi_read_piece(t_game *game);

int 			fi_solve(t_game *game);


int 			fi_map_update(t_game *game);
int 			fi_map_numerize(t_game *game);
int 			fi_map_surround(t_game *game);
int 			fi_map_calcdist(t_game *game);
int 			fi_map_adjacent(t_game *game, int i, int j, int c);

int 			fi_print_lastmove(t_game *game);

#endif
