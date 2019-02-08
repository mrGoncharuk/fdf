/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:31:44 by mhonchar          #+#    #+#             */
/*   Updated: 2019/01/18 15:44:54 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(int *x, int *y)
{
	int		temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	draw_line(t_point p0, t_point p1, void *mlx_ptr, void *win_ptr)
{
	t_point dp;
	t_point p;
	int     err;
	int     steep;
	int     ystep;

	steep = abs(p1.y - p0.y) > abs(p1.x - p0.x);
	if (steep)
	{
		ft_swap(&(p0.x), &(p0.y));
		ft_swap(&(p1.x), &(p1.y));
	}
	if (p0.x > p1.x)
	{
		ft_swap(&(p0.x), &(p1.x));
		ft_swap(&(p0.y), &(p1.y));
	}
	dp.x = p1.x - p0.x;
	dp.y = abs(p1.y - p0.y);
	p.x = p0.x;
	p.y = p0.y;
	err = dp.x / 2;
	ystep = (p0.y < p1.y) ? 1 : -1;
	while (p.x <= p1.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, steep ? p.y : p.x, steep ? p.x : p.y, 0x0000FF);
		err -= dp.y;
		if (err < 0)
		{
			p.y += ystep;
			err += dp.x;
		}
		p.x++;
	}
}
