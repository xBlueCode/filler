/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 03:25:06 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/16 03:26:02 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		main(void)
{
	ft_log_open(LOG_DIR, "filler");
	fi_game_run();
	ft_log_close();
	return (0);
}
