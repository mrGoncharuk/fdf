#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include "mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# define WIDTH 500
# define HEIGHT 500

typedef struct  s_point
{
    int         x;
    int         y;
    int         z;
    char        *color;
}               t_point;

typedef struct	s_matrix
{
	int			row;
	int			cols;
	t_point		**matrix;
}				t_matrix;

typedef struct  s_mlx
{
    void        *win_ptr;
    void        *mlx_ptr;
    void        *img_ptr;
    void        *pixels;
    t_matrix    *m;
}               t_mlx;

void	ft_swap(int *x, int *y);
void	draw_line(t_point p0, t_point p1, void *mlx_ptr, void *win_ptr);
void	*write_img(void *mlx_ptr, void *win_ptr);
void	ft_put_pixel_to_img(char *pixels, int x, int y, int color);
void	ft_draw_line_img(char *pixels, t_point p0, t_point p1, int color);
void	draw_net(t_matrix *m, char *pixels);
int		ft_read_coords(char *fname, t_matrix *mtrx);
int		ft_init_struct(char *fname, t_matrix *mtrx);
void	x_rotate(t_matrix *m, int way);
void	y_rotate(t_matrix *m, int way);
void	z_rotate(t_matrix *m, int way);

#endif