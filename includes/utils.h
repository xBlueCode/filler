//
// Created by Abdelfettah BESBES on 2019-06-17.
//

#ifndef UTILS_H
#define UTILS_H

int 	**ut_read_mtx(int fd, int nl, int nc, int off);
int 	**ut_log_mtx_int(int **mtx, int nl, int nc);
int 	**ut_log_mtx_ch(int **mtx, int nl, int nc);

int 	ut_vec_normsquare(t_cell c1, t_cell c2);
t_cell	ut_mtx_center_of_mass(int **mtx, int mnl, int mnc, int c);

int		ut_mtx_scan_zone(int **mtx, t_cell meta, t_cell *lt, t_cell *rb);
int		ut_mtx_scan_zone_lty(int **mtx, t_cell meta, t_cell *lt);
int		ut_mtx_scan_zone_ltx(int **mtx, t_cell meta, t_cell *lt);
int		ut_mtx_scan_zone_rby(int **mtx, t_cell meta, t_cell *rb);
int		ut_mtx_scan_zone_rbx(int **mtx, t_cell meta, t_cell *rb);

#endif
