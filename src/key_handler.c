/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:31:04 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/25 20:56:34 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_img(int key, t_win *win)
{
	if (key == K_LEFT_ARROW)
		win->fig_pos.x--;
	else if (key == K_RIGTH_ARROW)
		win->fig_pos.x++;
	else if (key == K_DOWN_ARROW)
		win->fig_pos.y--;
	else if (key == K_UP_ARROW)
		win->fig_pos.y++;

}

void	ft_scale_img(int key, t_win *win)
{
	if (key == K_NUM_PLUS)
		win->scale++;
	else if (key == K_NUM_MINUS && win->scale > 0)
		win->scale--;
}

void	ft_set_default_position(t_win *win)
{
	win->endian = 0;
}
