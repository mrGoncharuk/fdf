/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_net.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:36:14 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/06 20:52:29 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_count_rads(t_vector3 *grads, t_rotation *rads)
{
	double	rad_x;
	double	rad_y;
	double	rad_z;

	rad_x = DEG_TO_RAD(grads->x);
	rad_y = DEG_TO_RAD(grads->y);
	rad_z = DEG_TO_RAD(grads->z);
	rads->cosx = cos(rad_x);
	rads->sinx = sin(rad_x);
	rads->cosy = cos(rad_y);
	rads->siny = sin(rad_y);
	rads->cosz = cos(rad_z);
	rads->sinz = sin(rad_z);

}

void	ft_rotate(t_vector3 *p, t_rotation *rads, t_vector3 *centre)		// TODO: change sin cos functions to numbers
{
	int prev_x;
    int prev_y;
	int	prev_z;

    prev_x = p->x;
    prev_y = p->y;
	prev_z = p->z;
    p->y = centre->y + (prev_y - centre->y) * rads->cosx + (prev_z - centre->z) * rads->sinx;
	p->z = centre->z + (prev_z - centre->z) * rads->cosx - (prev_y - centre->y) * rads->sinx;
	prev_x = p->x;
    prev_y = p->y;
	prev_z = p->z;
	p->x = centre->x + (prev_x - centre->x) * rads->cosy - (prev_z - centre->z) * rads->siny;
	p->z = centre->z + (prev_z - centre->z) * rads->cosy + (prev_x - centre->x) * rads->siny;
	prev_x = p->x;
    prev_y = p->y;
	prev_z = p->z;
	p->x = centre->x + (prev_x - centre->x) * rads->cosz + (prev_y - centre->y) * rads->sinz;
	p->y = centre->y + (prev_y - centre->y) * rads->cosz - (prev_x - centre->x) * rads->sinz;
}

void	ft_rewrite_img(t_win *win)	//scale, rotate, move
{
	int		i;
	int		j;

	ft_bzero(win->pix_ptr, WIDTH * HEIGHT * sizeof(int));
	ft_count_rads(&(win->grads), &(win->rads));
	i = -1;
	win->fig_centre.x = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].x * win->scale.x;
	win->fig_centre.y = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].y * win->scale.y;
	win->fig_centre.z = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].z * win->scale.z;
	while (++i < win->mtrx.rows)
	{
		j = -1;
		while (++j < win->mtrx.cols)
		{
			win->draw_mtrx.m[i][j].x = win->mtrx.m[i][j].x * (win->scale.x);
			win->draw_mtrx.m[i][j].y = win->mtrx.m[i][j].y * (win->scale.y);
			win->draw_mtrx.m[i][j].z = win->mtrx.m[i][j].z * (win->scale.z);
			ft_rotate(&(win->draw_mtrx.m[i][j]), &(win->rads), &(win->fig_centre));
			win->draw_mtrx.m[i][j].x += (win->fig_pos.x - (win->mtrx.cols - 1) * win->scale.x / 2);
			win->draw_mtrx.m[i][j].y += (win->fig_pos.y - (win->mtrx.rows - 1) * win->scale.y / 2);
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
