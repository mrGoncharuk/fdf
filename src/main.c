/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:27:08 by mhonchar          #+#    #+#             */
/*   Updated: 2019/03/14 18:52:06 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_win *win)
{
	if (key == K_LEFT_ARROW || key == K_RIGTH_ARROW || key == K_UP_ARROW
		|| key == K_DOWN_ARROW)
		ft_move_img(key, win);
	if (key == K_NUM_MINUS || key == K_NUM_PLUS)
		ft_scale_img(key, win);
	if (key == K_NUM_7 || key == K_NUM_8 || key == K_NUM_9 || key == K_NUM_4
		|| key == K_NUM_2 || key == K_NUM_6)
		ft_rot_img(key, win);
	if (key == K_NUM_1 || key == K_NUM_3)
		ft_scale_z(key, win);
	if (key == K_NUM_0)
		ft_set_default_position(win);
	if (key == K_ESC)
		exit(0);
	if (key == K_H)
		win->help = !(win->help);
	if (key == K_G)
		win->gradient = !(win->gradient);
	if (key == K_L)
		win->visible_lines = !(win->visible_lines);
	if (key == K_I)
		(win->projection == P_ISO) ? (win->projection = P_PAR) :
			(win->projection = P_ISO);
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
	win->help = 0;
	win->gradient = 0;
	win->visible_lines = 1;
	win->pix_ptr = mlx_get_data_addr(win->img_ptr, &(win->bpp),
		&(win->size_line), &(win->endian));
	ft_set_default_position(win);
	ft_rewrite_img(win);
}

int		main(int argc, char **argv)
{
	t_win	win;
	int		err_code;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf [map_name]");
		return (0);
	}
	if ((err_code = ft_get_map(&win, argv[1])) < 0)
	{
		if (err_code == E_NOFILE)
			ft_putendl("Error. Can't find file.");
		else if (err_code == E_EMPTY_FILE)
			ft_putendl("Error. Empty file.");
		else if (err_code == E_NOMEMORY)
			ft_putendl("Error. Not enough memory.");
		else if (err_code == E_BADMAP)
			ft_putendl("Error. Bad map.");
		return (-1);
	}
	ft_win_init(&win);
	mlx_key_hook(win.win_ptr, deal_key, (void *)&win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
