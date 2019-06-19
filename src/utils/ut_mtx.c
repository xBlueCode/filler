//
// Created by Abdelfettah BESBES on 2019-06-17.
//

#include "libft.h"

int 	**ut_read_mtx(int fd, int nl, int nc, int off)
{
	char	*line;
	int		**mtx;
	int		i;
	int 	j;

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

int 	**ut_log_mtx_int(int **mtx, int nl, int nc)
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

int 	**ut_log_mtx_ch(int **mtx, int nl, int nc)
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
