/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:25:33 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/28 15:25:34 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		fi_read_player(t_game *game)
{
	char	*line;

	if (get_next_line(FI_IN_FD, &line) < 0 || !line
		|| ft_strncmp(line, FI_IN_PL_HEAD, FI_IN_PL_HEAD_LEN))
		FT_ERR_RETMSG(KO, "ERROR: GNL !");
	game->me.id = ft_atoi(line + FI_IN_PL_OFF_I);
	if (game->me.id != 1 && game->me.id != 2)
	{
		ft_printf(C_RED"ERROR : PARSER : INVALID PLAYER ID\n"T_END);
		FT_MEMDEL(line);
		return (KO);
	}
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

int		fi_read_map(t_game *game)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0 || !line)
		return (-2);
	if (ft_strncmp(line, "Plateau ", 8))
	{
		FT_MEMDEL(line);
		return (KO);
	}
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

int		fi_read_piece(t_game *game)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (KO);
	if (ft_strncmp(line, "Piece ", 6))
	{
		ft_printf(C_RED"ERROR : PARSER : Expected Token Piece\n"T_END);
		FT_MEMDEL(line);
		return (KO);
	}
	game->pnl = ft_atoi(line + 6);
	game->pnc = ft_atoi(ft_strchr(line + 6, ' '));
	FT_MEMDEL(line);
	if (!(game->piece = ut_read_mtx(0, game->pnl, game->pnc, 0)))
		return (KO);
	return (OK);
}
