/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:28:03 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/25 20:53:26 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define K_LEFT_ARROW 123
# define K_RIGTH_ARROW 124
# define K_UP_ARROW 126
# define K_DOWN_ARROW 125
# define K_NUM_PLUS 69
# define K_NUM_MINUS 78
# define K_NUM_ZERO 82


# define WIDTH 1600
# define HEIGHT 900




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
}				t_win;

int		ft_get_map(t_win *win, char *fname);
void	ft_draw_line_img(char *pixels, t_vector3 p0, t_vector3 p1);
void	ft_rewrite_img(t_win *win);
void	ft_draw_net(t_matrix *m, char *pixels);
void	ft_move_img(int key, t_win *win);
void    ft_scale_img(int key, t_win *win);
void    ft_set_default_position(t_win *win);
void	ft_rewrite_img(t_win *win);

#endif