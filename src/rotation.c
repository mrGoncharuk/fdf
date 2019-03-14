/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:14:55 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/14 16:57:23 by mhonchar         ###   ########.fr       */
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

void	ft_calc_image_mid(t_win *win)
{
	win->fig_centre.x = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].x
		* win->scale.x;
	win->fig_centre.y = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].y
		* win->scale.y;
	win->fig_centre.z = win->mtrx.m[win->mtrx.rows / 2][win->mtrx.cols / 2].z
		* win->scale.z;
}

void	ft_rotate(t_vector3 *p, t_rotation *rads, t_vector3 *centre)
{
	int prev_x;
	int prev_y;
	int	prev_z;

	prev_y = p->y;
	prev_z = p->z;
	p->y = centre->y + (prev_y - centre->y) * rads->cosx +
			(prev_z - centre->z) * rads->sinx;
	p->z = centre->z + (prev_z - centre->z) * rads->cosx -
			(prev_y - centre->y) * rads->sinx;
	prev_x = p->x;
	prev_z = p->z;
	p->x = centre->x + (prev_x - centre->x) * rads->cosy -
			(prev_z - centre->z) * rads->siny;
	p->z = centre->z + (prev_z - centre->z) * rads->cosy +
			(prev_x - centre->x) * rads->siny;
	prev_x = p->x;
	prev_y = p->y;
	p->x = centre->x + (prev_x - centre->x) * rads->cosz +
			(prev_y - centre->y) * rads->sinz;
	p->y = centre->y + (prev_y - centre->y) * rads->cosz -
			(prev_x - centre->x) * rads->sinz;
}

void	iso(t_vector3 *p)
{
	int		previous_x;
	int		previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.523599);
	p->y = -p->z + (previous_x + previous_y) * sin(0.523599);
}
