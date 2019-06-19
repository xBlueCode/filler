//
// Created by Abdelfettah BESBES on 2019-06-19.
//

#include "libft.h"
#include "filler.h"

int				fi_read_player(t_game *game)
{
	char	*line;

	if (get_next_line(FI_IN_FD, &line) < 0 || !line
		|| ft_strncmp(line, FI_IN_PL_HEAD, FI_IN_PL_HEAD_LEN))
		FT_ERR_RETMSG(KO, "ERROR: GNL !");
	game->me.id = ft_atoi(line + FI_IN_PL_OFF_I);
	if (game->me.id != 1 && game->me.id != 2)
		FT_ERR_RETMSG(KO, C_RED"ERROR : PARSER : Invalid PLAYER ID"T_END);
	game->me = game->me.id == 1 ? (t_player){.id = 1, .ch = FI_CE_PL1}
								: (t_player){.id = 2, .ch = FI_CE_PL2};
	game->en = game->me.id == 1 ?
			   (t_player){.id = 2, .ch = FI_CE_PL2, .name = NULL}
								: (t_player){.id = 1, .ch = FI_CE_PL1, .name = NULL};
	game->me.name = ft_strndup(line + FI_IN_PL_OFF_N,
							   ft_strlen(line + FI_IN_PL_OFF_N) - 1);
	FT_MEMDEL(line);
	ft_printf("Player Added !\n");
	return (OK);
}

int 			fi_read_map(t_game *game)
{
	char 	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (KO);
	if (ft_strncmp(line, "Plateau ", 8))
	FT_ERR_RETMSG(KO, "Error : Parser : Expected Token : Plateau !");
	game->mnl = ft_atoi(line + 8);
	game->mnc = ft_atoi(ft_strchr(line + 8, ' '));
	FT_MEMDEL(line);
	if (get_next_line(0, &line) < 0)
		return (KO);
	FT_MEMDEL(line);
	if (!(game->map = ut_read_mtx(0, game->mnl, game->mnc, 4)))
		return (KO);
	return (OK);
}

int 			fi_read_piece(t_game *game)
{
	char 	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (KO);
	if (ft_strncmp(line, "Piece ", 6))
	FT_ERR_RETMSG(KO, "Error : Parser : Expected Token : Piece !");
	game->pnl = ft_atoi(line + 6);
	game->pnc = ft_atoi(ft_strchr(line + 6, ' '));
	FT_MEMDEL(line);
	if (!(game->map = ut_read_mtx(0, game->pnl, game->pnc, 0)))
		return (KO);
	return (OK);
}

int 			fi_print_lastmove(t_game *game)
{
	ft_dprintf(0, "%d %d\n", game->lastmove.y, game->lastmove.x);
	return (0);
}
