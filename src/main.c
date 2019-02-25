/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:27:08 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/25 21:07:57 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_win *win)
{
	if (key >= K_LEFT_ARROW && key <= K_UP_ARROW)
		ft_move_img(key, win);
	if (key == K_NUM_MINUS || key == K_NUM_PLUS)
		ft_scale_img(key, win);
	if (key == K_NUM_ZERO)
		ft_set_default_position(win);
	ft_rewrite_img(win);	
	return (0);
}

void	ft_win_init(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "fukdisfuc");
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->bpp = 32;
	win->size_line = WIDTH;
	win->endian = 0;
	win->scale = 20;
	win->fig_pos.x = WIDTH / 2;		// - fig width * 2
	win->fig_pos.y = HEIGHT / 2;
	win->pix_ptr = mlx_get_data_addr(win->img_ptr, &(win->bpp), &(win->size_line), &(win->endian));

	//ft_set_default_position(win);
	ft_rewrite_img(win);
	//ft_draw_net(&(win->draw_mtrx), win->pix_ptr);
	//mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}

int		main(int argc, char **argv)
{
	t_win	win;
	
	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [map_name]");
		return (-1);
	}
	if (ft_get_map(&win, argv[1]) < 0)
	{
		ft_putendl("Error while file reading.");
		return (0);
	}
	ft_win_init(&win);
	//ft_rewrite_img(&win);
	mlx_key_hook(win.win_ptr, deal_key, (void *)&win);
	mlx_loop(win.mlx_ptr);
	//system("leaks fdf");
	return (0);
}
