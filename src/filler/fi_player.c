//
// Created by Abdelfettah BESBES on 2019-06-16.
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
	return (OK);
}
