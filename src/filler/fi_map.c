//
// Created by Abdelfettah BESBES on 2019-06-17.
//

#include "libft.h"
#include "filler.h"

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
