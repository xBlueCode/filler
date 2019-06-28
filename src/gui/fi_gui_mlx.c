/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_gui_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:52:43 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/28 14:52:45 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "filler.h"
#include "fi_gui.h"

int		fi_gui_drawback(t_fimlx *fimlx)
{
	int i;
	int len;

	i = -1;
	len = FI_GUI_WINH * FI_GUI_WINW;
	while (++i < len)
		fimlx->im.a[i] = 0xFFFFFF;
	return (OK);
}

int		fi_gui_init(t_fimlx *fimlx)
{
	fimlx->run = 1;
	fimlx->sc1 = 1;
	fimlx->sc2 = 1;
	fimlx->so = FI_GUI_SEP ? 1 : 0;
	fimlx->mlx = mlx_init();
	fimlx->window = mlx_new_window(fimlx->mlx,
		FI_GUI_WINW, FI_GUI_WINH + FI_GUI_BARH, "Filler Game !");
	fimlx->im.ptr = mlx_new_image(
		fimlx->mlx, FI_GUI_WINW, FI_GUI_WINH + FI_GUI_BARH);
	fimlx->im.a = (int*)mlx_get_data_addr(fimlx->im.ptr,
		&(fimlx->im.bpp), &(fimlx->im.sl), &(fimlx->im.endian));
	fi_gui_drawback(fimlx);
	mlx_key_hook(fimlx->window, &fi_gui_key_hook, fimlx);
	mlx_loop_hook(fimlx->mlx, &fi_gui_loop_hook, fimlx);
	mlx_loop(fimlx->mlx);
	return (OK);
}

int		fi_gui_putsquare(t_fimlx *fimlx, int i, int j)
{
	int color;
	int si;
	int sj;

	if (fimlx->game.map[i][j] == 'x' || fimlx->game.map[i][j] == 'o')
	{
		color = fimlx->game.map[i][j] == 'o' ?
			FI_GUI_C1 + 0 * fimlx->sc1++ : FI_GUI_C2 + 0 * fimlx->sc2++;
		si = -1;
		while ((++si < fimlx->sy - fimlx->so))
		{
			sj = -1;
			while (++sj < fimlx->sx - fimlx->so)
				fimlx->im.a[
					(i * fimlx->sy + si) * FI_GUI_WINW
					+ j * fimlx->sx + sj
					] = color;
		}
	}
	return (OK);
}

int		fi_gui_putrect(t_fimlx *fimlx, t_cell meta, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < FI_GUI_BARH)
	{
		j = -1;
		while (++j < meta.v)
		{
			fimlx->im.a[
				(meta.y + i) * FI_GUI_WINW + meta.x + j
			] = color;
		}
	}
	return (OK);
}

int		fi_gui_key_hook(int key, t_fimlx *fimlx)
{
	if (key != 53)
		return (OK);
	mlx_destroy_image(fimlx->mlx, fimlx->im.ptr);
	mlx_clear_window(fimlx->mlx, fimlx->window);
	mlx_destroy_window(fimlx->mlx, fimlx->window);
	exit(OK);
}
