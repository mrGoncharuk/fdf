/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:39:01 by mhonchar          #+#    #+#             */
/*   Updated: 2019/02/08 18:04:06 by mhonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>



void	show_some(t_matrix *pts)
{
	for (int i = 0; i < pts->row; i++)
	{
		for (int j = 0; j < pts->cols; j++)
			printf("(%d, %d, %d)\n", pts->matrix[i][j].x, pts->matrix[i][j].y, pts->matrix[i][j].z);
	}
}

void	create_img(t_mlx *mlx)
{
	int		bits_per_pixel;
	int		width;
	int		endian;

	bits_per_pixel = 32;
	width = WIDTH;
	endian = 0;
	mlx->pixels = mlx_get_data_addr(mlx->img_ptr, &bits_per_pixel, &width, &endian);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == 123)	// left_arrow
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		create_img(mlx);
		y_rotate(mlx->m, 1);
		draw_net(mlx->m, mlx->pixels);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 10, 10);
	} else if (key == 124)	// rigth_arrow
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		create_img(mlx);
		y_rotate(mlx->m, -1);
		draw_net(mlx->m, mlx->pixels);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 10, 10);
	} else if (key == 125)	// up_arrow
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		create_img(mlx);
		x_rotate(mlx->m, 1);
		draw_net(mlx->m, mlx->pixels);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 10, 10);
	} else if (key == 126)	// down_arrow
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		create_img(mlx);
		x_rotate(mlx->m, -1);
		draw_net(mlx->m, mlx->pixels);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 10, 10);
	} else if (key == 115)	
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		create_img(mlx);
		z_rotate(mlx->m, 1);
		draw_net(mlx->m, mlx->pixels);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 10, 10);
	} else if (key == 119)	
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		create_img(mlx);
		z_rotate(mlx->m, -1);
		draw_net(mlx->m, mlx->pixels);
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 10, 10);
	}
	system("leaks fdf");
	return (0);
}

int		main()
{
	t_matrix	*points;
	t_mlx		mlx;

	points = (t_matrix *)malloc(sizeof(*points));
	ft_read_coords("42.fdf", points);
	ft_init_struct("42.fdf", points);
	mlx.m = points;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "fdf");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	create_img(&mlx);
	draw_net(points, mlx.pixels);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 10, 10);
	mlx_key_hook(mlx.win_ptr, deal_key, (void*)(&mlx));
	
	mlx_loop(mlx.mlx_ptr);
	
	return (0);
}


//cc -I /usr/local/include main.c draw_line.c put_pixel_to_img.c libft/ft_memcpy.c -L /usr/local/lib -lmlx -framework openGL -framework AppKit