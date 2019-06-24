//
// Created by Abdelfettah BESBES on 2019-06-24.
//

#include "libft.h"
#include "fi_gui.h"
#include "mlx.h"

int 	fi_gui_loop_hook(t_fimlx *fimlx);

int 	fi_gui_init(t_fimlx *fimlx)
{
	fimlx->mlx = mlx_init();
	fimlx->window = mlx_new_window(fimlx->mlx, FI_GUI_WINW, FI_GUI_WINH,
		"Filler Game !");
	fimlx->im.ptr = mlx_new_image(fimlx->mlx, FI_GUI_WINW, FI_GUI_WINH);
	mlx_loop_hook(fimlx->mlx, &fi_gui_loop_hook, fimlx);
	mlx_loop(fimlx->mlx);
	return (OK);
}

int fi_gui_putsquare(t_fimlx *fimlx, int i, int j)
{
	int color;
	int si;
	int sj;

	if (fimlx->game.map[i][j] == '.')
		color = 0xFFFFFF;
	else
		color = fimlx->game.map[i][j] == 'O' || fimlx->game.map[i][j] == 'o' ?
			0x19b5fe : 0xf5ab35;
	si = -1;
	while (++si < fimlx->sy && (sj = -1))
		while (++sj < fimlx->sx)
			fimlx->im.a[(i * fimlx->sy + si) * FI_GUI_WINW + j * fimlx->sx + sj]
				= color;
	return (OK);
}

int fi_gui_loop_hook(t_fimlx *fimlx)
{
	int i;
	int j;
	int ret;

	if ((ret = fi_read_map(&fimlx->game)) == KO)
		return (KO);
	else if (ret == -2)
		exit(1);
	fimlx->sx = FI_GUI_WINW / fimlx->game.mnc;
	fimlx->sy = FI_GUI_WINH / fimlx->game.mnl;
	fimlx->im.ptr = mlx_new_image(fimlx->mlx, FI_GUI_WINW, FI_GUI_WINH);
	fimlx->im.a = (int*)mlx_get_data_addr(fimlx->im.ptr,
		&(fimlx->im.bpp), &(fimlx->im.sl), &(fimlx->im.endian));
	i = -1;
	while (++i < fimlx->game.mnl)
	{
		j = -1;
		while (++j < fimlx->game.mnc)
			fi_gui_putsquare(fimlx, i, j);
	}
	mlx_put_image_to_window(fimlx->mlx, fimlx->window, fimlx->im.ptr, 0, 0);
	mlx_destroy_image(fimlx->mlx, fimlx->im.ptr);
	return (OK);
}

int		main(void)
{
	t_fimlx fimlx;

	fi_gui_init(&fimlx);
//	fi_gui_display(&fimlx);
	return (OK);
}