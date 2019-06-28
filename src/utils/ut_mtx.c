/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_mtx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:21:26 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/28 15:21:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ut_read_mtx(int fd, int nl, int nc, int off)
{
	char	*line;
	int		**mtx;
	int		i;
	int		j;

	if (fd < 0 || nl <= 0 || nc <= 0)
		return (NULL);
	mtx = ft_memalloc((nl + 1) * sizeof(int*));
	i = -1;
	while (++i < nl && get_next_line(fd, &line) > -1)
	{
		if ((int)ft_strlen(line) != nc + off)
		{
			ft_arr_free((void***)&mtx, nc);
			return (NULL);
		}
		mtx[i] = ft_memalloc((nc + 1) * sizeof(int));
		j = -1;
		while (++j < nc)
			mtx[i][j] = line[j + off];
		mtx[i][j] = 0;
		FT_MEMDEL(line);
	}
	mtx[i] = NULL;
	return (mtx);
}

int		ut_log_mtx_int(int **mtx, int nl, int nc)
{
	int i;
	int j;

	i = -1;
	while (++i < nl)
	{
		j = -1;
		FT_LOG(FT_LOG_LINF, FT_LOG_FMESS, "%03d >>  ", i);
		while (++j < nc)
			FT_LOG(FT_LOG_LINF, FT_LOG_FMESS, "%-4d", mtx[i][j]);
		FT_LOG(FT_LOG_LINF, FT_LOG_FMESS, "%c", '\n');
	}
	return (OK);
}

int		ut_log_mtx_ch(int **mtx, int nl, int nc)
{
	int i;
	int j;

	i = -1;
	while (++i < nl)
	{
		j = -1;
		while (++j < nc)
			FT_LOG(FT_LOG_LINF, FT_LOG_FMESS, " %c ", mtx[i][j]);
		FT_LOG(FT_LOG_LINF, FT_LOG_FMESS, " %c", '\n');
	}
	return (OK);
}

int		ut_vec_normsquare(t_cell c1, t_cell c2)
{
	return (ft_pow(c2.x - c1.x, 2) + ft_pow(c2.y - c1.y, 2));
}

t_cell	ut_mtx_center_of_mass(int **mtx, int mnl, int mnc, int c)
{
	int		i;
	int		j;
	t_cell	com;

	com = (t_cell) {.x = 0, .y = 0, .v = 0};
	i = -1;
	while (++i < mnl)
	{
		j = -1;
		while (++j < mnc)
			if (mtx[i][j] == c)
			{
				com.x += j;
				com.y += i;
				com.v++;
			}
	}
	if (com.v)
	{
		com.x /= com.v;
		com.y /= com.v;
	}
	return (com);
}
