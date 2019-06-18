//
// Created by Abdelfettah BESBES on 2019-06-17.
//

#include "libft.h"

int 	**ut_read_mtx(int fd, int nl, int nc, int off)
{
	char	*line;
	int		**mtx;
	int		i;

	if (fd < 0 || nl <= 0 || nc <= 0)
		return (NULL);
	mtx = ft_memalloc(nl * sizeof(int*));
	i = -1;
	while (++i < nl && get_next_line(fd, &line) > -1)
	{
		if ((int)ft_strlen(line) != nc + off)
		{
			ft_arr_free((void***)&mtx, nc);
			return (NULL);
		}
		mtx[i] = (int*)ft_strndup(line + off, nc);
		FT_MEMDEL(line);
	}
	return (mtx);
}