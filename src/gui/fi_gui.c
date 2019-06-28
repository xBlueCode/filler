/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_gui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:52:11 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/28 14:52:14 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fi_gui.h"
#include "mlx.h"

void	fi_gui_sighand(int sig)
{
	if (sig == SIGINT)
		exit(OK);
}

int		fi_gui_loop_hook(t_fimlx *fimlx)
{
	int		i;
	int		j;
	int		ret;
	t_cell	b;

	if (!fimlx->run || (ret = fi_read_map(&fimlx->game)) == KO)
		return (KO);
	else if (ret == -2 && !(fimlx->run = 0))
		return (OK);
	fimlx->sx = FI_GUI_WINW / fimlx->game.mnc;
	fimlx->sy = FI_GUI_WINH / fimlx->game.mnl;
	i = -1;
	while (++i < fimlx->game.mnl && (j = -1))
		while (++j < fimlx->game.mnc)
			fi_gui_putsquare(fimlx, i, j);
	b = (t_cell){.y = FI_GUI_WINH, .x =0,
		.v = (fimlx->sc1 * FI_GUI_WINW) / (fimlx->sc1 + fimlx->sc2)};
	fi_gui_putrect(fimlx, b, FI_GUI_C1);
	fi_gui_putrect(fimlx, (t_cell){
		.x = b.v, .v = FI_GUI_WINW - b.v, .y = b.y}, FI_GUI_C2);
	fi_gui_putrect(fimlx, (t_cell){
		.y = FI_GUI_WINH, .x = FI_GUI_WINW / 2, .v = 4}, FI_GUI_CS);
	mlx_put_image_to_window(fimlx->mlx, fimlx->window, fimlx->im.ptr, 0, 0);
	ft_arr_free((void***)&(fimlx->game.map), fimlx->game.mnl);
	return (OK);
}

int		main(void)
{
	t_fimlx fimlx;

	signal(SIGINT, fi_gui_sighand);
	fi_gui_init(&fimlx);
	return (OK);
}
