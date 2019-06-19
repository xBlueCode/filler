//
// Created by Abdelfettah BESBES on 2019-06-17.
//

#include "libft.h"
#include "filler.h"

int		fi_map_numerize(t_game *game)
{
	int **map;
	int i;
	int j;

	map = game->map;
	i = -1;
	while (++i < game->mnl)
	{
		j = -1;
		while (++j < game->mnc)
			if (map[i][j] == '.')
				map[i][j] = 0;
			else if (map[i][j] == game->me.ch)
				map[i][j] = -game->me.ch;
			else if (map[i][j] == game->en.ch)
				map[i][j] = -game->en.ch;
			else
				return (KO);
	}
}

int 	fi_map_surround(t_game *game)
{
	int **map;
	int i;
	int j;

	map = game->map;
	i = -1;
	while (++i < game->mnl)
	{
		j = -1;
		while (++j < game->mnc)
			if (map[i][j] == 0 && fi_map_adjacent(game, i, j, -game->en.id))
				map[i][j] = 1;
	}
	return (0);
}

int		fi_map_adjacent(t_game *game, int i, int j, int c)
{
	if (i + 1 < game->mnl && game->map[i + 1][j] == c)
		return (1);
	if (j + 1 < game->mnc && game->map[i][j + 1] == c)
		return (1);
	if (i + 1 < game->mnl && j + 1 < game->mnc && game->map[i + 1][j + 1] == c)
		return (1);
	if (i > 0 && j + 1 < game->mnc && game->map[i - 1][j + 1] == c)
		return (1);
	if (i + 1 < game->mnl && j > 0 && game->map[i + 1][j - 1] == c)
		return (1);
	if (i > 0 && game->map[i - 1][j] == c)
		return (1);
	if (j > 0 && game->map[i][j - 1] == c)
		return (1);
	if (i > 0 && j > 0 && game->map[j - 1][j - 1] == c)
		return (1);
	return (0);
}