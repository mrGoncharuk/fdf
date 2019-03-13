/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:31:04 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/13 18:28:51 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_img(int key, t_win *win)
{
	if (key == K_LEFT_ARROW)
		win->fig_pos.x -= MOVE_POWER;
	else if (key == K_RIGTH_ARROW)
		win->fig_pos.x += MOVE_POWER;
	else if (key == K_DOWN_ARROW)
		win->fig_pos.y += MOVE_POWER;
	else if (key == K_UP_ARROW)
		win->fig_pos.y -= MOVE_POWER;
}

void	ft_scale_img(int key, t_win *win)
{
	if (key == K_NUM_PLUS)
	{
		win->scale.x++;
		win->scale.y++;
		win->scale.z++;
	}
	else if (key == K_NUM_MINUS)
	{
		win->scale.x--;
		win->scale.y--;
		win->scale.z--;
	}
}

void	ft_rot_img(int key, t_win *win)
{
	if (key == K_NUM_2)
		win->grads.x += ROT_POWER;
	else if (key == K_NUM_8)
		win->grads.x -= ROT_POWER;
	else if (key == K_NUM_4)
		win->grads.y += ROT_POWER;
	else if (key == K_NUM_6)
		win->grads.y -= ROT_POWER;
	else if (key == K_NUM_7)
		win->grads.z += ROT_POWER;
	else if (key == K_NUM_9)
		win->grads.z -= ROT_POWER;
}

void	ft_set_default_position(t_win *win)
{
	win->fig_pos.x = WIDTH / 2;
	win->fig_pos.y = HEIGHT / 2;
	win->grads.x = -30;
	win->grads.y = -30;
	win->grads.z = 30;
	win->scale.x = 20;
	win->scale.y = 20;
	win->scale.z = 20;
}

void	ft_scale_z(int key, t_win *win)
{
	if (key == K_NUM_1)
		win->scale.z--;
	else if (key == K_NUM_3)
		win->scale.z++;
}
