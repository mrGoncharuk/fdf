/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:28:03 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/01 01:12:51 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "mlx.h"
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define K_LEFT_ARROW 65361
# define K_RIGTH_ARROW 65363
# define K_UP_ARROW 65362
# define K_DOWN_ARROW 65364
# define K_NUM_PLUS 65451
# define K_NUM_MINUS 65453
# define K_NUM_ZERO 65438
# define K_NUM_2 65433
# define K_NUM_4 65430
# define K_NUM_8 65431
# define K_NUM_6 65432

# define WIDTH 500
# define HEIGHT 500
# define MOVE_POWER 10
# define ROT_POWER 10



typedef struct	s_vector3
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_vector3;

typedef struct	s_rotation
{
	double		x;
	double		y;
	double		z;
}				t_rotation;

typedef struct	s_matrix
{
	t_vector3	**m;
	t_rotation	radians;
	int			rows;
	int			cols;
}				t_matrix;

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*pix_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	int			scale;
	t_matrix	mtrx;
	t_matrix	draw_mtrx;
	t_vector3	grads;
	t_vector3	fig_pos;
	t_vector3	fig_centre;
}				t_win;

int		ft_get_map(t_win *win, char *fname);
void	ft_draw_line_img(char *pixels, t_vector3 p0, t_vector3 p1);
void	ft_rewrite_img(t_win *win);
void	ft_draw_net(t_matrix *m, char *pixels);
void	ft_move_img(int key, t_win *win);
void    ft_scale_img(int key, t_win *win);
void	ft_rot_img(int key, t_win *win);
void    ft_set_default_position(t_win *win);
void	ft_rewrite_img(t_win *win);
void	ft_put_pixel_to_img(char *pixels, int x, int y, int color);

#endif