/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_net.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:36:14 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/25 21:08:56 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rewrite_img(t_win *win)	//scale, rotate, move
{
	int		i;
	int		j;

	ft_bzero(win->pix_ptr, WIDTH * HEIGHT * sizeof(int));
	i = -1;
	while (++i < win->mtrx.rows)
	{
		j = -1;
		while (++j < win->mtrx.cols)
		{
			win->draw_mtrx.m[i][j].x = win->mtrx.m[i][j].x * win->scale;
			win->draw_mtrx.m[i][j].y = win->mtrx.m[i][j].y * win->scale;
			win->draw_mtrx.m[i][j].z = win->mtrx.m[i][j].z * win->scale;
			win->draw_mtrx.m[i][j].color = win->mtrx.m[i][j].color;
			//printf("[%d, %d, %d]\n", win->draw_mtrx.m[i][j].x, win->draw_mtrx.m[i][j].y, win->draw_mtrx.m[i][j].z);
		}
		//printf("\n");
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
