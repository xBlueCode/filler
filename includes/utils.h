//
// Created by Abdelfettah BESBES on 2019-06-17.
//

#ifndef UTILS_H
#define UTILS_H

int 	**ut_read_mtx(int fd, int nl, int nc, int off);
int 	**ut_log_mtx_int(int **mtx, int nl, int nc);
int 	**ut_log_mtx_ch(int **mtx, int nl, int nc);

#endif
