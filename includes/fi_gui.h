
#ifndef FI_GUI_H
# define FI_GUI_H

# include "filler.h"

# define FI_GUI_WINW 800
# define FI_GUI_WINH 600
# define FI_GUI_BARH 16

# define FI_GUI_C1 0x19b5fe
# define FI_GUI_C2 0xf5ab35
# define FI_GUI_CS 0xec644b

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
	int 		sc1;
	int			sc2;
}				t_fimlx;

int				fi_gui_init(t_fimlx *fimlx);
void			fi_gui_sighand(int sig);

int				fi_gui_loop_hook(t_fimlx *fimlx);
int 			fi_gui_key_hook(int key, t_fimlx *fimlx);

int				fi_gui_drawback(t_fimlx *fimlx);
int				fi_gui_putsquare(t_fimlx *fimlx, int i, int j);
int 			fi_gui_putrect(t_fimlx *fimlx, t_cell meta, int color);

#endif
