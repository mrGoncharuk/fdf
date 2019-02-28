/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_net.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:36:14 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/01 01:26:48 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


double	ft_rad(int angle)
{
	return ((M_PI * angle) / 180);
}

void	ft_rotate(t_vector3 *p, t_vector3 *grads, t_vector3 *centre)		// TODO: change sin cos functions to numbers
{
	int prev_x;
    int prev_y;
	int	prev_z;

    prev_x = p->x;
    prev_y = p->y;
	prev_z = p->z;
    p->y = centre->y + (prev_y - centre->y) * cos(ft_rad(grads->x)) + (prev_z - centre->z) * sin(ft_rad(grads->x));
	p->z = centre->z + (prev_z - centre->z) * cos(ft_rad(grads->x)) - (prev_y - centre->y) * sin(ft_rad(grads->x));
	prev_x = p->x;
    prev_y = p->y;
	prev_z = p->z;
	p->x = centre->x + (prev_x - centre->x) * cos(ft_rad(grads->y)) - (prev_z - centre->z) * sin(ft_rad(grads->y));
	p->z = centre->z + (prev_z - centre->z) * cos(ft_rad(grads->y)) + (prev_x - centre->x) * sin(ft_rad(grads->y));
}

void	ft_rewrite_img(t_win *win)	//scale, rotate, move
{
	int		i;
	int		j;

	ft_bzero(win->pix_ptr, WIDTH * HEIGHT * sizeof(int));
	i = -1;
	win->fig_centre.x = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].x * win->scale;
	win->fig_centre.y = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].y * win->scale;
	win->fig_centre.z = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].z * win->scale;
	while (++i < win->mtrx.rows)
	{
		j = -1;
		while (++j < win->mtrx.cols)
		{
			win->draw_mtrx.m[i][j].x = win->mtrx.m[i][j].x * (win->scale);
			win->draw_mtrx.m[i][j].y = win->mtrx.m[i][j].y * (win->scale);
			win->draw_mtrx.m[i][j].z = win->mtrx.m[i][j].z * (win->scale);
			ft_rotate(&(win->draw_mtrx.m[i][j]), &(win->grads), &(win->fig_centre));
			win->draw_mtrx.m[i][j].x += (win->fig_pos.x - (win->mtrx.cols - 1) * win->scale / 2);
			win->draw_mtrx.m[i][j].y += (win->fig_pos.y - (win->mtrx.rows - 1) * win->scale / 2);
			win->draw_mtrx.m[i][j].color = win->mtrx.m[i][j].color;
		}
	}
	ft_draw_net(&(win->draw_mtrx), win->pix_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}


void	ft_draw_net(t_matrix *m, char *pixels)
{
	int	 i;
	int	 j;

	i = -1;
	while (++i < m->rows - 1)
	{
		j = -1;
		while (++j < m->cols - 1)
		{
			ft_draw_line_img(pixels, m->m[i][j], m->m[i][j + 1]);
			ft_draw_line_img(pixels, m->m[i][j], m->m[i + 1][j]);
		}
		ft_draw_line_img(pixels, m->m[i][m->cols - 1], m->m[i + 1][m->cols - 1]);
	}
	i = -1;
	while (++i < m->cols - 1)
		ft_draw_line_img(pixels, m->m[m->rows - 1][i], m->m[m->rows - 1][i + 1]);
}
