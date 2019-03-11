/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:27:08 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/11 17:38:07 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_win *win)
{
	printf("Key [%d] pressed\n", key);
	if (key >= K_LEFT_ARROW && key <= K_DOWN_ARROW)
		ft_move_img(key, win);
	if (key == K_NUM_MINUS || key == K_NUM_PLUS)
		ft_scale_img(key, win);
	if (key >= K_NUM_7 && key <= K_NUM_9)
		ft_rot_img(key, win);
	if (key == K_NUM_1 || key == K_NUM_3)
		ft_scale_z(key, win);
	if (key == K_NUM_0)
		ft_set_default_position(win);
	if (key == K_ESC)
		exit(0);
	ft_rewrite_img(win);	
	return (0);
}

void	ft_win_init(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "fdf");
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->bpp = 32;
	win->size_line = WIDTH;
	win->endian = 0;
	win->pix_ptr = mlx_get_data_addr(win->img_ptr, &(win->bpp), &(win->size_line), &(win->endian));
	ft_set_default_position(win);
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
	mlx_key_hook(win.win_ptr, deal_key, (void *)&win);
	mlx_loop(win.mlx_ptr);
	//system("leaks fdf");
	return (0);

}
