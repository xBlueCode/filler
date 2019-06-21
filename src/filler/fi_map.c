//
// Created by Abdelfettah BESBES on 2019-06-17.
//

#include "libft.h"
#include "filler.h"

int		fi_map_update(t_game *game)
{
	FT_LOG_FUNC;
	//ut_log_mtx_ch(game->map, game->mnl, game->mnc);
	if (fi_map_numerize(game) == KO)
		return (KO);
	//ut_log_mtx_int(game->map, game->mnl, game->mnc);
	fi_map_surround(game);
	//ut_log_mtx_int(game->map, game->mnl, game->mnc);
	fi_map_calcdist(game);
	ut_log_mtx_int(game->map, game->mnl, game->mnc);
	return (OK);
}

int		fi_map_numerize(t_game *game)
{
	int **map;
	int i;
	int j;

	FT_LOG_FUNC;
	map = game->map;
	i = -1;
	while (++i < game->mnl)
	{
		j = -1;
		while (++j < game->mnc)
			if (map[i][j] == (int)'.')
				map[i][j] = 0;
			else if (map[i][j] == (int)game->me.ch)
				map[i][j] = -game->me.id;
			else if (map[i][j] == (int)game->en.ch)
				map[i][j] = -game->en.id;
			else
				return (KO);
	}
	return (OK);
}

int 	fi_map_surround(t_game *game)
{
	int **map;
	int i;
	int j;

	FT_LOG_FUNC;
	map = game->map;
	i = -1;
	while (++i < game->mnl)
	{
		j = -1;
		while (++j < game->mnc)
			if (!map[i][j] && fi_map_adjacent(game, i, j, -game->en.id))
				map[i][j] = 1;
	}
	return (OK);
}

int 	fi_map_calcdist(t_game *game)
{
	int max_dist;
	int dist;
	int i;
	int j;

	FT_LOG_FUNC;
	max_dist = game->mnl > game->mnc ? game->mnl : game->mnc;
	dist = 1;
	while (dist < max_dist)
	{
		i = -1;
		while (++i < game->mnl)
		{
			j = -1;
			while (++j < game->mnc)
				if (!game->map[i][j] && fi_map_adjacent(game, i, j, dist))
					game->map[i][j] = dist + 1;
		}
		dist++;
	}
	return (OK);
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
	if (i > 0 && j > 0 && game->map[i - 1][j - 1] == c)
		return (1);
	return (0);
}