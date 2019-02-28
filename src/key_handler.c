/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:31:04 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/01 01:09:29 by mhonchar         ###   ########.fr       */
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
		win->scale++;
	}
	else if (key == K_NUM_MINUS && win->scale > 0)
	{
		win->scale--;
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
	
}

void	ft_set_default_position(t_win *win)
{
	win->endian = 0;
}
