
#ifndef FI_GUI_H
# define FI_GUI_H

# include "filler.h"

# define FI_GUI_WINW 800
# define FI_GUI_WINH 600

# define FI_GUI_SEP 1

typedef struct	s_fiim
{
	void		*ptr;
	int			*a;
	int			bpp;
	int			sl;
	int			endian;
}				t_fiim;

typedef struct	s_fimlx
{
	void		*mlx;
	void		*window;
	t_fiim		im;
	t_game		game;
	int			run;
	int			sx;
	int			sy;
	int			so;
}				t_fimlx;

int				fi_gui_loop_hook(t_fimlx *fimlx);

#endif
