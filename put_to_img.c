/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:41:02 by mhonchar          #+#    #+#             */
/*   Updated: 2019/01/22 17:43:21 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_to_img(char *pixels, int x, int y, int color)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		*(int *)(pixels + (WIDTH * y + x) * 4) = color;
}

void	ft_draw_low_line(char *pixels, t_point p0, t_point p1, int color)
{
	t_point		deltap;
	t_point		p;
	int			d;
	int			yi;

	deltap.x = p1.x - p0.x;
	deltap.y = p1.y - p0.y;
	yi = 1;
	if (deltap.y < 0)
	{
		yi = -1;
		deltap.y = -deltap.y;
	}
	d = 2 * deltap.y - deltap.x;
	p.y = p0.y;
	p.x = p0.x;
	while (p.x <= p1.x)
	{
		ft_put_pixel_to_img(pixels, p.x, p.y, color);
		if (d > 0)
		{
			p.y += yi;
			d -= 2 * deltap.x;
		}
		d += 2 * deltap.y;
		p.x++;
	}
}

void	ft_draw_high_line(char *pixels, t_point p0, t_point p1, int color)
{
	t_point		deltap;
	t_point		p;
	int			d;
	int			xi;

	deltap.x = p1.x - p0.x;
	deltap.y = p1.y - p0.y;
	xi = 1;
	if (deltap.x < 0)
	{
		xi = -1;
		deltap.x = -deltap.x;
	}
	d = 2 * deltap.x - deltap.y;
	p.y = p0.y;
	p.x = p0.x;
	while (p.y <= p1.y)
	{
		ft_put_pixel_to_img(pixels, p.x, p.y, color);
		if (d > 0)
		{
			p.x = p.x + xi;
			d = d - 2 * deltap.y;
		}
		d = d + 2 * deltap.x;
		p.y++;
	}
}

void	ft_draw_line_img(char *pixels, t_point p0, t_point p1, int color)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			ft_draw_low_line(pixels, p1, p0, color);
		else
			ft_draw_low_line(pixels, p0, p1, color);
	}
	else
	{
		if (p0.y > p1.y)
			ft_draw_high_line(pixels, p1, p0, color);
		else
			ft_draw_high_line(pixels, p0, p1, color);
	}
}
