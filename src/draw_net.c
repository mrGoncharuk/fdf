/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_net.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:36:14 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/14 16:53:17 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_help(t_win *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 25, C_YELLOW,
		"Press H to toggle help menu");
	if (win->help == 1)
	{
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 40, C_YELLOW,
			"Rotate image: Num 4-6 8-2 7-9");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 55, C_YELLOW,
			"Scale image: Num +-");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 70, C_YELLOW,
			"Scale OZ axis: Num 1-3");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 85, C_YELLOW,
			"Set default position: Num 0");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 100, C_YELLOW,
			"Move image: arrows");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 115, C_YELLOW,
			"Enable/Disable gradient: G");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 130, C_YELLOW,
			"Enable/Disable line drawing: L");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 145, C_YELLOW,
			"Enable/Disable Isometric projection: I");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 160, C_YELLOW,
			"Exit: Esc");
	}
}

void	ft_point_transformation(t_win *win)
{
	int		i;
	int		j;

	i = -1;
	while (++i < win->mtrx.rows)
	{
		j = -1;
		while (++j < win->mtrx.cols)
		{
			win->draw_mtrx.m[i][j].x = win->mtrx.m[i][j].x * (win->scale.x);
			win->draw_mtrx.m[i][j].y = win->mtrx.m[i][j].y * (win->scale.y);
			win->draw_mtrx.m[i][j].z = win->mtrx.m[i][j].z * (win->scale.z);
			if (win->projection == P_ISO)
				iso(&(win->draw_mtrx.m[i][j]));
			else
				ft_rotate(&(win->draw_mtrx.m[i][j]), &(win->rads),
					&(win->fig_centre));
			win->draw_mtrx.m[i][j].x += (win->fig_pos.x -
				(win->mtrx.cols - 1) * win->scale.x / 2);
			win->draw_mtrx.m[i][j].y += (win->fig_pos.y -
				(win->mtrx.rows - 1) * win->scale.y / 2);
			win->draw_mtrx.m[i][j].color = win->mtrx.m[i][j].color;
		}
	}
}

void	ft_put_points(t_win *win)
{
	int			i;
	int			j;
	t_matrix	*m;

	m = &(win->draw_mtrx);
	i = -1;
	while (++i < m->rows - 1)
	{
		j = -1;
		while (++j < m->cols - 1)
			ft_pp_img(win->pix_ptr, m->m[i][j].x, m->m[i][j].y,
				m->m[i][j].color);
	}
}

void	ft_rewrite_img(t_win *win)
{
	ft_bzero(win->pix_ptr, WIDTH * HEIGHT * sizeof(int));
	ft_count_rads(&(win->grads), &(win->rads));
	ft_calc_image_mid(win);
	ft_point_transformation(win);
	if (win->visible_lines)
		ft_draw_net(win);
	else
		ft_put_points(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_put_help(win);
}

void	ft_draw_net(t_win *win)
{
	int			i;
	int			j;
	t_matrix	*m;

	m = &(win->draw_mtrx);
	i = -1;
	while (++i < m->rows - 1)
	{
		j = -1;
		while (++j < m->cols - 1)
		{
			ft_draw_line_img(win, m->m[i][j], m->m[i][j + 1]);
			ft_draw_line_img(win, m->m[i][j], m->m[i + 1][j]);
		}
		ft_draw_line_img(win, m->m[i][m->cols - 1],
			m->m[i + 1][m->cols - 1]);
	}
	i = -1;
	while (++i < m->cols - 1)
		ft_draw_line_img(win, m->m[m->rows - 1][i],
			m->m[m->rows - 1][i + 1]);
}
