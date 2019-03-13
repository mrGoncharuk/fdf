/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:01:06 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/13 20:59:35 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		ft_get_gradiental_color(t_vector3 current, t_vector3 start,
			t_vector3 end, t_vector3 delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = ft_get_light((start.color >> 16) & 0xFF,
		(end.color >> 16) & 0xFF, percentage);
	green = ft_get_light((start.color >> 8) & 0xFF,
		(end.color >> 8) & 0xFF, percentage);
	blue = ft_get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	ft_put_gradient_pixel(t_vector3 p, t_vector3 start,
			t_vector3 end, t_win *win)
{
	t_vector3	delta;

	delta.x = abs(start.x - end.x);
	delta.y = abs(start.y - end.y);
	ft_pp_img(win->pix_ptr, p.x, p.y,
			ft_get_gradiental_color(p, start, end, delta));
}
