/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:28:03 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/13 21:18:03 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

# define K_LEFT_ARROW 123
# define K_RIGTH_ARROW 124
# define K_UP_ARROW 126
# define K_DOWN_ARROW 125
# define K_NUM_PLUS 69
# define K_NUM_MINUS 78
# define K_NUM_0 82

# define K_NUM_7 89
# define K_NUM_4 86
# define K_NUM_8 91
# define K_NUM_6 88
# define K_NUM_2 84
# define K_NUM_9 92
# define K_NUM_3 85
# define K_NUM_1 83

# define K_ESC 53

# define K_H 4
# define K_G 5
# define K_L 37
# define WIDTH 1600
# define HEIGHT 900
# define MOVE_POWER 10
# define ROT_POWER 10

# define C_WHITE 0xFFFFFF
# define C_YELLOW 0xD8CE0F
# define PI 3.14159265358979323846
# define DEG_TO_RAD(angle) (PI * angle) / 180

typedef struct	s_vector3
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_vector3;

typedef struct	s_rotation
{
	double		cosx;
	double		sinx;
	double		cosy;
	double		siny;
	double		cosz;
	double		sinz;
}				t_rotation;

typedef struct	s_matrix
{
	t_vector3	**m;
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
	int			help;
	int			gradient;
	int			visible_lines;
	t_vector3	scale;
	t_matrix	mtrx;
	t_matrix	draw_mtrx;
	t_vector3	grads;
	t_vector3	fig_pos;
	t_vector3	fig_centre;
	t_rotation	rads;
}				t_win;

int				ft_get_map(t_win *win, char *fname);
int				ft_hex_to_dec(char *hex);
int				ft_get_color(char *data);
int				ft_2darr_len(char **arr);
void			ft_draw_line_img(t_win *win, t_vector3 p0, t_vector3 p1);
void			ft_rewrite_img(t_win *win);
void			ft_draw_net(t_win *win);
void			ft_move_img(int key, t_win *win);
void			ft_scale_img(int key, t_win *win);
void			ft_scale_z(int key, t_win *win);
void			ft_rot_img(int key, t_win *win);
void			ft_set_default_position(t_win *win);
void			ft_rewrite_img(t_win *win);
void			ft_pp_img(char *pixels, int x, int y, int color);
void			ft_count_rads(t_vector3 *grads, t_rotation *rads);
void			ft_rotate(t_vector3 *p, t_rotation *rads, t_vector3 *centre);
void			ft_put_gradient_pixel(t_vector3 p, t_vector3 start,
					t_vector3 end, t_win *win);

#endif
