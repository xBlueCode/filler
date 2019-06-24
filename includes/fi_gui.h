//
// Created by Abdelfettah BESBES on 2019-06-24.
//

#ifndef FI_GUI_H
#define FI_GUI_H

# define FI_GUI_WINW 800
# define FI_GUI_WINH 600

#include "filler.h"

typedef struct		s_fiim
{
	void		*ptr;
	int			*a;
	int			bpp;
	int			sl;
	int			endian;
}					t_fiim;

typedef struct		s_fimlx
{
	void		*mlx;
	void		*window;
	t_fiim		im;
	t_game		game;
	int 		run;
	int 		sx;
	int 		sy;
}					t_fimlx;

#endif
